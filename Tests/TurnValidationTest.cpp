#include "../Engine/GameState.h"

#include <iostream>

int main()
{
    GameState game;

    // White's turn
    bool whiteMove =
        game.playMove("e2", "e4");

    std::cout
        << "White e2-e4: "
        << whiteMove
        << "\n";

    // Now it is Black's turn.
    // White pawn a2-a3 should NOT be allowed.

    bool wrongPlayerMove =
        game.playMove("a2", "a3");

    std::cout
        << "Wrong-side a2-a3: "
        << wrongPlayerMove
        << "\n";

    // Black should be allowed to move.

    bool blackMove =
        game.playMove("e7", "e5");

    std::cout
        << "Black e7-e5: "
        << blackMove
        << "\n";

    return 0;
}