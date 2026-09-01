#include "ChessAI.h"

#include "Minimax.h"

ChessAI::ChessAI(int depth)
{
    searchDepth = depth;
}

Move ChessAI::chooseMove(
    GameState game)
{
    return Minimax::findBestMove(
        game,
        searchDepth);
}