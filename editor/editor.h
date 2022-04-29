#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <filesystem>
#include <fstream>
#include <stdexcept>

#include "../defines/defines.h"

namespace editor {
    struct File {
        std::string file; 

        void ReadFile(const char * path); 
    };

    struct Buffer {
        File file;

        std::vector<std::string> lines;
    };
}
