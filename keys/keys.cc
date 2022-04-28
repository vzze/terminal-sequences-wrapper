#include "keys.h"

console::defs::i_w console::keys::ProcessKeyCode(std::string & code) {
    if(code.length() == 1) {
        return (defs::i_w)(code[0]);
    }

    for(auto virtual_key : console::vkeys::virtual_keys)
        if(virtual_key == code.c_str())
            return virtual_key.val;

    return -1602;
}
