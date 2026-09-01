#include "../Engine/Position.h"
#include "../Engine/MoveGenerator.h"

#include <iostream>

int main()
{
    Position position;

    std::vector<Move> moves =
        MoveGenerator::generateMoves(
            position,
            Color::WHITE);

    for (const Move &move : moves)
    {

        if (move.getFrom() == "e2" &&
            move.getTo() == "e4")
        {

            position.makeMove(move);

            break;
        }
    }

    Piece piece =
        position.getPiece(3, 4);

    if (!piece.isEmpty() &&
        piece.getType() == PieceType::PAWN)
    {

        std::cout
            << "e2 -> e4 successful"
            << "\n";
    }
    else
    {

        std::cout
            << "Move failed"
            << "\n";
    }

    return 0;
}