#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <filesystem>
#include <fstream>
#include <stdexcept>

#include "../defines/defines.h"
#include "../console/console.h"

namespace editor {

    enum class MODE {
        INSERT = 0,
        NORMAL = 1
    };

    struct File {
        std::string data = ""; 

        std::filesystem::path file_path;

        void ReadFile(const char * path); 
        void Write(std::string lines);
    };

    struct Line {
        std::string data;

        bool Write(char c, console::defs::i_w pos, console::defs::i_w buffLen);
    };

    struct Buffer {
        std::pair<console::defs::us_w, console::defs::us_w> cursorPos = { 1, 1 };

        File file;

        std::vector<Line> lines;

        void Open(const char * path);
        void Close();
        void CloseAndSave();
        void Draw();
    };
}
