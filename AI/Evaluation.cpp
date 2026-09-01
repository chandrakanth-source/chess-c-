#include "Evaluation.h"

int Evaluation::pieceValue(PieceType type)
{
    switch (type)
    {
    case PieceType::PAWN:
        return 100;

    case PieceType::KNIGHT:
        return 320;

    case PieceType::BISHOP:
        return 330;

    case PieceType::ROOK:
        return 500;

    case PieceType::QUEEN:
        return 900;

    case PieceType::KING:
        return 20000;

    default:
        return 0;
    }
}
int Evaluation::evaluate(
    const Position &position)
{
    int score = 0;

    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            Piece piece =
                position.getPiece(row, col);

            if (piece.isEmpty())
            {
                continue;
            }

            int value =
                pieceValue(piece.getType());

            if (piece.getColor() == Color::WHITE)
            {
                score += value;
            }
            else
            {
                score -= value;
            }
        }
    }

    return score;
}