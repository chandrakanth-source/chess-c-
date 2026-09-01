#include "Move.h"

Move::Move() : from(""),
               to(""),
               movedPiece(),
               capturedPiece(),
               type(MoveType::NORMAL),
               promotionPiece(PieceType::QUEEN)
{
}

Move::Move(
    const std::string &from,
    const std::string &to,
    const Piece &movedPiece,
    const Piece &capturedPiece) : from(from),
                                  to(to),
                                  movedPiece(movedPiece),
                                  capturedPiece(capturedPiece),
                                  type(MoveType::NORMAL),
                                  promotionPiece(PieceType::QUEEN)
{

    this->from = from;
    this->to = to;

    this->movedPiece = movedPiece;
    this->capturedPiece = capturedPiece;
}
std::string Move::getFrom() const
{
    return from;
}

std::string Move::getTo() const
{
    return to;
}

Piece Move::getMovedPiece() const
{
    return movedPiece;
}

Piece Move::getCapturedPiece() const
{
    return capturedPiece;
}
bool Move::isCapture() const
{

    return !capturedPiece.isEmpty();
}
MoveType Move::getMoveType() const
{
    return type;
}
PieceType Move::getPromotionPiece() const
{
    return promotionPiece;
}
void Move::setMoveType(MoveType moveType)
{
    type = moveType;
}
void Move::setPromotionPiece(PieceType pieceType)
{
    promotionPiece = pieceType;
}