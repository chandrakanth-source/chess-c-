#include "../AI/Minimax.h"

#include <iostream>

int main()
{
    GameState game;

    std::cout
        << "Starting Minimax test...\n";

    int score =
        Minimax::search(game, 1);

    std::cout
        << "Depth 1 evaluation: "
        << score
        << "\n";

    return 0;
}