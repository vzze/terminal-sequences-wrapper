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

    dwMode |= ENABLE_WINDOW_INPUT | ENABLE_VIRTUAL_TERMINAL_INPUT;

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

    return val;
}

int console::Exit() {
    console::util::SetScrollingRegionDefault();
    console::text::mod::EraseInDisplay(2);
    console::util::MainScreenBuffer();
    return 0;
}

bool console::ProcessEvents() {
    static DWORD cNumRead, fdwMode, i; 

    static INPUT_RECORD irInBuf[256];

    static std::string key_code = "";
    static bool PRESSED;

    ReadConsoleInput(console::INPUT_HANDLE, irInBuf, 256, &cNumRead);

    for(i = 0; i < cNumRead; i++) 
        switch(irInBuf[i].EventType) {
            case KEY_EVENT:
                key_code += irInBuf[i].Event.KeyEvent.uChar.AsciiChar;
                PRESSED = irInBuf[i].Event.KeyEvent.bKeyDown;
            break;

            case MOUSE_EVENT:

            break;

            case WINDOW_BUFFER_SIZE_EVENT:

            break;

            case FOCUS_EVENT:

            break;

            case MENU_EVENT:
                
            break;
        }

    if(!key_code.empty()) {
        for(auto & c : key_code)
            printf("%i ", c);
        defs::i_w code = keys::ProcessKeyCode(key_code);

        _key_callback(code, PRESSED);
    }

    key_code.clear();

    return _close;
}

std::function<void(console::defs::i_w, bool)> console::_key_callback = [](console::defs::i_w code, bool pressed) -> void {};

void console::SetKeyCallback(std::function<void(defs::i_w, bool)> key_callback) {
    _key_callback = key_callback;
}

void console::SetMouseEvent() {
    
}

void console::SetWindowBufferResizeEvent() {
    
}

void console::FocusEvent() {
    
}
