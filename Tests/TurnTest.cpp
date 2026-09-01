#include "../Engine/GameState.h"

#include <iostream>

int main()
{
    GameState game;

    std::cout << "Initial: ";

    if (game.getSideToMove() == Color::WHITE)
    {
        std::cout << "WHITE\n";
    }
    else
    {
        std::cout << "BLACK\n";
    }

    game.playMove("e2", "e4");

    std::cout << "After White move: ";

    if (game.getSideToMove() == Color::WHITE)
    {
        std::cout << "WHITE\n";
    }
    else
    {
        std::cout << "BLACK\n";
    }

    game.playMove("e7", "e5");

    std::cout << "After Black move: ";

    if (game.getSideToMove() == Color::WHITE)
    {
        std::cout << "WHITE\n";
    }
    else
    {
        std::cout << "BLACK\n";
    }

    return 0;
}