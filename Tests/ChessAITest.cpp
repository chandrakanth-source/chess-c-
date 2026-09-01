#include "../AI/ChessAI.h"

#include <iostream>

int main()
{
    GameState game;

    ChessAI ai(1);

    Move move =
        ai.chooseMove(game);

    std::cout
        << "AI selected: "
        << move.getFrom()
        << " -> "
        << move.getTo()
        << "\n";

    return 0;
}