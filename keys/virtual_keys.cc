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
    console::vkeys::key(CODE_CTRL_F12, -53),

    console::vkeys::key(CODE_ALT_UP_ARROW, -54),
    console::vkeys::key(CODE_ALT_DOWN_ARROW, -55),
    console::vkeys::key(CODE_ALT_RIGHT_ARROW, -56),
    console::vkeys::key(CODE_ALT_LEFT_ARROW, -57),

    console::vkeys::key(CODE_CTRL_ALT_UP_ARROW, -58),
    console::vkeys::key(CODE_CTRL_ALT_DOWN_ARROW, -59),
    console::vkeys::key(CODE_CTRL_ALT_RIGHT_ARROW, -60),
    console::vkeys::key(CODE_CTRL_ALT_LEFT_ARROW, -61),

    console::vkeys::key(CODE_ALT_INS, -62),
    console::vkeys::key(CODE_ALT_DEL, -63),
    console::vkeys::key(CODE_ALT_HOME, -64),
    console::vkeys::key(CODE_ALT_END, -65),
    console::vkeys::key(CODE_ALT_PGUP, -66),
    console::vkeys::key(CODE_ALT_PGDOWN, -67),

    console::vkeys::key(CODE_CTRL_ALT_INS, -68),
    console::vkeys::key(CODE_CTRL_ALT_DEL, -69),
    console::vkeys::key(CODE_CTRL_ALT_HOME, -70),
    console::vkeys::key(CODE_CTRL_ALT_END, -71),
    console::vkeys::key(CODE_CTRL_ALT_PGUP, -72),
    console::vkeys::key(CODE_CTRL_ALT_PGDOWN, -73),
    
    console::vkeys::key(CODE_CTRL_ALT_F1, -74),
    console::vkeys::key(CODE_CTRL_ALT_F2, -75),
    console::vkeys::key(CODE_CTRL_ALT_F3, -76),
    console::vkeys::key(CODE_CTRL_ALT_F4, -77),
    console::vkeys::key(CODE_CTRL_ALT_F5, -78),
    console::vkeys::key(CODE_CTRL_ALT_F6, -79),
    console::vkeys::key(CODE_CTRL_ALT_F7, -80),
    console::vkeys::key(CODE_CTRL_ALT_F8, -81),
    console::vkeys::key(CODE_CTRL_ALT_F9, -82),
    console::vkeys::key(CODE_CTRL_ALT_F10, -83),
    console::vkeys::key(CODE_CTRL_ALT_F11, -84),
    console::vkeys::key(CODE_CTRL_ALT_F12, -85),

    console::vkeys::key(CODE_SHIFT_UP_ARROW, -86),
    console::vkeys::key(CODE_SHIFT_DOWN_ARROW, -87),
    console::vkeys::key(CODE_SHIFT_RIGHT_ARROW, -88),
    console::vkeys::key(CODE_SHIFT_LEFT_ARROW, -89),

    console::vkeys::key(CODE_SHIFT_DEL, -90),
    console::vkeys::key(CODE_SHIFT_HOME, -91),
    console::vkeys::key(CODE_SHIFT_END, -92),
    console::vkeys::key(CODE_SHIFT_PGUP, -93),
    console::vkeys::key(CODE_SHIFT_PGDOWN, -94),
    
    console::vkeys::key(CODE_SHIFT_F1, -95),
    console::vkeys::key(CODE_SHIFT_F2, -96),
    console::vkeys::key(CODE_SHIFT_F3, -97),
    console::vkeys::key(CODE_SHIFT_F4, -98),
    console::vkeys::key(CODE_SHIFT_F5, -99),
    console::vkeys::key(CODE_SHIFT_F6, -100),
    console::vkeys::key(CODE_SHIFT_F7, -101),
    console::vkeys::key(CODE_SHIFT_F8, -102),
    console::vkeys::key(CODE_SHIFT_F9, -103),
    console::vkeys::key(CODE_SHIFT_F10, -104),
    console::vkeys::key(CODE_SHIFT_F11, -105),
    console::vkeys::key(CODE_SHIFT_F12, -106)
};
