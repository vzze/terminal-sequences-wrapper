#pragma once

#include <iostream>

#include "../defines/defines.h"

namespace console {
    namespace util {
        /* Emit the cursor position as: ESC [ <r> ; <c> R Where <r> = cursor row and <c> = cursor column */
        void ReportCursorPosition();

        /* Report the terminal identity. Will emit “\x1b[?1;0c”, indicating "VT101 with No Options". */
        void DeviceAttributes();





        /* Sets a tab stop in the current column the cursor is in. */
        void HorizontalTabSet();

        /* Advance the cursor to the next column (in the same row) 
        with a tab stop. If there are no more tab stops, move to the 
        last column in the row. If the cursor is in the last column, 
        move to the first column of the next row. */
        void CursorHorizontalTabSet(defs::us_w n = 1);

        /* Move the cursor to the previous column (in the same row) 
        with a tab stop. If there are no more tab stops, moves the 
        cursor to the first column. If the cursor is in the first 
        column, doesn’t move the cursor. */
        void CursorBackwardsTab(defs::us_w n = 1);

        /* Clears the tab stop in the current column, if there is one. Otherwise does nothing. */
        void TabClear();

        /* Clears all currently set tab stops. */
        void TabClearAll();





        /* For DECSTBM, there are two optional parameters, <t> and <b>, 
        which are used to specify the rows that represent the top and 
        bottom lines of the scroll region, inclusive. 

        If the parameters are omitted, <t> defaults to 1 and <b> 
        defaults to the current viewport height. */
        void SetScrollingRegion(defs::us_w t, defs::us_w b);
        
        void SetScrollingRegionDefault();





        /* Enables DEC Line Drawing Mode */
        void EnableDEC();

        /* Enables ASCII Mode (Default) */
        void EnableASCII();

        /* Sets the console window’s title. Calls: ESC ] 0 ; <string> <ST> */
        void SetWindowTitle0(const char * title);

        /* Sets the console window’s title. Calls: ESC ] 2 ; <string> <ST> */
        void SetWindowTitle2(const char * title);





        /* Switches to a new alternate screen buffer. */
        void AlternateScreenBuffer();

        /* Switches to the main buffer. */
        void MainScreenBuffer();





        /* Sets the console width to 132 columns wide. */
        void Column132();

        /* Sets the console width to 80 columns wide. */
        void Column80();




        /* Following properties are reset to the following default values:
        Cursor visibility: visible (DECTEM)
        Numeric Keypad: Numeric Mode (DECNKM)
        Cursor Keys Mode: Normal Mode (DECCKM)
        Top and Bottom Margins: Top=1, Bottom=Console height (DECSTBM)
        Character Set: US ASCII
        Graphics Rendition: Default/Off (SGR)
        Save cursor state: Home position (0,0) (DECSC) */
        void SoftReset();
    }
}
