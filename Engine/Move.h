#ifndef MOVE_H
#define MOVE_H
using namespace std;
#include "Piece.h"
#include <string>
enum class MoveType
{
    NORMAL,
    CASTLING,
    EN_PASSANT,
    PROMOTION
};
class Move
{

private:
    string from;
    string to;

    Piece movedPiece;
    Piece capturedPiece;
    MoveType type;

    PieceType promotionPiece;

public:
    Move();

    Move(
        const std::string &from,
        const std::string &to,
        const Piece &movedPiece,
        const Piece &capturedPiece);

    std::string getFrom() const;

    std::string getTo() const;

    Piece getMovedPiece() const;
    MoveType getMoveType() const;

    PieceType getPromotionPiece() const;

    void setMoveType(MoveType moveType);

    void setPromotionPiece(PieceType pieceType);
    Piece getCapturedPiece() const;

    bool isCapture() const;
};

#endif