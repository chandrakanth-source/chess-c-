#ifndef GAME_STATE_H
#define GAME_STATE_H
#include <vector>
#include <string>
#include "Position.h"
#include "MoveGenerator.h"
enum class GameResult
{
    ONGOING,
    WHITE_WINS,
    BLACK_WINS,
    DRAW
};
class GameState
{

private:
    Position position;
    bool whiteKingMoved;
    bool blackKingMoved;
    std::vector<Move> moveHistory;
    bool whiteKingsideRookMoved;
    bool whiteQueensideRookMoved;

    bool blackKingsideRookMoved;
    bool blackQueensideRookMoved;
    Color sideToMove;
    int halfmoveClock;

public:
    GameState();
    GameResult getGameResult() const;
    bool playMove(
        const std::string &from,
        const std::string &to);
    Position &getPosition();
    bool isFiftyMoveDraw() const;
    const std::vector<Move> &getMoveHistory() const;
    int getMoveCount() const;
    int getCaptureCount() const;
    const Position &getPosition() const;
    bool canCastleKingside(Color color) const;
    bool performCastling(const std::string &from,
                         const std::string &to);
    bool canCastleQueenside(Color color) const;
    Color getSideToMove() const;

    void switchTurn();

    std::vector<Move> getLegalMoves() const;
    int getHalfmoveClock() const;
    bool isCheck() const;

    bool isCheckmate() const;

    bool isStalemate() const;

    bool isGameOver() const;
};

#endif