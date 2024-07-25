/*
                      Hania Waheed
                      22i-0982
                      c
                  */

#include <iostream>
using namespace std;

//Recurrsively function
void DrawPattern(char arr[50][50], int x, int y)
{
    int z = 5;
    for (int i = 0; i < z; ++i)
    {
        int index = y + i;
        int start = x - i;
        int end = x + i;

        for (int j = start; j <= end; ++j)
        {
            arr[index][j] = '*';
        }
    }
}

void initializeDisplay(char arr[50][50])
{
    for (int i = 0; i < 50; ++i)
    {
        for (int j = 0; j < 50; ++j)
        {
            arr[i][j] = ' ';
        }
    }
}



void printDisplay(char arr[50][50])
{
    for (int i = 0; i < 50; ++i)
    {
        for (int j = 0; j < 50; ++j)
        {
            cout << arr[i][j];
        }
        cout << endl;
    }
}

int main()
{
    char arr[50][50];

    initializeDisplay(arr);

    DrawPattern(arr, 20, 0);
    DrawPattern(arr, 15, 5);
    DrawPattern(arr, 25, 5);

    printDisplay(arr);

    return 0;
}