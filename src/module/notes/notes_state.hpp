#pragma once

#include <string>
#include <vector>

#include "notes_item.hpp"

enum class NotesMode { Browse, Edit };
enum class NotesInput { None, NewFile, NewFolder };

struct NotesState {
    NotesMode mode =        NotesMode::Browse;
    NotesInput input_mode = NotesInput::None;

    std::string base_path;
    std::string current_path;
    std::vector<std::string> path_stack;

    std::vector<NotesItem> items;
    std::vector<std::string> display_names;
    
    int selected = 0;
    
    std::string current_file;
    std::string content;

    std::string new_name;
};