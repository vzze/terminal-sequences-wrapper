#include "mode.h"

void console::mode::EnableKeypadApplicationMode() {
    printf(DECKPAM);
}

void console::mode::EnableKeypadNumericMode() {
    printf(DECKPNM);
}

void console::mode::EnableCursorKeysApplicationMode() {
    printf(DECCKME);
}

void console::mode::DisableCursorKeysApplicationMode() {
    printf(DECCKMD);
}
