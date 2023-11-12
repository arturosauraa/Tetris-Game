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
        DrawTextEx( font, "Next", {370, 275}, 38, 2, WHITE);
        if(game.gameOver)
        {
            DrawTextEx( font, "Game Over", {320, 550}, 34, 2, WHITE);
        }
        DrawRectangleRounded({320, 55, 170, 50}, 0.3, 6, lightBlue);

        DrawTextEx( font, "Level", {365, 130}, 38, 2, WHITE);    
        DrawRectangleRounded({320, 180, 170, 50}, 0.3, 6, lightBlue);
        char levelText[10];
        sprintf(levelText, "%d", game.level);
        Vector2 textSizeLevel = MeasureTextEx(font, levelText, 38, 2);
        DrawTextEx( font, levelText, {320 + (175 - textSizeLevel.x)/2, 190}, 38, 2, WHITE);



        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);
        DrawTextEx( font, scoreText, {320 + (175 - textSize.x)/2, 65}, 38, 2, WHITE);

        DrawRectangleRounded({320, 315, 170, 180}, 0.3, 6, lightBlue);
        
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
} 