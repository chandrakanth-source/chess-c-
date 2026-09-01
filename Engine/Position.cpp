#include "Position.h"
#include <iostream>

Position::Position()
{
    initialize();
}
void Position::setPiece(
    int row,
    int col,
    const Piece &piece)
{
    board[row][col] = piece;
}
void Position::initialize()
{

    // Empty the board

    for (int row = 0; row < 8; row++)
    {

        for (int col = 0; col < 8; col++)
        {

            board[row][col] =
                Piece(PieceType::EMPTY, Color::NONE);
        }
    }
    // =========================
    // WHITE BACK RANK
    // =========================

    board[0][0] =
        Piece(PieceType::ROOK, Color::WHITE);

    board[0][1] =
        Piece(PieceType::KNIGHT, Color::WHITE);

    board[0][2] =
        Piece(PieceType::BISHOP, Color::WHITE);

    board[0][3] =
        Piece(PieceType::QUEEN, Color::WHITE);

    board[0][4] =
        Piece(PieceType::KING, Color::WHITE);

    board[0][5] =
        Piece(PieceType::BISHOP, Color::WHITE);

    board[0][6] =
        Piece(PieceType::KNIGHT, Color::WHITE);

    board[0][7] =
        Piece(PieceType::ROOK, Color::WHITE);

    // =========================
    // WHITE PAWNS
    // =========================

    for (int col = 0; col < 8; col++)
    {

        board[1][col] =
            Piece(PieceType::PAWN, Color::WHITE);
    }

    // =========================
    // BLACK BACK RANK
    // =========================

    board[7][0] =
        Piece(PieceType::ROOK, Color::BLACK);

    board[7][1] =
        Piece(PieceType::KNIGHT, Color::BLACK);

    board[7][2] =
        Piece(PieceType::BISHOP, Color::BLACK);

    board[7][3] =
        Piece(PieceType::QUEEN, Color::BLACK);

    board[7][4] =
        Piece(PieceType::KING, Color::BLACK);

    board[7][5] =
        Piece(PieceType::BISHOP, Color::BLACK);

    board[7][6] =
        Piece(PieceType::KNIGHT, Color::BLACK);

    board[7][7] =
        Piece(PieceType::ROOK, Color::BLACK);

    // =========================
    // BLACK PAWNS
    // =========================

    for (int col = 0; col < 8; col++)
    {

        board[6][col] =
            Piece(PieceType::PAWN, Color::BLACK);
    }
}
int Position::fileToColumn(char file) const
{

    if (file < 'a' || file > 'h')
    {
        return -1;
    }

    return file - 'a';
}

int Position::rankToRow(char rank) const
{

    if (rank < '1' || rank > '8')
    {
        return -1;
    }

    return rank - '1';
}
void Position::display() const
{

    std::cout << "\n";

    for (int row = 7; row >= 0; row--)
    {

        std::cout << row + 1 << " ";

        for (int col = 0; col < 8; col++)
        {

            std::cout
                << board[row][col].getSymbol()
                << " ";
        }

        std::cout << "\n";
    }

    std::cout << "\n";
    std::cout << "  a b c d e f g h\n";
}
bool Position::movePiece(
    const std::string &from,
    const std::string &to)
{

    if (from.length() != 2 ||
        to.length() != 2)
    {

        return false;
    }

    int fromCol = fileToColumn(from[0]);
    int fromRow = rankToRow(from[1]);

    int toCol = fileToColumn(to[0]);
    int toRow = rankToRow(to[1]);

    if (fromCol == -1 ||
        fromRow == -1 ||
        toCol == -1 ||
        toRow == -1)
    {

        return false;
    }

    if (board[fromRow][fromCol].isEmpty())
    {
        return false;
    }

    board[toRow][toCol] =
        board[fromRow][fromCol];

    board[fromRow][fromCol] =
        Piece();

    return true;
}
Piece Position::getPiece(int row, int col) const
{

    if (row < 0 || row >= 8 ||
        col < 0 || col >= 8)
    {

        return Piece();
    }

    return board[row][col];
}
Move Position::createMove(
    const std::string &from,
    const std::string &to) const
{

    int fromCol = fileToColumn(from[0]);
    int fromRow = rankToRow(from[1]);

    int toCol = fileToColumn(to[0]);
    int toRow = rankToRow(to[1]);

    Piece movedPiece =
        getPiece(fromRow, fromCol);

    Piece capturedPiece =
        getPiece(toRow, toCol);

    return Move(
        from,
        to,
        movedPiece,
        capturedPiece);
}
void Position::makeMove(const Move &move)
{
    int fromCol = move.getFrom()[0] - 'a';
    int fromRow = move.getFrom()[1] - '1';

    int toCol = move.getTo()[0] - 'a';
    int toRow = move.getTo()[1] - '1';

    Piece movingPiece =
        getPiece(fromRow, fromCol);

    setPiece(
        fromRow,
        fromCol,
        Piece());

    setPiece(
        toRow,
        toCol,
        movingPiece);
}
void Position::undoMove(const Move &move)
{
    int fromCol = move.getFrom()[0] - 'a';
    int fromRow = move.getFrom()[1] - '1';

    int toCol = move.getTo()[0] - 'a';
    int toRow = move.getTo()[1] - '1';

    Piece movingPiece = move.getMovedPiece();
    Piece capturedPiece = move.getCapturedPiece();

    // Put moving piece back
    board[fromRow][fromCol] = movingPiece;

    // Restore captured piece
    board[toRow][toCol] = capturedPiece;
}