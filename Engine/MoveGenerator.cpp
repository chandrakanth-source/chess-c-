#include "MoveGenerator.h"

void MoveGenerator::generatePawnMoves(
    const Position &position,
    Color color,
    int row,
    int col,
    std::vector<Move> &moves)
{

    int direction;

    int startingRow;

    if (color == Color::WHITE)
    {

        direction = 1;
        startingRow = 1;
    }
    else
    {

        direction = -1;
        startingRow = 6;
    }

    // ==========================================
    // ONE SQUARE FORWARD
    // ==========================================

    int nextRow = row + direction;

    if (nextRow >= 0 && nextRow < 8)
    {

        Piece front =
            position.getPiece(nextRow, col);

        if (front.isEmpty())
        {

            std::string from;

            from += char('a' + col);
            from += char('1' + row);

            std::string to;

            to += char('a' + col);
            to += char('1' + nextRow);

            moves.push_back(
                position.createMove(from, to));

            // ==================================
            // TWO SQUARES FROM STARTING POSITION
            // ==================================

            if (row == startingRow)
            {

                int twoRows = row + 2 * direction;

                Piece twoForward =
                    position.getPiece(twoRows, col);

                if (twoForward.isEmpty())
                {

                    std::string twoTo;

                    twoTo += char('a' + col);
                    twoTo += char('1' + twoRows);

                    moves.push_back(
                        position.createMove(from, twoTo));
                }
            }
        }
    }

    // ==========================================
    // DIAGONAL CAPTURES
    // ==========================================

    int captureRow = row + direction;

    if (captureRow < 0 || captureRow >= 8)
    {
        return;
    }

    // Left diagonal

    int leftCol = col - 1;

    if (leftCol >= 0)
    {

        Piece target =
            position.getPiece(captureRow, leftCol);

        if (!target.isEmpty() &&
            target.getColor() != color)
        {

            std::string from;

            from += char('a' + col);
            from += char('1' + row);

            std::string to;

            to += char('a' + leftCol);
            to += char('1' + captureRow);

            moves.push_back(
                position.createMove(from, to));
        }
    }

    // Right diagonal

    int rightCol = col + 1;

    if (rightCol < 8)
    {

        Piece target =
            position.getPiece(captureRow, rightCol);

        if (!target.isEmpty() &&
            target.getColor() != color)
        {

            std::string from;

            from += char('a' + col);
            from += char('1' + row);

            std::string to;

            to += char('a' + rightCol);
            to += char('1' + captureRow);

            moves.push_back(
                position.createMove(from, to));
        }
    }
}

void MoveGenerator::generateKnightMoves(
    const Position &position,
    Color color,
    int row,
    int col,
    std::vector<Move> &moves)
{
    static const int offsets[8][2] = {
        {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

    for (const auto &offset : offsets)
    {
        int nextRow = row + offset[0];
        int nextCol = col + offset[1];

        if (nextRow < 0 || nextRow >= 8 ||
            nextCol < 0 || nextCol >= 8)
        {
            continue;
        }

        Piece target = position.getPiece(nextRow, nextCol);

        if (target.isEmpty() || target.getColor() != color)
        {
            std::string from;
            from += char('a' + col);
            from += char('1' + row);

            std::string to;
            to += char('a' + nextCol);
            to += char('1' + nextRow);

            moves.push_back(position.createMove(from, to));
        }
    }
}

void MoveGenerator::generateSlidingMoves(
    const Position &position,
    Color color,
    int row,
    int col,
    std::vector<Move> &moves,
    const std::vector<std::pair<int, int>> &directions)
{
    for (const auto &direction : directions)
    {
        int nextRow = row + direction.first;
        int nextCol = col + direction.second;

        while (nextRow >= 0 && nextRow < 8 &&
               nextCol >= 0 && nextCol < 8)
        {
            Piece target = position.getPiece(nextRow, nextCol);

            if (target.isEmpty())
            {
                std::string from;
                from += char('a' + col);
                from += char('1' + row);

                std::string to;
                to += char('a' + nextCol);
                to += char('1' + nextRow);

                moves.push_back(position.createMove(from, to));
            }
            else
            {
                if (target.getColor() != color)
                {
                    std::string from;
                    from += char('a' + col);
                    from += char('1' + row);

                    std::string to;
                    to += char('a' + nextCol);
                    to += char('1' + nextRow);

                    moves.push_back(position.createMove(from, to));
                }
                break;
            }

            nextRow += direction.first;
            nextCol += direction.second;
        }
    }
}

void MoveGenerator::generateKingMoves(
    const Position &position,
    Color color,
    int row,
    int col,
    std::vector<Move> &moves)
{
    static const int offsets[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    for (const auto &offset : offsets)
    {
        int nextRow = row + offset[0];
        int nextCol = col + offset[1];

        if (nextRow < 0 || nextRow >= 8 ||
            nextCol < 0 || nextCol >= 8)
        {
            continue;
        }

        Piece target = position.getPiece(nextRow, nextCol);

        if (target.isEmpty() || target.getColor() != color)
        {
            std::string from;
            from += char('a' + col);
            from += char('1' + row);

            std::string to;
            to += char('a' + nextCol);
            to += char('1' + nextRow);

            moves.push_back(position.createMove(from, to));
        }
    }
}

std::vector<Move> MoveGenerator::generateMoves(
    const Position &position,
    Color color)
{

    std::vector<Move> moves;

    for (int row = 0; row < 8; row++)
    {

        for (int col = 0; col < 8; col++)
        {

            Piece piece =
                position.getPiece(row, col);

            if (piece.isEmpty())
            {
                continue;
            }

            if (piece.getColor() != color)
            {
                continue;
            }

            switch (piece.getType())
            {

            case PieceType::PAWN:

                generatePawnMoves(
                    position,
                    color,
                    row,
                    col,
                    moves);

                break;

            case PieceType::KNIGHT:

                generateKnightMoves(
                    position,
                    color,
                    row,
                    col,
                    moves);

                break;

            case PieceType::BISHOP:
            {

                std::vector<std::pair<int, int>> directions = {
                    {1, 1},
                    {1, -1},
                    {-1, 1},
                    {-1, -1}};

                generateSlidingMoves(
                    position,
                    color,
                    row,
                    col,
                    moves,
                    directions);

                break;
            }

            case PieceType::ROOK:
            {

                std::vector<std::pair<int, int>> directions = {
                    {1, 0},
                    {-1, 0},
                    {0, 1},
                    {0, -1}};

                generateSlidingMoves(
                    position,
                    color,
                    row,
                    col,
                    moves,
                    directions);

                break;
            }

            case PieceType::QUEEN:
            {

                std::vector<std::pair<int, int>> directions = {
                    {1, 0},
                    {-1, 0},
                    {0, 1},
                    {0, -1},
                    {1, 1},
                    {1, -1},
                    {-1, 1},
                    {-1, -1}};

                generateSlidingMoves(
                    position,
                    color,
                    row,
                    col,
                    moves,
                    directions);

                break;
            }

            case PieceType::KING:

                generateKingMoves(
                    position,
                    color,
                    row,
                    col,
                    moves);

                break;

            case PieceType::EMPTY:
                break;
            }
        }
    }

    return moves;
}
bool MoveGenerator::isSquareAttacked(
    const Position &position,
    int row,
    int col,
    Color attackingColor)
{

    int pawnDirection;

    if (attackingColor == Color::WHITE)
    {
        pawnDirection = 1;
    }
    else
    {
        pawnDirection = -1;
    }

    int pawnRow = row - pawnDirection;

    if (pawnRow >= 0 && pawnRow < 8)
    {

        for (int dc : {-1, 1})
        {

            int pawnCol = col + dc;

            if (pawnCol < 0 || pawnCol >= 8)
            {
                continue;
            }

            Piece piece =
                position.getPiece(pawnRow, pawnCol);

            if (!piece.isEmpty() &&
                piece.getColor() == attackingColor &&
                piece.getType() == PieceType::PAWN)
            {

                return true;
            }
        }
    }
    const int knightMoves[8][2] = {

        {2, 1},
        {2, -1},
        {-2, 1},
        {-2, -1},

        {1, 2},
        {1, -2},
        {-1, 2},
        {-1, -2}};

    for (int i = 0; i < 8; i++)
    {

        int r = row + knightMoves[i][0];
        int c = col + knightMoves[i][1];

        if (r < 0 || r >= 8 ||
            c < 0 || c >= 8)
        {

            continue;
        }

        Piece piece =
            position.getPiece(r, c);

        if (!piece.isEmpty() &&
            piece.getColor() == attackingColor &&
            piece.getType() == PieceType::KNIGHT)
        {

            return true;
        }
    }
    const int diagonalDirections[4][2] = {

        {1, 1},
        {1, -1},
        {-1, 1},
        {-1, -1}};

    for (int i = 0; i < 4; i++)
    {

        int r = row + diagonalDirections[i][0];
        int c = col + diagonalDirections[i][1];

        while (
            r >= 0 && r < 8 &&
            c >= 0 && c < 8)
        {

            Piece piece =
                position.getPiece(r, c);

            if (!piece.isEmpty())
            {

                if (piece.getColor() == attackingColor &&
                    (piece.getType() == PieceType::BISHOP ||
                     piece.getType() == PieceType::QUEEN))
                {

                    return true;
                }

                break;
            }

            r += diagonalDirections[i][0];
            c += diagonalDirections[i][1];
        }
    }
    const int straightDirections[4][2] = {{1, 0},
                                          {-1, 0},
                                          {0, 1},
                                          {0, -1}};

    for (int i = 0; i < 4; i++)
    {

        int r = row + straightDirections[i][0];
        int c = col + straightDirections[i][1];

        while (
            r >= 0 && r < 8 &&
            c >= 0 && c < 8)
        {

            Piece piece =
                position.getPiece(r, c);

            if (!piece.isEmpty())
            {

                if (piece.getColor() == attackingColor &&
                    (piece.getType() == PieceType::ROOK ||
                     piece.getType() == PieceType::QUEEN))
                {

                    return true;
                }

                break;
            }

            r += straightDirections[i][0];
            c += straightDirections[i][1];
        }
    }
    return false;
}
bool MoveGenerator::findKing(
    const Position &position,
    Color color,
    int &kingRow,
    int &kingCol)
{

    for (int row = 0; row < 8; row++)
    {

        for (int col = 0; col < 8; col++)
        {

            Piece piece =
                position.getPiece(row, col);

            if (piece.isEmpty())
            {
                continue;
            }

            if (piece.getColor() != color)
            {
                continue;
            }

            if (piece.getType() == PieceType::KING)
            {

                kingRow = row;
                kingCol = col;

                return true;
            }
        }
    }

    return false;
}
bool MoveGenerator::isInCheck(
    const Position &position,
    Color color)
{

    int kingRow;
    int kingCol;

    if (!findKing(
            position,
            color,
            kingRow,
            kingCol))
    {

        return false;
    }

    Color opponent;

    if (color == Color::WHITE)
    {
        opponent = Color::BLACK;
    }
    else
    {
        opponent = Color::WHITE;
    }

    return isSquareAttacked(
        position,
        kingRow,
        kingCol,
        opponent);
}
bool MoveGenerator::isLegalMove(
    const Position &position,
    const Move &move,
    Color color)
{
    Position temporary = position;

    temporary.makeMove(move);

    return !isInCheck(
        temporary,
        color);
}
std::vector<Move> legalMoves;