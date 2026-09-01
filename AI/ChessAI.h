#ifndef CHESS_AI_H
#define CHESS_AI_H

#include "../Engine/GameState.h"

class ChessAI
{
private:
    int searchDepth;

public:
    ChessAI(int depth);

    Move chooseMove(
        GameState game);
};

#endif