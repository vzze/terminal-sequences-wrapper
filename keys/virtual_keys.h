#pragma once

#include <cstring>
#include <vector>

#include "../defines/defines.h"

namespace console { 
    namespace vkeys {
        struct key {
            const char * code;

            const defs::i_w val;

            key(const char * code, defs::i_w val);

            bool operator == (const char * cmp);
        };

        extern const std::vector<key> virtual_keys;
    }
}
