#include "ui.hpp"
#include "module/notes/notes.hpp"
#include "module/notes/notes_state.hpp"

#include <ftxui/component/event.hpp>

using namespace ftxui;

Component CreateUI(AppState* state) {
    static std::vector<std::string> menu_items = {
        "Home", "Notes", "Command", "Settings"
    };

    static std::string command_input;

    auto sidebar = Menu(&menu_items, &state->selected_menu);

    static NotesState notes_state;
    auto notes = CreateNotes(&notes_state);

    auto command = Input(&command_input, "command Line");

    auto main_container = Container::Horizontal(Components{
        sidebar,
        notes
    });

    auto main = Renderer(main_container, [=] {
        Element right;

        if (state->selected_menu == 0) {
            right = text("Home") | center;
        } else if (state->selected_menu == 1) {
            right = notes->Render();
        } else if (state->selected_menu == 2) {
            right = text("Command") | center;
        } else {
            right = text("Settings") | center;
        }

        return hbox(Elements{
            sidebar->Render() | size(WIDTH, EQUAL, 20) | border,
            right | flex
        });
    });

    auto cmd = Renderer(command, [=] {
        return hbox(Elements{
            text("/ "),
            command->Render() | flex
        }) | border;
    });

    auto root = Container::Vertical(Components{
        main,
        command
    });

    auto app = Renderer(root, [=] {
        return vbox(Elements{
            main->Render() | flex,
            cmd->Render() | size(HEIGHT, EQUAL, 3)
        });
    });

    return app;
}