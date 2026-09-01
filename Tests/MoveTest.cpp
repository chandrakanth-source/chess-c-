#include "../Engine/Position.h"
#include "../Engine/Move.h"
#include <iostream>

int main()
{

    Position position;

    Move move =
        position.createMove("e2", "e4");

    std::cout << "From: "
              << move.getFrom()
              << "\n";

    std::cout << "To: "
              << move.getTo()
              << "\n";

    std::cout << "Moved piece: "
              << move.getMovedPiece().getSymbol()
              << "\n";

    std::cout << "Captured piece: "
              << move.getCapturedPiece().getSymbol()
              << "\n";

    std::cout << "Is capture: "
              << (move.isCapture() ? "Yes" : "No")
              << "\n";

    return 0;
}