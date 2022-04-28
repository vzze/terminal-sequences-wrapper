#include "virtual_keys.h"

console::vkeys::key::key(const char * code, defs::i_w value) : val(value) {
    key::code = code;
}

bool console::vkeys::key::operator == (const char *cmp) {
    return !strcmp(code, cmp);
}

const std::vector<console::vkeys::key> console::vkeys::virtual_keys = {
    console::vkeys::key(CODE_UP_ARROWN, -1), 
    console::vkeys::key(CODE_DOWN_ARROWN, -2),
    console::vkeys::key(CODE_RIGHT_ARROWN, -3),
    console::vkeys::key(CODE_LEFT_ARROWN, -4),
    console::vkeys::key(CODE_HOMEN, -5),
    console::vkeys::key(CODE_ENDN, -6),

    console::vkeys::key(CODE_UP_ARROWA, -7), 
    console::vkeys::key(CODE_DOWN_ARROWA, -8),
    console::vkeys::key(CODE_RIGHT_ARROWA, -9),
    console::vkeys::key(CODE_LEFT_ARROWA, -10),
    console::vkeys::key(CODE_HOMEA, -11),
    console::vkeys::key(CODE_ENDA, -12),

    console::vkeys::key(CODE_CTRL_UP_ARROW, -13),
    console::vkeys::key(CODE_CTRL_DOWN_ARROW, -14),
    console::vkeys::key(CODE_CTRL_RIGHT_ARROW, -15),
    console::vkeys::key(CODE_CTRL_LEFT_ARROW, -16),

    console::vkeys::key(CODE_BCKSPACE, -17),
    console::vkeys::key(CODE_PAUSE, -18),
    console::vkeys::key(CODE_INSERT, -19),
    console::vkeys::key(CODE_DELETE, -20),
    console::vkeys::key(CODE_PG_UP, -21),
    console::vkeys::key(CODE_PG_DOWN, -22),

    console::vkeys::key(CODE_F1, -23),
    console::vkeys::key(CODE_F2, -24),
    console::vkeys::key(CODE_F3, -25),
    console::vkeys::key(CODE_F4, -26),
    console::vkeys::key(CODE_F5, -27),
    console::vkeys::key(CODE_F6, -28),
    console::vkeys::key(CODE_F7, -29),
    console::vkeys::key(CODE_F8, -30),
    console::vkeys::key(CODE_F9, -31),
    console::vkeys::key(CODE_F10, -32),
    console::vkeys::key(CODE_F11, -33),
    console::vkeys::key(CODE_F12, -34),

    console::vkeys::key(CODE_CTRL_SPACE, -35),

    console::vkeys::key(CODE_CTRL_INS, -36),
    console::vkeys::key(CODE_CTRL_DEL, -37),
    console::vkeys::key(CODE_CTRL_HOME, -38),
    console::vkeys::key(CODE_CTRL_END, -39),
    console::vkeys::key(CODE_CTRL_PGUP, -40),
    console::vkeys::key(CODE_CTRL_PGDOWN, -41),

    console::vkeys::key(CODE_CTRL_F1, -42),
    console::vkeys::key(CODE_CTRL_F2, -43),
    console::vkeys::key(CODE_CTRL_F3, -44),
    console::vkeys::key(CODE_CTRL_F4, -45),
    console::vkeys::key(CODE_CTRL_F5, -46),
    console::vkeys::key(CODE_CTRL_F6, -47),
    console::vkeys::key(CODE_CTRL_F7, -48),
    console::vkeys::key(CODE_CTRL_F8, -49),
    console::vkeys::key(CODE_CTRL_F9, -50),
    console::vkeys::key(CODE_CTRL_F10, -51),
    console::vkeys::key(CODE_CTRL_F11, -52),
    console::vkeys::key(CODE_CTRL_F12, -53)
};
