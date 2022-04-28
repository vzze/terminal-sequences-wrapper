#include "text.h"

void console::text::mod::InsertCharacter(defs::us_w n) {
    printf(ICH, n);
}

void console::text::mod::DeleteCharacter(defs::us_w n) {
    printf(DCH, n);
} 

void console::text::mod::EraseCharacter(defs::us_w n) {
    printf(ECH, n);
}

void console::text::mod::InsertLine(defs::us_w n) {
    printf(IL, n);
}

void console::text::mod::DeleteLine(defs::us_w n) {
    printf(DL, n);
}

void console::text::mod::EraseInDisplay(defs::us_w n) {
    printf(ED, n);
}

void console::text::mod::EraseInLine(defs::us_w n) {
    printf(EL, n);
}

void console::text::fmt::SetGR(VALUE BOLD_VALUE, VALUE UNDERLINE_VALUE, VALUE NEGATIVE_VALUE, VALUE FG_COLOR, VALUE BG_COLOR) {
    printf(SGR, BOLD_VALUE, UNDERLINE_VALUE, NEGATIVE_VALUE, FG_COLOR, BG_COLOR); 
}
