#pragma once

#include <iostream>

#include "../defines/defines.h"

namespace console {
    namespace viewport {
        /* Scroll text up by <n>. Also known as pan down, new lines fill in from the bottom of the screen */
        void ScrollUp(defs::us_w n = 1);

        /* Scroll down by <n>. Also known as pan up, new lines fill in from the top of the screen */
        void ScrollDown(defs::us_w n = 1);
    }
}
