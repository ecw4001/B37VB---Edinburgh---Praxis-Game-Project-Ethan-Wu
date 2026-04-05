# B37VB---Edinburgh---Praxis-Game-Project-Ethan-Wu

# SQUAREJUMP

SQUAREJUMP is a simple endless runner game made in C using raylib.

The player controls a square that must jump over incoming obstacles. The game continues until the player collides with an obstacle. The score increases as more obstacles are passed.

## How to Play

- Press **ENTER** or **SPACE** on the title screen to start
- Press **SPACE** or **UP ARROW** to jump
- Avoid hitting the obstacles
- After losing, press **ENTER** or **SPACE** to play again

## Game Rules

- The player moves automatically through the game
- Obstacles come from the right side of the screen
- Each obstacle passed increases the score
- The game ends when the player hits an obstacle
- The high score is shown on the ending screen

## Files

- `screen_title.c` - title screen
- `screen_gameplay.c` - main gameplay
- `screen_ending.c` - game over screen
- `raylib_game.c` - screen switching and main flow
- `screens.h` - shared declarations

## How to Compile

Open the project folder in "Developer PowerShell for VS 2022" or a terminal with MSVC available and run -

```powershell
cmake -S . -B build -G "Visual Studio 17 2022" -A x64
cmake --build build --config Debug
