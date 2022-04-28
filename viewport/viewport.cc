#include "viewport.h"

void console::viewport::ScrollUp(defs::us_w n) {
    printf(SU, n);
}

void console::viewport::ScrollDown(defs::us_w n) {
    printf(SD, n);
}
