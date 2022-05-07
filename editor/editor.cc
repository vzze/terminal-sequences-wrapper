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

        data = content;
        file_path = p;
    } else {
        f.close();
    }
}

void editor::File::Write(std::string lines) {
    std::ofstream o(file_path); 

    o << lines;
}

bool editor::Line::Write(char c, console::defs::i_w pos, console::defs::i_w buffLen) {
    data.insert(pos, 1, c);
    if(data.length() == buffLen) return false;
    return true;
}

void editor::Buffer::Open(const char *path) {
    file.ReadFile(path);

    size_t loc = file.data.find('\n');

    size_t off = 0;

    while(loc != std::string::npos) {
        lines.push_back({file.data.substr(off, loc - off)});
        off = loc + 1;
        loc = file.data.find('\n', off);
    }

    lines.push_back({file.data.substr(off)});
}

void editor::Buffer::Close() {

};

void editor::Buffer::CloseAndSave() {

    std::string lns = "";

    for(auto & line : lines)
        lns += line.data + '\n';

    lns.erase(lns.size() - 1);

    file.Write(lns);
}

void editor::Buffer::Draw() {
    console::text::mod::EraseInDisplay(2);

    for(auto & l : lines) {
        std::cout << l.data << '\n';
    }

    console::cursor::Position();
}
