#pragma once

#include <iostream>

#include "../defines/defines.h"
namespace console {
    namespace text {
        enum class VALUE {
            DEFAULT        = 0,
            BOLD_BRIGHT    = 1,
            NO_BOLD_BRIGHT = 22,
            UNDERLINE      = 4,
            NO_UNDERLINE   = 24,
            NEGATIVE       = 7,
            POSITIVE       = 27,
            FG_BLACK       = 30,
            FG_RED         = 31,
            FG_GREEN       = 32,
            FG_YELLOW      = 33,
            FG_BLUE        = 34,
            FG_MAGENTA     = 35,
            FG_CYAN        = 36,
            FG_WHITE       = 37,
            FG_EXTENDED    = 38,
            FG_DEFAULT     = 39,
            BG_BLACK       = 40,
            BG_RED         = 41,
            BG_GREEN       = 42,
            BG_YELLOW      = 43,
            BG_BLUE        = 44,
            BG_MAGENTA     = 45,
            BG_CYAN        = 46,
            BG_WHITE       = 47,
            BG_EXTENDED    = 48,
            BG_DEFAULT     = 49,
            BFG_BLACK      = 90,
            BFG_RED        = 91,
            BFG_GREEN      = 92,
            BFG_YELLOW     = 93,
            BFG_BLUE       = 94,
            BFG_MAGENTA    = 95,
            BFG_CYAN       = 96,
            BFG_WHITE      = 97,
            BBG_BLACK      = 100,
            BBG_RED        = 101,
            BBG_GREEN      = 102,
            BBG_YELLOW     = 103,
            BBG_BLUE       = 104,
            BBG_MAGENTA    = 105,
            BBG_CYAN       = 106,
            BBG_WHITE      = 107
        };
        namespace mod {
            /* Insert <n> spaces at the current cursor position, shifting all existing text to the right. Text exiting the screen to the right is removed. */
            void InsertCharacter(defs::us_w n = 1);

            /* Delete <n> characters at the current cursor position, shifting in space characters from the right edge of the screen. */
            void DeleteCharacter(defs::us_w n = 1); 

            /* Erase <n> characters from the current cursor position by overwriting them with a space character. */
            void EraseCharacter(defs::us_w n = 1);

            /* Inserts <n> lines into the buffer at the cursor position. The line the cursor is on, and lines below it, will be shifted downwards. */
            void InsertLine(defs::us_w n = 1);

            /* Deletes <n> lines from the buffer, starting with the row the cursor is on. */
            void DeleteLine(defs::us_w n = 1);





            /* 0 erases from the current cursor position (inclusive) to the end of the line/display */
            /* 1 erases from the beginning of the line/display up to and including the current cursor position */
            /* 2 erases the entire line/display */
            /* Replace all text in the current viewport/screen specified by <n> with space characters */
            void EraseInDisplay(defs::us_w n = 0);

            /* 0 erases from the current cursor position (inclusive) to the end of the line/display */
            /* 1 erases from the beginning of the line/display up to and including the current cursor position */
            /* 2 erases the entire line/display */
            /* Replace all text on the line with the cursor specified by <n> with space characters */
            void EraseInLine(defs::us_w n = 0);
        }

        namespace fmt {
            void SetGR(VALUE BOLD_VALUE = VALUE::NO_BOLD_BRIGHT, 
                       VALUE UNDERLINE_VALUE = VALUE::NO_UNDERLINE, 
                       VALUE NEGATIVE_VALUE = VALUE::POSITIVE, 
                       VALUE FG_COLOR = VALUE::FG_DEFAULT, 
                       VALUE BG_COLOR = VALUE::BG_DEFAULT
                 );
        }
    }
}
