#include "../AI/Minimax.h"

#include <iostream>

int main()
{
    GameState game;

    std::cout
        << "Finding best move...\n";

    Move bestMove =
        Minimax::findBestMove(game, 1);

    std::cout
        << "Best move: "
        << bestMove.getFrom()
        << " -> "
        << bestMove.getTo()
        << "\n";

    return 0;
}