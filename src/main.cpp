#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <vector>
#include <string>

using namespace ftxui;

int main() {
    auto screen = ScreenInteractive::Fullscreen();

    std::string input_text;
    std::vector<std::string> output_lines = {
        "Dock is LIVE",
    };

    auto input = Input(&input_text, "type command here...");

    auto ui = Renderer(input, [&] {
        Elements lines;
        for (auto& line : output_lines) {
            lines.push_back(text(line));
        }

        return vbox({
            vbox(lines) | border | flex,
            hbox({
                text(" ❯ ") | color(Color::Green),
                input->Render(),
            }) | border,
        });
    });

    screen.Loop(ui);
    return 0;
}