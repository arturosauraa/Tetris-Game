#include <raylib.h>
#include <iostream>
#include "game.h"
#include "colors.h"


using namespace std;

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if(currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}


int main()
{
    Color darkBlue = {44, 44, 127, 255};
    InitWindow(500, 620, "Tetris Game");
    SetTargetFPS(60);
    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);

    Game game = Game();

    

    while(WindowShouldClose() == false)
    {
        game.HandleInput();
        if(EventTriggered(game.gameSpeed))
        {
            game.MoveBlockDown();
        }

        BeginDrawing();
        ClearBackground(darkBlue);
        DrawTextEx( font, "Score", {365, 15}, 38, 2, WHITE);
        DrawTextEx( font, "Next", {370, 175}, 38, 2, WHITE);
        if(game.gameOver)
        {
            DrawTextEx( font, "Game Over", {320, 450}, 34, 2, WHITE);
        }
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);

        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);
        DrawTextEx( font, scoreText, {320 + (175 - textSize.x)/2, 65}, 38, 2, WHITE);

        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);
        
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
} 