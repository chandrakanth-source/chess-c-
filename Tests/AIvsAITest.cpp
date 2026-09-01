#include "../AI/ChessAI.h"

#include <iostream>

int main()
{
    GameState game;

    ChessAI whiteAI(1);
    ChessAI blackAI(1);

    for (int turn = 0; turn < 10; turn++)
    {
        if (game.isGameOver())
        {
            break;
        }

        Move move;

        if (game.getSideToMove() == Color::WHITE)
        {
            move =
                whiteAI.chooseMove(game);
        }
        else
        {
            move =
                blackAI.chooseMove(game);
        }

        std::cout
            << (game.getSideToMove() == Color::WHITE
                    ? "White"
                    : "Black")
            << ": "
            << move.getFrom()
            << " -> "
            << move.getTo()
            << "\n";

        bool success =
            game.playMove(
                move.getFrom(),
                move.getTo());

        if (!success)
        {
            std::cout
                << "ERROR: AI generated illegal move\n";

            return 1;
        }
    }

    std::cout
        << "AI vs AI test completed.\n";

    return 0;
}