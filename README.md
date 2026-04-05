# SQUAREJUMP

SQUAREJUMP is a simple endless runner game made in C using raylib.

The player controls a square and must jump over incoming obstacles. The game continues until the player hits an obstacle. The score increases when obstacles are passed, and the high score is shown on the ending screen.

## Project Files

- `CMakeLists.txt` - main CMake build file
- `src/CMakeLists.txt` - source folder CMake file
- `src/raylib_game.c` - main game flow and screen switching
- `src/screen_title.c` - title screen
- `src/screen_gameplay.c` - main gameplay
- `src/screen_ending.c` - ending screen
- `src/screen_options.c` - unused options screen
- `src/screens.h` - shared declarations


## Requirements

To build and run this game on Windows, you need:

- CMake
- Visual Studio Build Tools 2022 or Visual Studio 2022
- Desktop development with C++ workload
- raylib (handled through the provided CMake setup)

## How to Compile

Open the project folder in Developer PowerShell for VS 2022 and run:

```powershell
cmake -S . -B build -G "Visual Studio 17 2022" -A x64
cmake --build build --config Debug 

.\build\raylib-game-template\Debug\raylib-game-template.exe (or your build command)

