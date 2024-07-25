#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Enum for color of pieces
enum Color {
    BLACK,
    WHITE
};

// Enum for type of pieces
enum PieceType {
    PAWN,
    ROOK,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING
};

// Class to represent a Chess Piece
class ChessPiece {
public:
    Color color;
    PieceType type;

    ChessPiece(Color c, PieceType t) {
        color = c;
        type = t;
    }
};

// Class to represent a Chess Board
class ChessBoard {
public:
    vector<vector<ChessPiece*>> board;

    ChessBoard() {
        board.resize(8, vector<ChessPiece*>(8, nullptr));
        // Initializing pawns
        for (int i = 0; i < 8; i++) {
            board[1][i] = new ChessPiece(BLACK, PAWN);
            board[6][i] = new ChessPiece(WHITE, PAWN);
        }
        // Initializing rooks, knights, bishops
        board[0][0] = new ChessPiece(BLACK, ROOK);
        board[0][7] = new ChessPiece(BLACK, ROOK);
        board[7][0] = new ChessPiece(WHITE, ROOK);
        board[7][7] = new ChessPiece(WHITE, ROOK);

        board[0][1] = new ChessPiece(BLACK, KNIGHT);
        board[0][6] = new ChessPiece(BLACK, KNIGHT);
        board[7][1] = new ChessPiece(WHITE, KNIGHT);
        board[7][6] = new ChessPiece(WHITE, KNIGHT);

        board[0][2] = new ChessPiece(BLACK, BISHOP);
        board[0][5] = new ChessPiece(BLACK, BISHOP);
        board[7][2] = new ChessPiece(WHITE, BISHOP);
        board[7][5] = new ChessPiece(WHITE, BISHOP);

        board[0][3] = new ChessPiece(BLACK, QUEEN);
        board[7][3] = new ChessPiece(WHITE, QUEEN);

        board[0][4] = new ChessPiece(BLACK, KING);
        board[7][4] = new ChessPiece(WHITE, KING);
    }

    // Function to print the current state of the board
    void printBoard() {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == nullptr) {
                    cout << "- ";
                }
                else {
                    switch (board[i][j]->type) {
                    case PAWN:
                        cout << "P";
                        break;
                    case ROOK:
                        cout << "R";
                        break;
                    case KNIGHT:
                        cout << "N";
                        break;
                    case BISHOP:
                        cout << "B";
                        break;
                    case QUEEN:
                        cout << "Q";
                        break;
                    case KING:
                        cout << "K";
                        break;
                    }
                    if (board[i][j]->color == WHITE) {
                        cout << "w ";
                    }
                    else {
                        cout << "b ";
                    }
                }
            }
            cout << endl;
        }
    }