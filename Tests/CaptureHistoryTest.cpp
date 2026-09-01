#include "../Engine/GameState.h"

#include <iostream>

int main()
{
    GameState game;

    game.playMove("e2", "e4");
    game.playMove("d7", "d5");

    // White pawn captures black pawn
    game.playMove("e4", "d5");

    std::cout
        << "Total moves: "
        << game.getMoveCount()
        << "\n";

    std::cout
        << "Captures: "
        << game.getCaptureCount()
        << "\n";

    return 0;
}