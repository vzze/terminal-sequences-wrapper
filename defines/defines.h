#pragma once


namespace console {
    namespace defs {

        typedef unsigned short us_w;
        typedef int i_w;

        #define ESC "\x1b"
        #define CSI "\x1b["
        #define OSC "\x1b]"
        #define ST  "\x7"

        // Simple Cursor Positioning
        #define RI ESC "M" // moves cursor up one line
        #define DECSC ESC "7" // save cursor position in memory
        #define DECSR ESC "8" // restore cursor position from memory

        // Cursor Positioning
        #define CUU CSI "%dA" // cursor up
        #define CUD CSI "%dB" // cursor down
        #define CUF CSI "%dC" // cursor forward
        #define CUB CSI "%dD" // cursor backward
        #define CNL CSI "%dE" // cursor next line
        #define CPL CSI "%dF" // cursor previous line
        #define CHA CSI "%dG" // cursor horizontal absolute
        #define VPA CSI "%dd" // vertical line position absolute
        #define CUP CSI "%d;%dH" // cursor position
        #define HVP CSI "%d;%df" // horizontal vertical position
        #define ANSISYSSCS CSI "s" // save cursor
        #define ANSISYSSCR CSI "u" // restore cursor

        // Cursor Visibility
        #define ATT160E CSI "?12h" // text cursor enable blinking
        #define ATT160D CSI "?12l" // text cursor disable blinking
        #define DECTCEMS CSI "?25h" // text cursor enable mode show
        #define DECTCEMH CSI "?25l" // text cursor enable mode hide

        // Viewport Positioning
        #define SU CSI "%dS" // scroll up
        #define SD CSI "%dT" // scroll down

        // Text Modification
        #define ICH CSI "%d@" // insert character
        #define DCH CSI "%dP" // delete character
        #define ECH CSI "%dX" // erase character
        #define IL CSI "%dL" // insert line
        #define DL CSI "%dM" // delete line

        /*
        for the following commands, the parameter %d has 3 valid values:
        0 erases from the current cursor position (inclusive) to the end of the line/display
        1 erases from the beginning of the line/display up to and including the current cursor position
        2 erases the entire line/display
        */

        #define ED CSI "%dJ" // erase in display
        #define EL CSI "%dK" // erase in line

        // Text Formatting

        // 1 %d BOLD VALUE
        // 2 %d UNDERLINE VALUE
        // 3 %d NEGATIVE / POSITIVE VALUE
        // 4 %d FOREGROUND COLOR
        // 5 %d BACKGROUND COLOR
        // %s string to be formatted
        #define SGR CSI "%d;%d;%d;%d;%dm" // set graphics rendition

        // Mode Changes
        #define DECKPAM ESC "=" // enable keypad application mode
        #define DECKPNM ESC ">" // enable keypad numeric mode
        #define DECCKME CSI "?1h" // enable cursor keys application mode
        #define DECCKMD CSI "?1l" // disable cursor keys application mode

        // Query State
        /* These queries will emit their responses into the console input 
        stream  immediately after being recognized on the output stream 
        while ENABLE_VIRTUAL_TERMINAL_PROCESSING is set. 

        The ENABLE_VIRTUAL_TERMINAL_INPUT flag does not apply to query 
        commands as it is assumed that an application making the query 
        will always want to receive the reply. */
        #define DECXCPR CSI "6n" // report cursor position
        #define DA CSI "0c" // device attributes

        // Tabs
        #define HTS ESC "H" // horizontal tab set
        #define CHT CSI "%dI" // cursor horizontal tab
        #define CBT CSI "%dZ" // cursor backwards tab
        #define TBC CSI "0g" // tab clear
        #define TBCA CSI "3g" // tab clear all columns

        // Designate Character Set
        #define DEC_MODE ESC "(0" // enables dec mode
        #define ASCII_MODE ESC "(B" // enables ascii mode

        /*
           BR_CORNER  = ┘ TR_CORNER  = ┐ TL_CORNER  = ┌

           BL_CORNER  = └ CROSS      = ┼ HORIZONTAL = ─

           TPIECE1    = ├ TPIECE2    = ┤ TPIECE3    = ┴

           TPIECE4    = ┬ VERTICAL   = │
        */
        #define DEC_BR_CORNER "j"
        #define DEC_TR_CORNER "k"
        #define DEC_TL_CORNER "l"
        #define DEC_BL_CORNER "m"
        #define DEC_CROSS "n"
        #define DEC_HORIZONTAL "q"
        #define DEC_TPIECE1 "t"
        #define DEC_TPIECE2 "u" 
        #define DEC_TPIECE3 "v" 
        #define DEC_TPIECE4 "w" 
        #define DEC_VERTICAL "x" 

        // Scrolling Margins
        /* For DECSTBM, there are two optional parameters, <t> and <b>, 
        which are used to specify the rows that represent the top and 
        bottom lines of the scroll region, inclusive. 

        If the parameters are omitted, <t> defaults to 1 and <b> 
        defaults to the current viewport height. */
        // 1 %d = <t>
        // 2 %d = <b>
        #define DECSTBM CSI "%d;%dr" // set scrolling region
        #define DECSTBM_DEFAULT CSI "r"

        // Window Title
        #define SWT0 OSC "0;%s" ST // sets window title
        #define SWT2 OSC "2;%s" ST // sets window title

        // Alternate Screen Buffer
        #define ASB CSI "?1049h"
        #define MSB CSI "?1049l" 

        // Window Width
        #define DECCOLM132 CSI "?3h" // sets number of columns to 132
        #define DECCOLM80 CSI "?3l" // sets number of columns to 80

        // Soft Reset
        /*  Cursor visibility: visible (DECTEM)
        Numeric Keypad: Numeric Mode (DECNKM)
        Cursor Keys Mode: Normal Mode (DECCKM)
        Top and Bottom Margins: Top=1, Bottom=Console height (DECSTBM)
        Character Set: US ASCII
        Graphics Rendition: Default/Off (SGR)
        Save cursor state: Home position (0,0) (DECSC) */

        #define DECSTR CSI "!p" // soft reset

        /* The following terminal sequences are emitted by the console host 
        on the input stream if the ENABLE_VIRTUAL_TERMINAL_INPUT flag is 
        set on the input buffer handle using the SetConsoleMode flag. */

        // Cursor Keys
        #define CODE_UP_ARROWN CSI "A"
        #define CODE_DOWN_ARROWN CSI "B"
        #define CODE_RIGHT_ARROWN CSI "C"
        #define CODE_LEFT_ARROWN CSI "D"
        #define CODE_HOMEN CSI "H"
        #define CODE_ENDN CSI "F"

        #define CODE_UP_ARROWA ESC "OA"
        #define CODE_DOWN_ARROWA ESC "OB"
        #define CODE_RIGHT_ARROWA ESC "OC"
        #define CODE_LEFT_ARROWA ESC "OD"
        #define CODE_HOMEA ESC "OH"
        #define CODE_ENDA ESC "OF"

        #define CODE_CTRL_UP_ARROW CSI "1;5A"
        #define CODE_CTRL_DOWN_ARROW CSI "1;5B"
        #define CODE_CTRL_RIGHT_ARROW CSI "1;5C"
        #define CODE_CTRL_LEFT_ARROW CSI "1;5D"

        // Numpad & Functions Keys
        #define CODE_BCKSPACE "\x7f"
        #define CODE_PAUSE "\x1a"
        #define CODE_INSERT CSI "2~"
        #define CODE_DELETE CSI "3~"
        #define CODE_PG_UP CSI "5~"
        #define CODE_PG_DOWN CSI "6~"

        #define CODE_F1 ESC "OP"
        #define CODE_F2 ESC "OQ"
        #define CODE_F3 ESC "OR"
        #define CODE_F4 ESC "OS"
        #define CODE_F5 CSI "15~"
        #define CODE_F6 CSI "17~"
        #define CODE_F7 CSI "18~"
        #define CODE_F8 CSI "19~"
        #define CODE_F9 CSI "20~"
        #define CODE_F10 CSI "21~"
        #define CODE_F11 CSI "23~"
        #define CODE_F12 CSI "24~"

        #define CODE_CTRL_INS CSI "2;5~"
        #define CODE_CTRL_DEL CSI "3;5~"
        #define CODE_CTRL_HOME CSI "1;5H"
        #define CODE_CTRL_END CSI "1;5F"
        #define CODE_CTRL_PGUP CSI "5;5~"
        #define CODE_CTRL_PGDOWN CSI "6;5~"

        #define CODE_CTRL_F1 CSI "1;5P"
        #define CODE_CTRL_F2 CSI "1;5Q"
        #define CODE_CTRL_F3 CSI "1;5R"
        #define CODE_CTRL_F4 CSI "1;5S"
        #define CODE_CTRL_F5 CSI "15;5~"
        #define CODE_CTRL_F6 CSI "17;5~"
        #define CODE_CTRL_F7 CSI "18;5~"
        #define CODE_CTRL_F8 CSI "19;5~"
        #define CODE_CTRL_F9 CSI "20;5~"
        #define CODE_CTRL_F10 CSI "21;5~"
        #define CODE_CTRL_F11 CSI "23;5~"
        #define CODE_CTRL_F12 CSI "24;5~"

        #define CODE_CTRL_SPACE "\x00"

        #define CODE_ALT_UP_ARROW CSI "1;3A"
        #define CODE_ALT_DOWN_ARROW CSI "1;3B"
        #define CODE_ALT_RIGHT_ARROW CSI "1;3C"
        #define CODE_ALT_LEFT_ARROW CSI "1;3D"

        #define CODE_CTRL_ALT_UP_ARROW CSI "1;7A"
        #define CODE_CTRL_ALT_DOWN_ARROW CSI "1;7B"
        #define CODE_CTRL_ALT_RIGHT_ARROW CSI "1;7C"
        #define CODE_CTRL_ALT_LEFT_ARROW CSI "1;7D"

        #define CODE_ALT_INS CSI "2;3~"
        #define CODE_ALT_DEL CSI "3;3~"
        #define CODE_ALT_HOME CSI "1;3H"
        #define CODE_ALT_END CSI "1;3F"
        #define CODE_ALT_PGUP CSI "5;3~"
        #define CODE_ALT_PGDOWN CSI "6;3~"

        #define CODE_CTRL_ALT_INS CSI "2;7~"
        #define CODE_CTRL_ALT_DEL CSI "3;7~"
        #define CODE_CTRL_ALT_HOME CSI "1;7H"
        #define CODE_CTRL_ALT_END CSI "1;7F"
        #define CODE_CTRL_ALT_PGUP CSI "5;7~"
        #define CODE_CTRL_ALT_PGDOWN CSI "6;7~"
        
        #define CODE_CTRL_ALT_F1 CSI "1;7P"
        #define CODE_CTRL_ALT_F2 CSI "1;7Q"
        #define CODE_CTRL_ALT_F3 CSI "1;7R"
        #define CODE_CTRL_ALT_F4 CSI "1;7S"
        #define CODE_CTRL_ALT_F5 CSI "15;7~"
        #define CODE_CTRL_ALT_F6 CSI "17;7~"
        #define CODE_CTRL_ALT_F7 CSI "18;7~"
        #define CODE_CTRL_ALT_F8 CSI "19;7~"
        #define CODE_CTRL_ALT_F9 CSI "20;7~"
        #define CODE_CTRL_ALT_F10 CSI "21;7~"
        #define CODE_CTRL_ALT_F11 CSI "23;7~"
        #define CODE_CTRL_ALT_F12 CSI "24;7~"
    }
}
