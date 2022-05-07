#include "cursor.h"

console::defs::us_w console::cursor::_cursor_row = 1;
console::defs::us_w console::cursor::_cursor_column = 1;

void console::cursor::translateDECXCPR() {
    static std::string code = "";

    static HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);

    static DWORD cNumRead, i;

    static INPUT_RECORD mouse[128];

    util::ReportCursorPosition();

    ReadConsoleInput(hIn, mouse, 128, &cNumRead);

    for(i = 0; i < cNumRead; i++)
        if(mouse[i].EventType == KEY_EVENT && mouse[i].Event.KeyEvent.bKeyDown)
            code += mouse[i].Event.KeyEvent.uChar.AsciiChar;

    unsigned int point = code.find(';');

    _cursor_row = std::stoi(code.substr(2, point - 2));
    _cursor_column = std::stoi(code.substr(point + 1, code.size() - 2 - point));

    code.clear();
}

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

std::pair<console::defs::us_w, console::defs::us_w> console::cursor::GetCursorPosition() {
    translateDECXCPR();
    return { _cursor_column, _cursor_row };
}
