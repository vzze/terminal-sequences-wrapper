#pragma once

#include <iostream>

#include "../defines/defines.h"

namespace console {
    namespace mode {
        /* Keypad keys will emit their Application Mode sequences. */
        void EnableKeypadApplicationMode();

        /* Keypad keys will emit their Numeric Mode sequences. */
        void EnableKeypadNumericMode();

        /* Keypad keys will emit their Application Mode sequences. */
        void EnableCursorKeysApplicationMode();

        /* Keypad keys will emit their Numeric Mode sequences. */
        void DisableCursorKeysApplicationMode();
    }
}
