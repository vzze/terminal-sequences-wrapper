#pragma once

#include <string>

#include "virtual_keys.h"

namespace console {
    namespace keys {
        enum class SPECIAL_KEYS {
            // Emitted for any other keys pressed in combination with CTRL
            CTRL_TAG = 0,
            CTRL_A = 1,
            CTRL_B = 2,
            CTRL_C = 3,
            CTRL_D = 4,
            CTRL_E = 5,
            CTRL_F = 6,
            CTRL_G = 7,
            CTRL_H = 8,
            CTRL_I = 9,
            CTRL_J = 10,
            CTRL_K = 11,
            CTRL_L = 12,
            CTRL_M = 13,
            CTRL_N = 14,
            CTRL_O = 15,
            CTRL_P = 16,
            CTRL_Q = 17,
            CTRL_R = 18,
            CTRL_S = 19,
            CTRL_T = 20,
            CTRL_U = 21,
            CTRL_V = 22,
            CTRL_W = 23,
            CTRL_X = 24,
            CTRL_Y = 25,
            CTRL_Z = 26,
            CTRL_LEFT_BRAKET = 27,
            CTRL_BACKSLASH = 28,
            CTRL_RIGHT_BRACKET = 29,
            CTRL_CARET = 30,
            CTRL_UNDERSCORE = 31,
            // Special Keys Emitted by Terminal
            UP_ARROWN = -1, 
            DOWN_ARROWN = -2,
            RIGHT_ARROWN = -3,
            LEFT_ARROWN = -4,
            HOMEN = -5,
            ENDN = -6,

            UP_ARROWA = -7, 
            DOWN_ARROWA = -8,
            RIGHT_ARROWA = -9,
            LEFT_ARROWA = -10,
            HOMEA = -11,
            ENDA = -12,

            CTRL_UP_ARROW = -13,
            CTRL_DOWN_ARROW = -14,
            CTRL_RIGHT_ARROW = -15,
            CTRL_LEFT_ARROW = -16,

            BCKSPACE = -17,
            PAUSE = -18,
            INSERT = -19,
            DEL = -20,
            PG_UP = -21,
            PG_DOWN = -22,

            F1 = -23,
            F2 = -24,
            F3 = -25,
            F4 = -26,
            F5 = -27,
            F6 = -28,
            F7 = -29,
            F8 = -30,
            F9 = -31,
            F10 = -32,
            F11 = -33,
            F12 = -34,

            CTRL_SPACE = -35,

            CTRL_INS = -36,
            CTRL_DEL = -37,
            CTRL_HOME = -38,
            CTRL_END = -39,
            CTRL_PGUP = -40,
            CTRL_PGDOWN = -41,

            CTRL_F1 = -42,
            CTRL_F2 = -43,
            CTRL_F3 = -44,
            CTRL_F4 = -45,
            CTRL_F5 = -46,
            CTRL_F6 = -47,
            CTRL_F7 = -48,
            CTRL_F8 = -49,
            CTRL_F9 = -50,
            CTRL_F10 = -51,
            CTRL_F11 = -52,
            CTRL_F12 = -53,

            KEY_ERROR = -1602
        };

        defs::i_w ProcessKeyCode(std::string & code);
    }
}
