#include "../Engine/GameState.h"

#include <iostream>

int main()
{
    GameState game;

    GameResult result =
        game.getGameResult();

    std::cout << "Initial result: ";

    switch (result)
    {
    case GameResult::ONGOING:
        std::cout << "ONGOING\n";
        break;

    case GameResult::WHITE_WINS:
        std::cout << "WHITE WINS\n";
        break;

    case GameResult::BLACK_WINS:
        std::cout << "BLACK WINS\n";
        break;

    case GameResult::DRAW:
        std::cout << "DRAW\n";
        break;
    }

    return 0;
}