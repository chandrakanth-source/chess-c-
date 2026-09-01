#ifndef EVALUATION_H
#define EVALUATION_H

#include "../Engine/Position.h"

class Evaluation
{
public:
    static int pieceValue(PieceType type);

    static int evaluate(
        const Position &position);
};

#endif