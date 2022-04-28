#include "keys.h"

const console::defs::i_w console::keys::ALT = -500;

console::defs::i_w console::keys::ProcessKeyCode(std::string & code, std::function<void(MOUSE_EV)> & mouse_ev_callback) {
    if(code.length() == 1) {
        return (defs::i_w)(code[0]);
    }

    for(auto virtual_key : console::vkeys::virtual_keys)
        if(virtual_key == code.c_str())
            return virtual_key.val;

    if(code.length() == 2 && code[0] == '\x1b') {
        return (defs::i_w)(code[1]) + ALT;
    }

    static std::function<MOUSE_EV(std::string & code)> coord = [](std::string & code) -> MOUSE_EV {
        defs::us_w first = code.find(';');
        defs::us_w second = code.find_last_of(';');

        std::string f = code.substr(first + 1, second - first - 1);

        std::string s = code.substr(second + 1, code.size() - second - 2);

        MOUSE_EV event;

        event.ROW = std::stoi(s);
        event.COLUMN = std::stoi(f);

        return event;
    };

    if(code.find(CODE_MOUSE_COORD) == 0) {
        mouse_ev_callback(coord(code));

        return -1602;
    }

    if(code.find(CODE_LEFT_CLICK) == 0) {
        auto ev = coord(code);
        ev.LEFT_CLICK = (code[code.size() - 1] == 'M');
        mouse_ev_callback(ev);

        return -1602;
    }

    if(code.find(CODE_RIGHT_CLICK) == 0) {
        auto ev = coord(code);
        ev.RIGHT_CLICK = (code[code.size() - 1 == 'M']);
        mouse_ev_callback(ev);

        return -1602;
    }

    if(code.find(CODE_SCROLL_UP) == 0) {
        auto ev = coord(code);
        ev.SCROLL_UP = true;
        mouse_ev_callback(ev);

        return -1602;
    }

    if(code.find(CODE_SCROLL_DOWN) == 0) {
        auto ev = coord(code);
        ev.SCROLL_DOWN = true;
        mouse_ev_callback(ev);

        return -1602;
    }

    return -1602;
}
