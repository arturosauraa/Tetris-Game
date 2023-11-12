#pragma once
#include "grid.h"
#include "blocks.cpp"



class Game
{

public:
    Game();
    void Draw();
    void HandleInput();
    void MoveBlockDown();
    void UpdateSpeed();
    bool gameOver;
    int score;
    double gameSpeed;
    int scoreSpeed;
    int level;

private:
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
    Grid grid;
    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks();
    void MoveBlockLeft();
    void MoveBlockRight();
    bool isBlockOutside();
    void RotateBlock();
    void LockBlock();
    bool BlockFits();
    void Reset();
    void UpdateScore(int linesCleared, int moveDownPoints);

};