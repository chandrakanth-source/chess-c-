#include "GameState.h"

GameState::GameState()
{
    sideToMove = Color::WHITE;

    whiteKingMoved = false;
    blackKingMoved = false;

    whiteKingsideRookMoved = false;
    whiteQueensideRookMoved = false;

    blackKingsideRookMoved = false;
    blackQueensideRookMoved = false;
    halfmoveClock = 0;
}
GameResult GameState::getGameResult() const
{
    if (isCheckmate())
    {
        if (sideToMove == Color::WHITE)
        {
            return GameResult::BLACK_WINS;
        }

        return GameResult::WHITE_WINS;
    }

    if (isStalemate() ||
        isFiftyMoveDraw())
    {
        return GameResult::DRAW;
    }

    return GameResult::ONGOING;
}
bool GameState::isFiftyMoveDraw() const
{
    return halfmoveClock >= 100;
}
int GameState::getHalfmoveClock() const
{
    return halfmoveClock;
}
Position &GameState::getPosition()
{
    return position;
}
const Position &GameState::getPosition() const
{
    return position;
}
Color GameState::getSideToMove() const
{
    return sideToMove;
}

void GameState::switchTurn()
{
    if (sideToMove == Color::WHITE)
    {

        sideToMove = Color::BLACK;
    }
    else
    {

        sideToMove = Color::WHITE;
    }
}
std::vector<Move> GameState::getLegalMoves() const
{
    return MoveGenerator::generateMoves(
        position,
        sideToMove);
}
bool GameState::isCheck() const
{
    return MoveGenerator::isInCheck(
        position,
        sideToMove);
}
bool GameState::playMove(
    const std::string &from,
    const std::string &to)
{
    if (isGameOver())
    {
        return false;
    }

    // Try castling first
    if ((from == "e1" && to == "g1") ||
        (from == "e1" && to == "c1") ||
        (from == "e8" && to == "g8") ||
        (from == "e8" && to == "c8"))
    {
        return performCastling(from, to);
    }

    std::vector<Move> legalMoves =
        getLegalMoves();
    if (from == "e1")
    {
        whiteKingMoved = true;
    }

    if (from == "e8")
    {
        blackKingMoved = true;
    }

    if (from == "h1")
    {
        whiteKingsideRookMoved = true;
    }

    if (from == "a1")
    {
        whiteQueensideRookMoved = true;
    }

    if (from == "h8")
    {
        blackKingsideRookMoved = true;
    }

    if (from == "a8")
    {
        blackQueensideRookMoved = true;
    }
    for (const Move &move : legalMoves)
    {
        if (move.getFrom() == from &&
            move.getTo() == to)
        {
            if (from == "e1")
                whiteKingMoved = true;

            if (from == "e8")
                blackKingMoved = true;

            if (from == "h1")
                whiteKingsideRookMoved = true;

            if (from == "a1")
                whiteQueensideRookMoved = true;

            if (from == "h8")
                blackKingsideRookMoved = true;

            if (from == "a8")
                blackQueensideRookMoved = true;

            position.makeMove(move);
            moveHistory.push_back(move);
            switchTurn();

            return true;
        }
    }

    return false;
}

bool GameState::isCheckmate() const
{
    return isCheck() &&
           getLegalMoves().empty();
}
bool GameState::isStalemate() const
{
    return !isCheck() &&
           getLegalMoves().empty();
}
bool GameState::isGameOver() const
{
    return isCheckmate() ||
           isStalemate();
}
bool GameState::canCastleKingside(Color color) const
{
    if (color == Color::WHITE)
    {
        if (whiteKingMoved ||
            whiteKingsideRookMoved)
        {
            return false;
        }
        Piece rook =
            position.getPiece(0, 7);

        if (rook.isEmpty() ||
            rook.getColor() != Color::WHITE ||
            rook.getType() != PieceType::ROOK)
        {
            return false;
        }
        if (!position.getPiece(0, 5).isEmpty() ||
            !position.getPiece(0, 6).isEmpty())
        {
            return false;
        }

        if (MoveGenerator::isSquareAttacked(
                position, 0, 4, Color::BLACK) ||
            MoveGenerator::isSquareAttacked(
                position, 0, 5, Color::BLACK) ||
            MoveGenerator::isSquareAttacked(
                position, 0, 6, Color::BLACK))
        {
            return false;
        }

        return true;
    }

    if (color == Color::BLACK)
    {
        if (blackKingMoved ||
            blackKingsideRookMoved)
        {
            return false;
        }

        Piece rook =
            position.getPiece(7, 7);

        if (rook.isEmpty() ||
            rook.getColor() != Color::BLACK ||
            rook.getType() != PieceType::ROOK)
        {
            return false;
        }

        if (!position.getPiece(7, 5).isEmpty() ||
            !position.getPiece(7, 6).isEmpty())
        {
            return false;
        }

        if (MoveGenerator::isSquareAttacked(
                position, 7, 4, Color::WHITE) ||
            MoveGenerator::isSquareAttacked(
                position, 7, 5, Color::WHITE) ||
            MoveGenerator::isSquareAttacked(
                position, 7, 6, Color::WHITE))
        {
            return false;
        }

        return true;
    }

    return false;
}
bool GameState::canCastleQueenside(Color color) const
{
    if (color == Color::WHITE)
    {
        // White king or queenside rook already moved
        if (whiteKingMoved ||
            whiteQueensideRookMoved)
        {
            return false;
        }

        // b1, c1 and d1 must be empty
        if (!position.getPiece(0, 1).isEmpty() ||
            !position.getPiece(0, 2).isEmpty() ||
            !position.getPiece(0, 3).isEmpty())
        {
            return false;
        }

        Piece rook =
            position.getPiece(0, 0);

        if (rook.isEmpty() ||
            rook.getColor() != Color::WHITE ||
            rook.getType() != PieceType::ROOK)
        {
            return false;
        }

        // King cannot be in check,
        // pass through check,
        // or end in check.
        if (MoveGenerator::isSquareAttacked(
                position,
                0, 4,
                Color::BLACK) ||
            MoveGenerator::isSquareAttacked(
                position,
                0, 3,
                Color::BLACK) ||
            MoveGenerator::isSquareAttacked(
                position,
                0, 2,
                Color::BLACK))
        {
            return false;
        }

        return true;
    }

    if (color == Color::BLACK)
    {
        if (blackKingMoved ||
            blackQueensideRookMoved)
        {
            return false;
        }

        Piece rook =
            position.getPiece(7, 0);

        if (rook.isEmpty() ||
            rook.getColor() != Color::BLACK ||
            rook.getType() != PieceType::ROOK)
        {
            return false;
        }

        if (!position.getPiece(7, 1).isEmpty() ||
            !position.getPiece(7, 2).isEmpty() ||
            !position.getPiece(7, 3).isEmpty())
        {
            return false;
        }

        if (MoveGenerator::isSquareAttacked(
                position, 7, 4, Color::WHITE) ||
            MoveGenerator::isSquareAttacked(
                position, 7, 3, Color::WHITE) ||
            MoveGenerator::isSquareAttacked(
                position, 7, 2, Color::WHITE))
        {
            return false;
        }

        return true;
    }

    return false;
}
bool GameState::performCastling(
    const std::string &from,
    const std::string &to)
{
    if (sideToMove == Color::WHITE)
    {
        // White kingside: e1 -> g1
        if (from == "e1" && to == "g1")
        {
            if (!canCastleKingside(Color::WHITE))
            {
                return false;
            }

            position.setPiece(
                0, 4, Piece());

            position.setPiece(
                0, 7, Piece());
            Piece king(
                PieceType::KING,
                Color::WHITE);

            Piece rook(
                PieceType::ROOK,
                Color::WHITE);

            position.setPiece(
                0, 6, king);

            position.setPiece(
                0, 5, rook);

            Move castleMove(
                "e1",
                "g1",
                king,
                Piece());

            castleMove.setMoveType(MoveType::CASTLING);
            moveHistory.push_back(castleMove);

            whiteKingMoved = true;
            whiteKingsideRookMoved = true;

            switchTurn();

            return true;
        }

        // White queenside: e1 -> c1
        if (from == "e1" && to == "c1")
        {
            if (!canCastleQueenside(Color::WHITE))
            {
                return false;
            }

            position.setPiece(
                0, 4, Piece());

            position.setPiece(
                0, 0, Piece());

            Piece king(
                PieceType::KING,
                Color::WHITE);

            Piece rook(
                PieceType::ROOK,
                Color::WHITE);

            position.setPiece(
                0, 2, king);

            position.setPiece(
                0, 3, rook);

            whiteKingMoved = true;
            whiteQueensideRookMoved = true;
            Move castleMove(
                "e1",
                "c1",
                king,
                Piece());

            castleMove.setMoveType(MoveType::CASTLING);

            moveHistory.push_back(castleMove);
            switchTurn();

            return true;
        }
    }

    if (sideToMove == Color::BLACK)
    {
        // Black kingside: e8 -> g8
        if (from == "e8" && to == "g8")
        {
            if (!canCastleKingside(Color::BLACK))
            {
                return false;
            }

            position.setPiece(
                7, 4, Piece());

            position.setPiece(
                7, 7, Piece());

            Piece king(
                PieceType::KING,
                Color::BLACK);

            Piece rook(
                PieceType::ROOK,
                Color::BLACK);

            position.setPiece(
                7, 6, king);

            position.setPiece(
                7, 5, rook);

            blackKingMoved = true;
            blackKingsideRookMoved = true;
            Move castleMove(
                "e8",
                "g8",
                position.getPiece(7, 6),
                Piece());

            castleMove.setMoveType(MoveType::CASTLING);

            moveHistory.push_back(castleMove);
            switchTurn();

            return true;
        }

        // Black queenside: e8 -> c8
        if (from == "e8" && to == "c8")
        {
            if (!canCastleQueenside(Color::BLACK))
            {
                return false;
            }

            position.setPiece(
                7, 4, Piece());

            position.setPiece(
                7, 0, Piece());

            Piece king(
                PieceType::KING,
                Color::BLACK);

            Piece rook(
                PieceType::ROOK,
                Color::BLACK);

            position.setPiece(
                7, 2, king);

            position.setPiece(
                7, 3, rook);

            blackKingMoved = true;
            blackQueensideRookMoved = true;
            Move castleMove(
                "e8",
                "c8",
                king,
                Piece());

            castleMove.setMoveType(MoveType::CASTLING);

            moveHistory.push_back(castleMove);
            switchTurn();

            return true;
        }
    }

    return false;
}
const std::vector<Move> &GameState::getMoveHistory() const
{
    return moveHistory;
}
int GameState::getMoveCount() const
{
    return static_cast<int>(moveHistory.size());
}
int GameState::getCaptureCount() const
{
    int captureCount = 0;

    for (const Move &move : moveHistory)
    {
        if (move.isCapture())
        {
            ++captureCount;
        }
    }

    return captureCount;
}