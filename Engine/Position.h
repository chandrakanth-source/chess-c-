#ifndef POSITION_H
#define POSITION_H

#include "Piece.h"
#include <string>
#include "Move.h"

class Position
{

private:
    Piece board[8][8];

public:
    Position();
    void makeMove(const Move &move);
    void undoMove(const Move &move);
    void initialize();
    void setPiece(
        int row,
        int col,
        const Piece &piece);
    void display() const;

    bool movePiece(
        const std::string &from,
        const std::string &to);
    Move createMove(
        const std::string &from,
        const std::string &to) const;
    int fileToColumn(char file) const;

    int rankToRow(char rank) const;

    Piece getPiece(int row, int col) const;
};

#endif