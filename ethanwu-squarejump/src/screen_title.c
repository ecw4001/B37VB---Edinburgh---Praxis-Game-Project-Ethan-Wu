/**********************************************************************************************
*
*   raylib - Advance Game template
*
*   Title Screen Functions Definitions (Init, Update, Draw, Unload)
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
// Title Screen Functions Definition
//----------------------------------------------------------------------------------

// Title Screen Initialization logic
void InitTitleScreen(void)
{
    framesCounter = 0;
    finishScreen = 0;
}

// Title Screen Update logic
void UpdateTitleScreen(void)
{
    framesCounter++;

    // Press enter to go to gameplay
    if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE))
    {
        finishScreen = 2;   // GAMEPLAY
        PlaySound(fxCoin);
    }
}

// Title Screen Draw logic
void DrawTitleScreen(void)
{
    ClearBackground(RAYWHITE);

    // Title
    DrawText("SQUAREJUMP", 180, 100, 60, BLACK);

    // Small square decoration
    DrawRectangle(370, 190, 40, 40, BLACK);

    // Blinking message
    if ((framesCounter / 30) % 2 == 0)
    {
        DrawText("PRESS ENTER OR SPACE TO START", 150, 300, 25, DARKGRAY);
    }

    // Controls
    DrawText("JUMP OVER THE OBSTACLES", 240, 380, 20, GRAY);
}

// Title Screen Unload logic
void UnloadTitleScreen(void)
{
}

// Title Screen should finish?
int FinishTitleScreen(void)
{
    return finishScreen;
}