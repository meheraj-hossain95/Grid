#pragma once

#include <string>
#include <vector>

#include "notes_item.hpp"

std::string            HomeNotesPath();
std::vector<NotesItem> LoadDir(const std::string& path);
std::string            ReadFile(const std::string& path);
void                   WriteFile(const std::string& path, const std::string& content);
std::string            BuildPath(const std::vector<std::string>& stack, const std::string& base);
bool                   CreateFile(const std::string& path);
bool                   CreateFolder(const std::string& path);   