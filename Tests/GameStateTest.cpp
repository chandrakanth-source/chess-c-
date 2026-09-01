#include "../Engine/GameState.h"

#include <iostream>

int main()
{
    GameState game;

    std::cout << "===== INITIAL GAME =====\n\n";

    std::cout << "Side to move: ";

    if (game.getSideToMove() == Color::WHITE)
    {
        std::cout << "WHITE\n";
    }
    else
    {
        std::cout << "BLACK\n";
    }

    std::cout
        << "Legal moves: "
        << game.getLegalMoves().size()
        << "\n";

    std::cout
        << "White in check: "
        << game.isCheck()
        << "\n";

    std::cout
        << "Checkmate: "
        << game.isCheckmate()
        << "\n";

    std::cout
        << "Stalemate: "
        << game.isStalemate()
        << "\n";

    // ==========================================
    // WHITE PLAYS e2 -> e4
    // ==========================================

    std::cout << "\n===== WHITE PLAYS e2 -> e4 =====\n";

    bool result =
        game.playMove("e2", "e4");

    std::cout
        << "Move accepted: "
        << result
        << "\n";

    std::cout << "Side to move: ";

    if (game.getSideToMove() == Color::WHITE)
    {
        std::cout << "WHITE\n";
    }
    else
    {
        std::cout << "BLACK\n";
    }

    // ==========================================
    // BLACK PLAYS e7 -> e5
    // ==========================================

    std::cout << "\n===== BLACK PLAYS e7 -> e5 =====\n";

    result =
        game.playMove("e7", "e5");

    std::cout
        << "Move accepted: "
        << result
        << "\n";

    std::cout << "Side to move: ";

    if (game.getSideToMove() == Color::WHITE)
    {
        std::cout << "WHITE\n";
    }
    else
    {
        std::cout << "BLACK\n";
    }

    // ==========================================
    // WHITE PLAYS KNIGHT
    // ==========================================

    std::cout << "\n===== WHITE PLAYS g1 -> f3 =====\n";

    result =
        game.playMove("g1", "f3");

    std::cout
        << "Move accepted: "
        << result
        << "\n";

    // ==========================================
    // TEST ILLEGAL MOVE
    // ==========================================

    std::cout << "\n===== TEST ILLEGAL MOVE =====\n";

    result =
        game.playMove("e2", "e5");

    std::cout
        << "Move accepted: "
        << result
        << "\n";

    std::cout << "\n===== FINAL STATE =====\n";

    std::cout << "Side to move: ";

    if (game.getSideToMove() == Color::WHITE)
    {
        std::cout << "WHITE\n";
    }
    else
    {
        std::cout << "BLACK\n";
    }

    std::cout
        << "In check: "
        << game.isCheck()
        << "\n";

    std::cout
        << "Checkmate: "
        << game.isCheckmate()
        << "\n";

    std::cout
        << "Stalemate: "
        << game.isStalemate()
        << "\n";

    return 0;
}