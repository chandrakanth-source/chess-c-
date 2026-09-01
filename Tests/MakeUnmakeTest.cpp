#include "../Engine/Position.h"
#include "../Engine/Move.h"

#include <iostream>

int main()
{
    Position position;

    // Get the pawn on e2
    Piece pawn = position.getPiece(1, 4);

    // Create e2 -> e4
    Move move(
        "e2",
        "e4",
        pawn,
        Piece());

    std::cout << "Before move:\n";

    std::cout
        << "e2 empty: "
        << position.getPiece(1, 4).isEmpty()
        << "\n";

    std::cout
        << "e4 empty: "
        << position.getPiece(3, 4).isEmpty()
        << "\n";

    // Make
    position.makeMove(move);

    std::cout << "\nAfter makeMove:\n";

    std::cout
        << "e2 empty: "
        << position.getPiece(1, 4).isEmpty()
        << "\n";

    std::cout
        << "e4 empty: "
        << position.getPiece(3, 4).isEmpty()
        << "\n";

    // Undo
    position.undoMove(move);

    std::cout << "\nAfter undoMove:\n";

    std::cout
        << "e2 empty: "
        << position.getPiece(1, 4).isEmpty()
        << "\n";

    std::cout
        << "e4 empty: "
        << position.getPiece(3, 4).isEmpty()
        << "\n";

    return 0;
}