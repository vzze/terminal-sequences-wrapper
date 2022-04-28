#include "console/console.h"

using namespace console;

void PrintVerticalBorder() {
    util::EnableDEC();
    text::fmt::SetGR(text::VALUE::NO_BOLD_BRIGHT, text::VALUE::NO_UNDERLINE, text::VALUE::POSITIVE, text::VALUE::BFG_YELLOW, text::VALUE::BBG_BLUE);
    printf(DEC_VERTICAL);
    text::fmt::SetGR();
    util::EnableASCII();
}

void PrintHorizontalBorder(COORD const Size, bool fIsTop)
{
    util::EnableDEC();
    text::fmt::SetGR(text::VALUE::NO_BOLD_BRIGHT, text::VALUE::NO_UNDERLINE, text::VALUE::POSITIVE, text::VALUE::BFG_YELLOW, text::VALUE::BBG_BLUE);
    printf(fIsTop ? DEC_TL_CORNER : DEC_BL_CORNER); // print left corner 

    for (int i = 1; i < Size.X - 1; i++)
        printf(DEC_HORIZONTAL); // in line drawing mode, \x71 -> \u2500 "HORIZONTAL SCAN LINE-5"

    printf(fIsTop ? DEC_TR_CORNER : DEC_BR_CORNER); // print right corner
    text::fmt::SetGR();
    util::EnableASCII();
}

void PrintStatusLine(const char* const pszMessage, COORD const Size)
{
    cursor::Position(Size.Y, 1);
    text::mod::EraseInLine();
    printf(pszMessage); // NOLINT
}

void KeyCallback(int code) {
    printf("%i\n", code);
}

int main() {
    if(!console::Init())
        return -1;

    console::SetKeyCallback(KeyCallback);

    while(console::ProcessEvents()) {

    }

    return console::Exit();
    /*
    if(!EnableVTMode()) {
        printf("Unable to enter VT processing mode. Quitting.\n");
        return -1;
    }

    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    
    if(hOut == INVALID_HANDLE_VALUE) {
        printf("Couldn't get the console handle. Quitting.\n");
        return -1;
    }

    CONSOLE_SCREEN_BUFFER_INFO ScreenBufferInfo;
    GetConsoleScreenBufferInfo(hOut, &ScreenBufferInfo);
    COORD Size;
    Size.X = ScreenBufferInfo.srWindow.Right - ScreenBufferInfo.srWindow.Left + 1;
    Size.Y = ScreenBufferInfo.srWindow.Bottom - ScreenBufferInfo.srWindow.Top + 1;

    util::AlternateScreenBuffer();

    util::SetWindowTitle0("THIS IS A TEST");

    cursor::Position();
    text::mod::EraseInDisplay(2);

    int iNumTabStops = 4;

    util::TabClearAll();
    cursor::Position(1, 20);
    util::HorizontalTabSet();

    cursor::Position(1, 40);
    util::HorizontalTabSet();

    util::SetScrollingRegion(3, Size.Y - 2);

    int iNumLines = Size.Y - 4;

    cursor::Position(1, 1);
    text::fmt::SetGR(TEXT::NO_BOLD_BRIGHT, TEXT::NO_UNDERLINE, TEXT::POSITIVE, TEXT::FG_BLACK, TEXT::BBG_GREEN);
    printf("Windows 10 Anniversary Update - VT Example");
    text::fmt::SetGR();

    // Print a top border - Yellow
    cursor::Position(2, 1);
    PrintHorizontalBorder(Size, true);

    // // Print a bottom border
    cursor::Position(Size.Y - 1, 1);
    PrintHorizontalBorder(Size, false);

    wchar_t wch;

    // draw columns
    cursor::Position(3, 1);
    int line = 0;
    for (line = 0; line < iNumLines * iNumTabStops; line++)
    {
        PrintVerticalBorder();
        if (line + 1 != iNumLines * iNumTabStops) // don't advance to next line if this is the last line
            printf("\t"); // advance to next tab stop

    }

    PrintStatusLine("Press any key to see text printed between tab stops.", Size);
    wch = _getwch();

    // Fill columns with output
    cursor::Position(3, 1);
    for (line = 0; line < iNumLines; line++)
    {
        int tab = 0;
        for (tab = 0; tab < iNumTabStops - 1; tab++)
        {
            PrintVerticalBorder();
            printf("line=%d", line);
            printf("\t"); // advance to next tab stop
        }
        PrintVerticalBorder();// print border at right side
        if (line + 1 != iNumLines)
            printf("\t"); // advance to next tab stop, (on the next line)
    }

    PrintStatusLine("Press any key to demonstrate scroll margins", Size);
    wch = _getwch();

    cursor::Position(3, 1);
    for (line = 0; line < iNumLines * 2; line++)
    {
        text::mod::EraseInLine();
        int tab = 0;
        for (tab = 0; tab < iNumTabStops - 1; tab++)
        {
            PrintVerticalBorder();
            printf("line=%d", line);
            printf("\t"); // advance to next tab stop
        }
        PrintVerticalBorder(); // print border at right side
        if (line + 1 != iNumLines * 2)
        {
            printf("\n"); //Advance to next line. If we're at the bottom of the margins, the text will scroll.
            printf("\r"); //return to first col in buffer
        }
    }

    PrintStatusLine("Press any key to exit", Size);
    wch = _getwch();
    
    // Exit the alternate buffer
    util::SetScrollingRegionDefault();
    text::mod::EraseInDisplay(2);
    util::MainScreenBuffer();

    return 0; */
}
