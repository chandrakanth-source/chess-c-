#include "../Engine/Position.h"
#include "../Engine/MoveGenerator.h"

#include <iostream>
#include <vector>

int main()
{

    Position position;

    std::vector<Move> moves =
        MoveGenerator::generateMoves(
            position,
            Color::WHITE);

    std::cout
        << "White moves: "
        << moves.size()
        << "\n\n";

    for (const Move &move : moves)
    {

        std::cout
            << move.getFrom()
            << " -> "
            << move.getTo()
            << "\n";
    }

    return 0;
}