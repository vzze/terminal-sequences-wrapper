#pragma once

#include <Windows.h>
#include <string>
#include <functional>

#include "../text/text.h"
#include "../cursor/cursor.h"
#include "../util/util.h"
#include "../viewport/viewport.h"
#include "../mode/mode.h"
#include "../keys/keys.h"

namespace console {
    extern HANDLE INPUT_HANDLE;

    bool EnableVTMode();

    int Init();

    int Exit();

    bool ProcessEvents();
    extern bool _close;

    extern defs::us_w _rows;
    extern defs::us_w _columns;
    
    void CallCloseEvent();

    BOOL WINAPI _ctrlCloseHandler(DWORD ctrl_type);

    defs::us_w GetColumns();
    defs::us_w GetRows();

    void SetKeyCallback(std::function<void(defs::i_w)> key_callback);
    extern std::function<void(defs::i_w)> _key_callback;

    void SetMouseCallback(std::function<void(keys::MOUSE_EV)> mouse_callback);
    extern std::function<void(keys::MOUSE_EV)> _mouse_callback;

    void SetWindowBufferResizeCallback(std::function<void(defs::us_w, defs::us_w)> resize_callback);
    extern std::function<void(defs::us_w, defs::us_w)> _resize_callback;

    void SetFocusCallback(std::function<void(bool)> focus_callback);
    extern std::function<void(bool)> _focus_callback;
}
