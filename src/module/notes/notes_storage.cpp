#include "notes_storage.hpp"

#include <filesystem>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <algorithm>

namespace fs = std::filesystem;

std::string HomeNotesPath() {
    // I have to apply  proper path for (windows + macOS + linux)
    const char* home = std::getenv("HOME");
    std::string path = home ? std::string(home) + "/notes" : "./notes";
    fs::create_directories(path);
    return path;
}


std::string ReadFile(const std::string& path) {
    std::ifstream f(path);
    std::stringstream ss;
    ss << f.rdbuf();
    return ss.str();
}

void WriteFile(const std::string& path, const std::string& content) {
    std::ofstream f(path);
    f << content;
}

std::string BuildPath(const std::vector<std::string>& stack, const std::string& base) {
    std::string path = base;
    for (auto& p : stack) path += "/" + p;
    return path;
}

bool CreateFile(const std::string& path) {
    std::ofstream f(path);
    return f.good();
}

bool CreateFolder(const std::string& path) {
    std::error_code ec;
    return std::filesystem::create_directory(path, ec);
}