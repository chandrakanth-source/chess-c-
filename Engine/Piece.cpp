#include "Piece.h"
#include <cctype>

Piece::Piece()
{
    type = PieceType::EMPTY;
    color = Color::NONE;
}

Piece::Piece(PieceType type, Color color)
{
    this->type = type;
    this->color = color;
}

PieceType Piece::getType() const
{
    return type;
}

Color Piece::getColor() const
{
    return color;
}

bool Piece::isEmpty() const
{
    return type == PieceType::EMPTY;
}

char Piece::getSymbol() const
{

    char symbol = '.';

    switch (type)
    {

    case PieceType::PAWN:
        symbol = 'P';
        break;

    case PieceType::KNIGHT:
        symbol = 'N';
        break;

    case PieceType::BISHOP:
        symbol = 'B';
        break;

    case PieceType::ROOK:
        symbol = 'R';
        break;

    case PieceType::QUEEN:
        symbol = 'Q';
        break;

    case PieceType::KING:
        symbol = 'K';
        break;

    case PieceType::EMPTY:
        symbol = '.';
        break;
    }

    if (color == Color::BLACK)
    {
        symbol = std::tolower(symbol);
    }

    return symbol;
}