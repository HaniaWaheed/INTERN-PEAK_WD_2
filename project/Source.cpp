#include <iostream>
using namespace std;

// Define chess pieces
const char EMPTY = ' ';
const char PAWN = 'P';
const char KNIGHT = 'N';
const char BISHOP = 'B';
const char ROOK = 'R';
const char QUEEN = 'Q';
const char KING = 'K';

// Define chessboard
const int BOARD_SIZE = 8;
char board[BOARD_SIZE][BOARD_SIZE] = {
    {ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK},
    {PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN},
    {ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK}
};

// Define functions
void drawBoard() {
    cout << "  a b c d e f g h\n";
    for (int row = 0; row < BOARD_SIZE; row++) {
        cout << row + 1 << " ";
        for (int col = 0; col < BOARD_SIZE; col++) {
            cout << board[row][col] << " ";
        }
        cout << row + 1 << "\n";
    }
    cout << "  a b c d e f g h\n";
}

void makeMove() {
    string from, to;
    cout << "Enter move (e.g. 'e2e4'): ";
    cin >> from >> to;
    int fromRow = from[1] - '1';
    int fromCol = from[0] - 'a';
    int toRow = to[1] - '1';
    int toCol = to[0] - 'a';
    char piece = board[fromRow][fromCol];
    board[fromRow][fromCol] = EMPTY;
    board[toRow][toCol] = piece;
}

// Main function
int main() {
    while (true) {
        drawBoard();
        makeMove();
    }
    return 0;
}
