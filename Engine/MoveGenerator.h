#ifndef MOVE_GENERATOR_H
#define MOVE_GENERATOR_H

#include "Position.h"
#include "Move.h"

#include <vector>
#include <utility>

class MoveGenerator
{

private:
    static void generatePawnMoves(
        const Position &position,
        Color color,
        int row,
        int col,
        std::vector<Move> &moves);

    static void generateKnightMoves(
        const Position &position,
        Color color,
        int row,
        int col,
        std::vector<Move> &moves);

    static void generateSlidingMoves(
        const Position &position,
        Color color,
        int row,
        int col,
        std::vector<Move> &moves,
        const std::vector<std::pair<int, int>> &directions);

    static void generateKingMoves(
        const Position &position,
        Color color,
        int row,
        int col,
        std::vector<Move> &moves);

public:
    static std::vector<Move> generateMoves(
        const Position &position,
        Color color);
    static bool isSquareAttacked(
        const Position &position,
        int row,
        int col,
        Color attackingColor);
    static bool findKing(
        const Position &position,
        Color color,
        int &kingRow,
        int &kingCol);
    static bool isInCheck(
        const Position &position,
        Color color);
    static bool isLegalMove(
        const Position &position,
        const Move &move,
        Color color);
};

#endif