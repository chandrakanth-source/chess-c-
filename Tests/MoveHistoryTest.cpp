#include "../Engine/GameState.h"

#include <iostream>

int main()
{
    GameState game;

    std::cout << "Initial move count: "
              << game.getMoveCount()
              << "\n";

    game.playMove("e2", "e4");

    game.playMove("e7", "e5");

    game.playMove("g1", "f3");

    std::cout << "Final move count: "
              << game.getMoveCount()
              << "\n";

    std::cout << "History size: "
              << game.getMoveHistory().size()
              << "\n";

    return 0;
}