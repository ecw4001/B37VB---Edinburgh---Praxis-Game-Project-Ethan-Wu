/**********************************************************************************************
*
*   raylib - Advance Game template
*
*   Ending Screen Functions Definitions (Init, Update, Draw, Unload)
*
*   Copyright (c) 2014-2022 Ramon Santamaria (@raysan5)
*
*   This software is provided "as-is", without any express or implied warranty. In no event
*   will the authors be held liable for any damages arising from the use of this software.
*
*   Permission is granted to anyone to use this software for any purpose, including commercial
*   applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*     1. The origin of this software must not be misrepresented; you must not claim that you
*     wrote the original software. If you use this software in a product, an acknowledgment
*     in the product documentation would be appreciated but is not required.
*
*     2. Altered source versions must be plainly marked as such, and must not be misrepresented
*     as being the original software.
*
*     3. This notice may not be removed or altered from any source distribution.
*
**********************************************************************************************/

#include "raylib.h"
#include "screens.h"

//----------------------------------------------------------------------------------
// Module Variables Definition (local)
//----------------------------------------------------------------------------------
static int framesCounter = 0;
static int finishScreen = 0;

//----------------------------------------------------------------------------------
// Ending Screen Functions Definition
//----------------------------------------------------------------------------------

// Ending Screen Initialization logic
void InitEndingScreen(void)
{
    framesCounter = 0;
    finishScreen = 0;
}

// Ending Screen Update logic
void UpdateEndingScreen(void)
{
    framesCounter++;

    // Press enter or space to play again
    if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE))
    {
        finishScreen = 1;
    }
}

// Ending Screen Draw logic
void DrawEndingScreen(void)
{
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), RAYWHITE);

    DrawText("GAME OVER", 250, 100, 50, BLACK);
    DrawText(TextFormat("Score: %d", GetGameplayScore()), 330, 200, 30, DARKGRAY);
    DrawText(TextFormat("High Score: %d", GetGameplayHighScore()), 300, 250, 30, DARKGRAY);
    DrawText("Press ENTER or SPACE to play again", 170, 340, 25, GRAY);
}

// Ending Screen Unload logic
void UnloadEndingScreen(void)
{
}

// Ending Screen should finish?
int FinishEndingScreen(void)
{
    return finishScreen;
}