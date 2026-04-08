cmake_minimum_required(VERSION 3.16)
project(grid VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
  GIT_TAG v6.1.9
)
FetchContent_MakeAvailable(ftxui)

add_library(notes
    src/module/notes/notes.cpp
)
target_include_directories(notes PUBLIC src)
target_link_libraries(notes
    PUBLIC
    ftxui::component
    ftxui::dom
    ftxui::screen
)

add_library(ui
    src/ui/ui.cpp
)
target_include_directories(ui PUBLIC src)
target_link_libraries(ui
    PUBLIC
    notes
)

add_library(app
    src/app/app.cpp
)
target_include_directories(app PUBLIC src)
target_link_libraries(app
    PUBLIC
    ui
)

add_executable(grid
    src/main.cpp
)
target_link_libraries(grid PRIVATE app)

install(TARGETS grid DESTINATION bin)