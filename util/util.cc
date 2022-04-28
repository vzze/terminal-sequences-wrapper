#include "util.h"

void console::util::ReportCursorPosition() {
    printf(DECXCPR);
}

void console::util::DeviceAttributes() {
    printf(DA);
}

void console::util::HorizontalTabSet() {
    printf(HTS);
}

void console::util::CursorHorizontalTabSet(defs::us_w n) {
    printf(CHT, n);
}

void console::util::CursorBackwardsTab(defs::us_w n) {
    printf(CBT, n);
}

void console::util::TabClear() {
    printf(TBC);
}

void console::util::TabClearAll() {
    printf(TBCA);
}

void console::util::SetScrollingRegion(defs::us_w t, defs::us_w b) {
    printf(DECSTBM, t, b);
}

void console::util::SetScrollingRegionDefault() {
    printf(DECSTBM_DEFAULT);
}

void console::util::EnableDEC() {
    printf(DEC_MODE);
}

void console::util::EnableASCII() {
    printf(ASCII_MODE);
}

void console::util::SetWindowTitle0(const char *title) {
    printf(SWT0, title);
}

void console::util::SetWindowTitle2(const char *title) {
    printf(SWT2, title);
}

void console::util::AlternateScreenBuffer() {
    printf(ASB);
}

void console::util::MainScreenBuffer() {
    printf(MSB); 
}

void console::util::Column132() {
    printf(DECCOLM132);
}

void console::util::Column80() {
    printf(DECCOLM80);
}

void console::util::SoftReset() {
    printf(DECSTR);
}
