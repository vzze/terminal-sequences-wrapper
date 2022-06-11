#include "console.h"

HANDLE console::INPUT_HANDLE = NULL;
bool console::_close = true;

BOOL console::_ctrlCloseHandler(DWORD ctrl_type) {
    switch(ctrl_type) {
        case CTRL_C_EVENT:
            return true;
        break;

        case CTRL_CLOSE_EVENT:
            return true;
        break;

        case CTRL_BREAK_EVENT:
            return true;
        break;

        case CTRL_LOGOFF_EVENT:
            return true;
        break;

        case CTRL_SHUTDOWN_EVENT:
            return true;
        break;

        default:
            return true;
    }
}

bool console::EnableVTMode() {
    console::util::SoftReset();

    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    
    if(hOut == INVALID_HANDLE_VALUE)
        return false;

    DWORD dwMode = 0;

    if(!GetConsoleMode(hOut, &dwMode))
        return false;

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;

    if(!SetConsoleMode(hOut, dwMode))
        return false;

    HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);

    if(hIn == INVALID_HANDLE_VALUE)
        return false;

    if(!GetConsoleMode(hIn, &dwMode))
        return false;

    dwMode = ENABLE_EXTENDED_FLAGS;

    if(!SetConsoleMode(hIn, dwMode))
        return false;

    dwMode |= ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT | ENABLE_VIRTUAL_TERMINAL_INPUT;

    if(!SetConsoleMode(hIn, dwMode))
        return false;

    return true;
}

int console::Init() {
    defs::i_w val = EnableVTMode();  

    if(val == 0)
        return 0; 

    console::util::AlternateScreenBuffer();
    val = SetConsoleCtrlHandler(console::_ctrlCloseHandler, TRUE);

    if(val == 0)
        return 0;

    INPUT_HANDLE = GetStdHandle(STD_INPUT_HANDLE);

    if(INPUT_HANDLE == INVALID_HANDLE_VALUE)
        return 0;

    cursor::Position();

    return val;
}

int console::Exit() {
    _close = false;
    console::util::SetScrollingRegionDefault();
    console::text::mod::EraseInDisplay(2);
    console::util::MainScreenBuffer();
    console::util::SoftReset();
    return 0;
}

console::defs::us_w console::_columns = 0;
console::defs::us_w console::_rows = 0;

bool console::ProcessEvents() {
    static DWORD cNumRead, i; 

    static INPUT_RECORD irInBuf[256];

    static std::string key_code = "";

    ReadConsoleInput(console::INPUT_HANDLE, irInBuf, 256, &cNumRead);

    for(i = 0; i < cNumRead; i++) 
        switch(irInBuf[i].EventType) {
            case KEY_EVENT:
                if(irInBuf[i].Event.KeyEvent.bKeyDown)
                    key_code += irInBuf[i].Event.KeyEvent.uChar.AsciiChar;
            break;

            case WINDOW_BUFFER_SIZE_EVENT:
                _columns = irInBuf[i].Event.WindowBufferSizeEvent.dwSize.X;
                _rows = irInBuf[i].Event.WindowBufferSizeEvent.dwSize.Y;
                _resize_callback(irInBuf[i].Event.WindowBufferSizeEvent.dwSize.X, irInBuf[i].Event.WindowBufferSizeEvent.dwSize.Y);
            break;

            case FOCUS_EVENT:
                _focus_callback(irInBuf[i].Event.FocusEvent.bSetFocus);
            break;
        }

    if(!key_code.empty()) {
        defs::i_w code = keys::ProcessKeyCode(key_code, _mouse_callback);

        if(code != (defs::i_w)keys::SPECIAL_KEYS::KEY_ERROR) {
            _key_callback(code);
        }
    }

    key_code.clear();

    return _close;
}

std::function<void(console::defs::i_w)> console::_key_callback = [](console::defs::i_w code) -> void {};

void console::SetKeyCallback(std::function<void(defs::i_w)> key_callback) {
    _key_callback = key_callback;
}

std::function<void(console::keys::MOUSE_EV)> console::_mouse_callback = [](console::keys::MOUSE_EV code) -> void {};

void console::SetMouseCallback(std::function<void(console::keys::MOUSE_EV)> mouse_callback) {
    _mouse_callback = mouse_callback; 
}

std::function<void(console::defs::us_w, console::defs::us_w)> console::_resize_callback = [](console::defs::us_w columns, console::defs::us_w rows) -> void {};

void console::SetWindowBufferResizeCallback(std::function<void(defs::us_w, defs::us_w)> resize_callback) {
    _resize_callback = resize_callback; 
}

std::function<void(bool)> console::_focus_callback = [](bool focus) -> void {};

void console::SetFocusCallback(std::function<void(bool)> focus_callback) {
    _focus_callback = focus_callback; 
}

console::defs::us_w console::GetColumns() {
    return _columns;
}

console::defs::us_w console::GetRows() {
    return _rows;
}

void console::CallCloseEvent() {
    _close = false;
}
