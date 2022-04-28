#include "keys.h"

const console::defs::i_w console::keys::ALT = -500;

console::defs::i_w console::keys::ProcessKeyCode(std::string & code) {
    if(code.length() == 1) {
        return (defs::i_w)(code[0]);
    }

    for(auto virtual_key : console::vkeys::virtual_keys)
        if(virtual_key == code.c_str())
            return virtual_key.val;

    if(code.length() == 2 && code[0] == '\x1b') {
        return (defs::i_w)(code[1]) + ALT;
    }

    return -1602;
}
