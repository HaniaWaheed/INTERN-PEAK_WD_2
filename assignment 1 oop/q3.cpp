                    /*
                        Hania Waheed
                        22i-0982
                        c
                    */


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


//Global variables

const int size = 15;
const int Path = 52;
const int home[4][2] = { {1, 1}, {1, 13}, {13, 1}, {13, 13} };
const char TOKEN[] = { 'A', 'B', 'C', 'D' };
const int position[4][4][2] = {
    { {1, 2}, {2, 1}, {2, 2}, {1, 1} }, //player A
    { {1, 12}, {2, 13}, {2, 12}, {1, 13} }, // Player B
    { {13, 2}, {12, 1}, {12, 2}, {13, 1} }, // Player C
    { {13, 12}, {12, 13}, {12, 12}, {13, 13} }  // Player D
};


const int path[4][52][2] =
{
    {
        { 6,  6}, { 7,  6}, { 8,  6}, { 9,  6}, {10,  6}, {11,  6}, {12,  6},
        {12,  5}, {12,  4}, {12,  3}, {12,  2}, {12,  1}, {11,  1}, {10,  1},
        { 9,  1}, { 8,  1}, { 7,  1}, { 6,  1}, { 6,  2}, { 6,  3}, { 6,  4},
        { 6,  5}, { 7,  0}, { 7,  1}, { 7,  2}, { 7,  3}, { 7,  4}, { 7,  5},
        { 8,  5}, { 9,  5}, {10,  5}, {11,  5}, {12,  5}, {13,  5}, {13,  6},
        {13,  7}, {13,  8}
    },

    {
        { 8,  8}, { 8,  9}, { 8, 10}, { 8, 11}, { 8, 12}, { 8, 13}, { 9, 13},
        {10, 13}, {11, 13}, {12, 13}, {13, 13}, {13, 12}, {13, 11}, {13, 10},
        {13,  9}, {13,  8}, {12,  8}, {11,  8}, {10,  8}, { 9,  8}, { 8,  8},
        {14,  7}, {13,  7}, {12,  7}, {11,  7}, {10,  7}, { 9,  7},
        { 8,  7}, { 7,  7}, { 6,  7}, { 5,  7}, { 4,  7}, { 3,  7}, { 2,  7},
        { 1,  7}, { 0,  7}
    },

    {
        { 8,  8}, { 7,  8}, { 6,  8}, { 5,  8}, { 4,  8}, { 3,  8}, { 2,  8},
        { 2,  9}, { 2, 10}, { 2, 11}, { 2, 12}, { 2, 13}, { 1, 13}, { 0, 13},
        { 1, 12}, { 1, 11}, { 1, 10}, { 1,  9}, { 1,  8}, { 2,  8}, { 3,  8},
        { 4,  8}, { 5,  8}, { 6,  8}, { 7,  8}, { 7,  9}, { 7, 10}, { 7, 11},
        { 7, 12}, { 7, 13}, { 6, 13}, { 5, 13}, { 4, 13}, { 3, 13}, { 2, 13},
        { 1, 13}, { 0, 13}
    },

    {
        { 6,  6}, { 6,  7}, { 6,  8}, { 6,  9}, { 6, 10}, { 6, 11}, { 5, 12},
        { 4, 12}, { 3, 12}, { 2, 12}, { 1, 12}, { 1, 11}, { 1, 10}, { 1,  9},
        { 1,  8}, { 1,  7}, { 2,  7}, { 3,  7}, { 4,  7}, { 5,  7}, { 6,  7},
        { 0,  7}, { 1,  7}, { 2,  7}, { 3,  7}, { 4,  7}, { 5,  7},
        { 6,  7}, { 7,  7}, { 8,  7}, { 9,  7}, {10,  7}, {11,  7}, {12,  7},
        {13,  7}, {14,  7}
    }
};

void printTopLeft(int row, int col)
{
    if ((row == 0 || row == 5) || (col == 0 || col == 5))
    {
        cout << "+";
    }
    else if (row % 2 == 1 && col % 2 == 1)
    {
        cout << "\\";
    }
    else if (row % 2 == 0 && col % 2 == 0)
    {
        cout << "/";
    }
    else
    {
        cout << " ";
    }
}

void printTopRight(int row, int col)
{
    if ((row == 0 || row == 5) || (col == 9 || col == 14))
    {
        cout << "+";
    }
    else if ((row == 1 || row == 4) && (col == 10 || col == 13))
    {
        cout << "/";
    }
    else if ((row == 2 || row == 3) && (col == 11 || col == 12))
    {
        cout << "\\";
    }
    else
    {
        cout << " ";
    }
}

void printBottomLeft(int row, int col)
{
    if ((row == 9 || row == 14) || (col == 0 || col == 5))
    {
        cout << "+";
    }
    else if ((row == 10 || row == 13) && (col == 1 || col == 4))
    {
        cout << "/";
    }
    else if ((row == 11 || row == 12) && (col == 2 || col == 3))
    {
        cout << "\\";
    }
    else
    {
        cout << " ";
    }
}

void printBottomRight(int row, int col)
{
    if ((row == 9 || row == 14) || (col == 9 || col == 14))
    {
        cout << "+";
    }
    else if ((row == 10 || row == 13) && (col == 10 || col == 13))
    {
        cout << "/";
    }
    else if ((row == 11 || row == 12) && (col == 11 || col == 12))
    {
        cout << "\\";
    }
    else
    {
        cout << " ";
    }
}
void printHorizontalLine(int col)
{
    if (col == 0 || col == 14)
    {
        cout << "+";
    }
    else
    {
        cout << "-";
    }
}
void printVerticalLine(int row)
{
    if (row == 0 || row == 14)
    {
        cout << "+";
    }
    else
    {
        cout << "|";
    }
}

void printMiddle(int row, int col, const int tokens[4][4])
{
    bool tokenPresent = false;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (row == tokens[i][j] / size && col == tokens[i][j] % size)
            {
                cout << TOKEN[i];
                tokenPresent = true;
                break;
            }
        }
        if (tokenPresent)
        {
            break;
        }
    }
    if (!tokenPresent)
    {
        bool isPath = false;
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < Path; ++j)
            {
                if (path[i][j][0] == row && path[i][j][1] == col)
                {
                    cout << "I";
                    isPath = true;
                    break;
                }
            }
            if (isPath)
            {
                break;
            }
        }
        if (!isPath)
        {
            if (row == 7 && col == 7)
            {
                cout << " ";
            }
            else
            {
                cout << " ";
            }
        }
    }
}

void printLine(int row, int col, const int tokens[4][4])
{
    if (col >= size)
    {
        return;
    }
    if (row < 6 && col < 6)
    {
        printTopLeft(row, col);
    }
    else if (row < 6 && col >= 9)
    {
        printTopRight(row, col);
    }
    else if (row >= 9 && col < 6)
    {
        printBottomLeft(row, col);
    }
    else if (row >= 9 && col >= 9)
    {
        printBottomRight(row, col);
    }
    else if (row == 6 || row == 8)
    {
        printHorizontalLine(col);
    }
    else if (col == 6 || col == 8)
    {
        printVerticalLine(row);
    }
    else
    {
        printMiddle(row, col, tokens);
    }
    printLine(row, col + 1, tokens);
}

void printBoard(int row, const int tokens[4][4])
{
    if (row >= size)
    {
        return;
    }
    printLine(row, 0, tokens);
    cout << endl;
    printBoard(row + 1, tokens);
}

int rollDice()
{
    return (rand() % 6) + 1;
}
void moveToken(int& tokenRow, int& tokenCol, int& tokenPos, int steps, int player, int tokens[4][4])
{
    if (tokenPos == -1)
    {
        if (steps == 6)
        {
            for (int i = 0; i < 4; ++i)
            {
                if (tokens[player][i] == -1)
                {
                    tokenRow = position[player][i][0];
                    tokenCol = position[player][i][1];
                    tokenPos = 0;
                    return;
                }
            }
        }
        return;
    }
    int nextPos = (tokenPos + steps) % Path;
    for (int i = 0; i < 4; ++i)
    {
        if (i != tokenPos / size && tokens[player][i] == nextPos)
        {
            return;
        }
    }
    for (int p = 0; p < 4; ++p)
    {
        if (p != player)
        {
            for (int t = 0; t < 4; ++t)
            {
                if (tokens[p][t] == nextPos)
                {
                    tokens[p][t] = -1;
                }
            }
        }
    }
    tokenRow = path[player][nextPos][0];
    tokenCol = path[player][nextPos][1];
    tokenPos = nextPos;
}
bool checkWin(const int tokens[4][4])
{
    for (int player = 0; player < 4; ++player)
    {
        int tokensInHome = 0;
        for (int token = 0; token < 4; ++token)
        {
            if (tokens[player][token] >= Path - 6)
            {
                tokensInHome++;
            }
        }
        if (tokensInHome == 4)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    srand(time(0));
    int tokens[4][4];
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            tokens[i][j] = -1;
        }
    }

    int currentPlayer = 0;

    while (!checkWin(tokens))
    {
        printBoard(0, tokens);
        cout << "\nPlayer " << TOKEN[currentPlayer] << ", roll the dice (press Enter): ";
        cin.get();
        int diceRoll = rollDice();
        cout << "You rolled a " << diceRoll << endl;
        int tokenToMove;
        do
        {
            cout << "Which token to move (1, 2, 3, or 4): ";
            if (!(cin >> tokenToMove))
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input. Please enter a number between 1 and 4." << endl;
            }
            else if (tokenToMove < 1 || tokenToMove > 4)
            {
                cout << "Invalid token number. Please choose a token between 1 and 4." << endl;
            }
            else
            {
                tokenToMove--;
                if (tokens[currentPlayer][tokenToMove] == -1 && diceRoll != 6)
                {
                    cout << "That token is not on the board yet. You need to roll a 6." << endl;
                }
                else
                {
                    break;
                }
            }
        } while (true);
        int newTokenRow = tokens[currentPlayer][tokenToMove] / size;
        int newTokenCol = tokens[currentPlayer][tokenToMove] % size;
        moveToken(newTokenRow, newTokenCol, tokens[currentPlayer][tokenToMove], diceRoll, currentPlayer, tokens);

        currentPlayer = (currentPlayer + 1) % 4;
    }

    cout << "\nPlayer " << TOKEN[currentPlayer] << " wins!" << endl;

    return 0;
}
