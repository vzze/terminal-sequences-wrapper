#include "cursor.h"

void console::cursor::Up(defs::us_w n) {
    printf(CUU, n);
}

void console::cursor::Down(defs::us_w n) {
    printf(CUD, n);
}

void console::cursor::Forward(defs::us_w n) {
    printf(CUF, n);
}

void console::cursor::Backward(defs::us_w n) {
    printf(CUB, n);
}

void console::cursor::NextLine(defs::us_w n) {
    printf(CNL, n);
}

void console::cursor::PreviousLine(defs::us_w n) {
    printf(CPL, n);
}

void console::cursor::HorizontalAbsolute(defs::us_w n) {
    printf(CHA, n);
}

void console::cursor::VerticalLinePositionAbsolute(defs::us_w n) {
    printf(VPA, n);
}

void console::cursor::Position(defs::us_w y, defs::us_w x) {
   printf(CUP, y, x);
}

void console::cursor::HorizontalVerticalPosition(defs::us_w y, defs::us_w x) {
    printf(HVP, y, x);
}

void console::cursor::Save() {
    printf(ANSISYSSCS);
}

void console::cursor::Restore() {
    printf(ANSISYSSCR);
}

void EnableBlinking() {
    printf(ATT160E);
}

void DisableBlinking() {
    printf(ATT160D);
} 

void Show() {
    printf(DECTCEMS);
}

void Hide() {
    printf(DECTCEMH);
}
