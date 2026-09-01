#include "../Engine/Position.h"
#include "../Engine/MoveGenerator.h"

#include <iostream>

int main()
{
    Position position;

    std::cout
        << "White in check: "
        << MoveGenerator::isInCheck(
               position,
               Color::WHITE)
        << "\n";

    std::cout
        << "Black in check: "
        << MoveGenerator::isInCheck(
               position,
               Color::BLACK)
        << "\n";

    return 0;
}