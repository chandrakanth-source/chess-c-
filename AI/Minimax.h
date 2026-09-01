#ifndef MINIMAX_H
#define MINIMAX_H

#include "../Engine/GameState.h"

class Minimax
{
public:
    static int search(
        GameState &game,
        int depth,
        bool maximizingPlayer = true);
    static Move findBestMove(
        GameState game,
        int depth);
};

#endif