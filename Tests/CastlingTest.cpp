#include "../Engine/GameState.h"

#include <iostream>

int main()
{
    GameState game;

    std::cout
        << "White kingside castling: "
        << game.canCastleKingside(Color::WHITE)
        << "\n";

    std::cout
        << "White queenside castling: "
        << game.canCastleQueenside(Color::WHITE)
        << "\n";

    return 0;
}