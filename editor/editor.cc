#include "editor.h"

void editor::File::ReadFile(const char *path) {
    std::filesystem::path p(path);

    std::ifstream f(p, std::ios::binary);

    if(f) {
        std::string content;

        f.seekg(0, std::ios::end);
        content.resize(f.tellg());
        f.seekg(0, std::ios::beg);

        f.read(&content[0], content.size());

        f.close();

        file = content;
    } else {
        f.close();

        throw std::invalid_argument("Invalid Path");
    }
}
