#include <emscripten/emscripten.h>
#include <emscripten/em_asm.h>
#include <string.h>

using namespace std;

extern "C" {

int i = 0;

void rotate()
{
    EM_ASM({
        document.getElementById("text").style.transform = "rotateX(" + $0 + "deg) rotateY(" + $1 + "deg) rotateZ(" + $2 + "deg)";
    },
           i, (float)i / 2, (float)i / 4);
    i++;
    if (i == 360 * 4)
        i = 0;
}

int main()
{
    emscripten_set_main_loop(rotate, 120, 1);
    return 0;
}
}
