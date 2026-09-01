#ifndef PIECE_H
#define PIECE_H

enum class PieceType
{
    EMPTY,
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING
};

enum class Color
{
    NONE,
    WHITE,
    BLACK
};

class Piece
{
private:
    PieceType type;
    Color color;

public:
    Piece();

    Piece(PieceType type, Color color);

    PieceType getType() const;

    Color getColor() const;

    bool isEmpty() const;

    char getSymbol() const;
};

#endif