#include "Minimax.h"
#include "Evaluation.h"

#include <limits>

int Minimax::search(
    GameState &game,
    int depth,
    bool maximizingPlayer)
{
    if (game.isCheckmate())
    {
        if (game.getSideToMove() == Color::WHITE)
        {
            return -1000000;
        }
        else
        {
            return 1000000;
        }
    }

    if (game.isStalemate())
    {
        return 0;
    }

    if (depth == 0)
    {
        return Evaluation::evaluate(
            game.getPosition());
    }

    std::vector<Move> moves =
        game.getLegalMoves();

    if (moves.empty())
    {
        return Evaluation::evaluate(
            game.getPosition());
    }

    if (maximizingPlayer)
    {
        int bestScore =
            std::numeric_limits<int>::min();

        for (const Move &move : moves)
        {
            GameState nextState = game;

            nextState.playMove(
                move.getFrom(),
                move.getTo());

            int score =
                search(
                    nextState,
                    depth - 1,
                    !maximizingPlayer);

            if (score > bestScore)
            {
                bestScore = score;
            }
        }

        return bestScore;
    }

    else
    {
        int bestScore =
            std::numeric_limits<int>::max();

        for (const Move &move : moves)
        {
            GameState nextState = game;

            nextState.playMove(
                move.getFrom(),
                move.getTo());

            int score =
                search(
                    nextState,
                    depth - 1,
                    !maximizingPlayer);

            if (score < bestScore)
            {
                bestScore = score;
            }
        }

        return bestScore;
    }
}
Move Minimax::findBestMove(
    GameState game,
    int depth)
{
    std::vector<Move> moves =
        game.getLegalMoves();

    if (moves.empty())
    {
        return Move();
    }

    bool maximizingPlayer =
        game.getSideToMove() == Color::WHITE;

    Move bestMove = moves[0];

    if (maximizingPlayer)
    {
        int bestScore =
            std::numeric_limits<int>::min();

        for (const Move &move : moves)
        {
            GameState nextState = game;

            nextState.playMove(
                move.getFrom(),
                move.getTo());

            int score =
                search(
                    nextState,
                    depth - 1,
                    !maximizingPlayer);

            if (score > bestScore)
            {
                bestScore = score;
                bestMove = move;
            }
        }
    }
    else
    {
        int bestScore =
            std::numeric_limits<int>::max();

        for (const Move &move : moves)
        {
            GameState nextState = game;

            nextState.playMove(
                move.getFrom(),
                move.getTo());

            int score =
                search(
                    nextState,
                    depth - 1,
                    !maximizingPlayer);

            if (score < bestScore)
            {
                bestScore = score;
                bestMove = move;
            }
        }
    }

    return bestMove;
}