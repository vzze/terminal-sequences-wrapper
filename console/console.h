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

    BOOL WINAPI _ctrlCloseHandler(DWORD ctrl_type);

    void SetKeyCallback(std::function<void(defs::i_w, bool)> key_callback);
    extern std::function<void(defs::i_w, bool)> _key_callback;

    void SetMouseEvent();

    void SetWindowBufferResizeEvent();

    void FocusEvent();
}
