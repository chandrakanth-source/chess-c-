#include "../Engine/GameState.h"

#include <iostream>

int main()
{
    GameState game;

    // Clear pieces between White king and rook
    game.getPosition().setPiece(0, 5, Piece());
    game.getPosition().setPiece(0, 6, Piece());

    std::cout
        << "Can castle kingside: "
        << game.canCastleKingside(Color::WHITE)
        << "\n";

    bool result =
        game.playMove("e1", "g1");

    std::cout
        << "Castling executed: "
        << result
        << "\n";

    Piece king =
        game.getPosition().getPiece(0, 6);

    Piece rook =
        game.getPosition().getPiece(0, 5);

    std::cout
        << "King on g1: "
        << (!king.isEmpty() &&
            king.getType() == PieceType::KING)
        << "\n";

    std::cout
        << "Rook on f1: "
        << (!rook.isEmpty() &&
            rook.getType() == PieceType::ROOK)
        << "\n";

    return 0;
}