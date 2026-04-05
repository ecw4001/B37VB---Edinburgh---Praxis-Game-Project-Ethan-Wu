# SQUAREJUMP

SQUAREJUMP is a simple endless runner game made in C using raylib.

The player controls a square and must jump over incoming obstacles. The game continues until the player hits an obstacle. The score increases when obstacles are passed, and the high score is shown on the ending screen.

## Controls

- **ENTER/SPACE** - start the game
- **SPACE/UP ARROW** - jump
- **ENTER/SPACE** on the ending screen - play again

## Rules of the Game

- Press **ENTER** to start from the title screen.
- The square must jump over obstacles coming from the right side of the screen.
- Each obstacle passed increases the score.
- If the square collides with an obstacle, the game ends.
- The ending screen displays the score and high score.
- The player can then press a key to play again.

## Project Files

- `CMakeLists.txt` - main CMake build file
- `src/CMakeLists.txt` - source folder CMake file
- `src/raylib_game.c` - main game flow and screen switching
- `src/screen_title.c` - title screen
- `src/screen_gameplay.c` - main gameplay
- `src/screen_ending.c` - ending screen
- `src/screens.h` - shared declarations
- `src/resources/` - resources folder

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

.\build\raylib-game-template\Debug\raylib-game-template.exe

