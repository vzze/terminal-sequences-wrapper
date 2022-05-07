#include "console/console.h"

#include "editor/editor.h"

using namespace console;

editor::Buffer buff;
editor::MODE moddd = editor::MODE::NORMAL;

void KeyCallback(int code) {
    if(moddd == editor::MODE::INSERT) {
        if(code >= 32) {
            buff.cursorPos = cursor::GetCursorPosition();

            text::mod::InsertCharacter();
        }
    }

    if(code == 'i') {
        moddd = editor::MODE::INSERT;
    }

    if(code == (int)keys::SPECIAL_KEYS::LEFT_ARROWN) {
        console::cursor::Backward();
        buff.cursorPos = cursor::GetCursorPosition();
        return;
    }

    if(code == (int)keys::SPECIAL_KEYS::RIGHT_ARROWN) {
        cursor::Forward();
        buff.cursorPos = cursor::GetCursorPosition();
        return;
    }

    if(code == (int)keys::SPECIAL_KEYS::DOWN_ARROWN) {
        console::cursor::Down();
        buff.cursorPos = cursor::GetCursorPosition();

        return;
    }

    if(code == (int)keys::SPECIAL_KEYS::UP_ARROWN) {
        console::cursor::Up();
        buff.cursorPos = cursor::GetCursorPosition();

        return;
    }
    
    if(code == 'q') {
        buff.CloseAndSave();
        CallCloseEvent();
    }
}

void ResizeCallback(unsigned int columns, unsigned int rows) {

}

void MouseCallback(keys::MOUSE_EV event) {

}

int main() {
    if(!console::Init())
        return -1;

    console::SetKeyCallback(KeyCallback);
    console::SetWindowBufferResizeCallback(ResizeCallback);
    console::SetMouseCallback(MouseCallback);
    console::cursor::HorizontalVerticalPosition();

    buff.Open("./this_is_a_test_file.txt");

    buff.Draw();

    while(console::ProcessEvents()) {

    }

    return console::Exit();    
}
