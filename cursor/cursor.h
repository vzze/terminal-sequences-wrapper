#pragma once

#include <iostream>

#include "../defines/defines.h"

namespace console {
    namespace cursor {
        /* Cursor up by <n> */
        void Up(defs::us_w n = 1);

        /* Cursor down by <n> */
        void Down(defs::us_w n = 1);

        /* Cursor forward (Right) by <n> */
        void Forward(defs::us_w n = 1);

        /* Cursor backward (Left) by <n> */
        void Backward(defs::us_w n = 1);

        /* Cursor down <n> lines from current position */
        void NextLine(defs::us_w n = 1);

        /* Cursor up <n> lines from current position */
        void PreviousLine(defs::us_w n = 1);

        /* Cursor moves to <n>th position horizontally in the current line */
        void HorizontalAbsolute(defs::us_w n = 1);

        /* Cursor moves to the <n>th position vertically in the current column */
        void VerticalLinePositionAbsolute(defs::us_w n = 1);

        /* *Cursor moves to <x>; <y> coordinate within the viewport, where <x> is the column of the <y> line */
        void Position(defs::us_w y = 1, defs::us_w x = 1);

        /* *Cursor moves to <x>; <y> coordinate within the viewport, where <x> is the column of the <y> line */
        void HorizontalVerticalPosition(defs::us_w y = 1, defs::us_w x = 1);

        /* Save Cursor Position in Memory* */
        void Save();

        /* Restore Cursor Position from Memory */
        void Restore();





        /* Start the cursor blinking */
        void EnableBlinking();

        /* Stop blinking the cursor */
        void DisableBlinking();

        /* Show the cursor */
        void Show();
        
        /* Hide the cursor */
        void Hide();
    }
}
