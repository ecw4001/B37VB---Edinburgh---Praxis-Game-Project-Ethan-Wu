/**********************************************************************************************
*
*   raylib - Advance Game template
*
*   Gameplay Screen Functions Definitions (Init, Update, Draw, Unload)
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

#define GROUND_Y 330
#define PLAYER_X 80
#define PLAYER_WIDTH 40
#define PLAYER_HEIGHT 50
#define MAX_OBSTACLES 3

// This tells the template when gameplay should end
static int finishScreen = 0;

// Player variables
static float playerY = 0;
static float playerSpeedY = 0;
static bool isJumping = false;

// Game variables
static int score = 0;
static int highScore = 0;
static float scoreTimer = 0.0f;
static float gameSpeed = 350.0f;

// Obstacle variables
static float obstacleX[MAX_OBSTACLES];
static int obstacleWidth[MAX_OBSTACLES];
static int obstacleHeight[MAX_OBSTACLES];

// Function to reset one obstacle
static void ResetObstacle(int i, float startX)
{
    obstacleX[i] = startX;

    int type = GetRandomValue(0, 2);

    if (type == 0)
    {
        obstacleWidth[i] = 20;
        obstacleHeight[i] = 40;
    }
    else if (type == 1)
    {
        obstacleWidth[i] = 30;
        obstacleHeight[i] = 55;
    }
    else
    {
        obstacleWidth[i] = 45;
        obstacleHeight[i] = 40;
    }
}

// Gameplay Screen Initialization logic
void InitGameplayScreen(void)
{
    finishScreen = 0;

    playerY = GROUND_Y - PLAYER_HEIGHT;
    playerSpeedY = 0;
    isJumping = false;

    score = 0;

    gameSpeed = 350.0f;

    // Put obstacles at different starting positions
    ResetObstacle(0, 700);
    ResetObstacle(1, 1000);
    ResetObstacle(2, 1300);
}

// Gameplay Screen Update logic
void UpdateGameplayScreen(void)
{
    float dt = GetFrameTime();

    // Jump
    // More negative = higher jump
    if (!isJumping && (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_UP)))
    {
        playerSpeedY = -700.0f;
        isJumping = true;
    }

    // Gravity
    playerY = playerY + playerSpeedY * dt;
    playerSpeedY = playerSpeedY + 2300.0f * dt;

    // Land on ground
    if (playerY >= GROUND_Y - PLAYER_HEIGHT)
    {
        playerY = GROUND_Y - PLAYER_HEIGHT;
        playerSpeedY = 0;
        isJumping = false;
    }

    // Move obstacles left
    for (int i = 0; i < MAX_OBSTACLES; i++)
    {
        obstacleX[i] = obstacleX[i] - gameSpeed * dt;

        // If obstacle goes off screen, move it to the right again
        if (obstacleX[i] + obstacleWidth[i] < 0)
        {
            float furthestX = obstacleX[0];

            for (int j = 1; j < MAX_OBSTACLES; j++)
            {
                if (obstacleX[j] > furthestX)
                {
                    furthestX = obstacleX[j];
                }
            }

            ResetObstacle(i, furthestX + GetRandomValue(250, 400));
            score = score + 1;
        }
    }

    // Increase speed slowly over time
    gameSpeed = gameSpeed + 8.0f * dt;

    // Collision check
    Rectangle playerRect = { PLAYER_X, playerY, PLAYER_WIDTH, PLAYER_HEIGHT };

    for (int i = 0; i < MAX_OBSTACLES; i++)
    {
        Rectangle obstacleRect = {
            obstacleX[i],
            GROUND_Y - obstacleHeight[i],
            obstacleWidth[i],
            obstacleHeight[i]
        };

        if (CheckCollisionRecs(playerRect, obstacleRect))
        {
            if (score > highScore)
            {
                highScore = score;
            }

            finishScreen = 1;
        }
    }


}

// Gameplay Screen Draw logic
void DrawGameplayScreen(void)
{
    ClearBackground(RAYWHITE);

    // Ground
    DrawLine(0, GROUND_Y, GetScreenWidth(), GROUND_Y, BLACK);

    // Player
    DrawRectangle(PLAYER_X, (int)playerY, PLAYER_WIDTH, PLAYER_HEIGHT, BLACK);

    // Eye
    DrawRectangle(PLAYER_X + 26, (int)playerY + 8, 4, 4, RAYWHITE);

    // Obstacles
    for (int i = 0; i < MAX_OBSTACLES; i++)
    {
        DrawRectangle(
            (int)obstacleX[i],
            GROUND_Y - obstacleHeight[i],
            obstacleWidth[i],
            obstacleHeight[i],
            BLACK
        );
    }

    // Score
    DrawText(TextFormat("Score: %04d", score), 620, 20, 20, DARKGRAY);
    DrawText(TextFormat("High Score: %d", highScore), 540, 50, 20, DARKGRAY);

    // Controls
    DrawText("Press SPACE or UP to jump", 20, 20, 20, GRAY);
}

// Gameplay Screen Unload logic
void UnloadGameplayScreen(void)
{
    // Nothing to unload
}

// Gameplay Screen should finish?
int FinishGameplayScreen(void)
{
    return finishScreen;
}
int GetGameplayScore(void)
{
    return score;
}

int GetGameplayHighScore(void)
{
    return highScore;
}