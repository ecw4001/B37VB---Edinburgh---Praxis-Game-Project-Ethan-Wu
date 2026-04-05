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


## How to Compile

Open the project folder in Developer PowerShell for VS 2022 and run:

```powershell
cmake -S . -B build -G "Visual Studio 17 2022" -A x64
cmake --build build --config Debug
```

## How to Run

From the project folder, run:

```powershell
.\build\raylib-game-template\Debug\raylib-game-template.exe (or your build command from your folder)
```

