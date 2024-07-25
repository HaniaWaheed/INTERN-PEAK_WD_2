#include <iostream>

using namespace std;

int main()
{
    int width = 10;
    int height = 6;

    for (int i = 1; i <= height; i++) 
    {
        for (int j = 1; j <= width; j++) 
        {
            if (i == 1 || i == height || j == 1 || j == width)
            {
                cout << "#";
            }
            else if (i == height / 2 + 1)
            {
                if (j == 1 && j == width)
                {
                    cout << "#";
                }
                else
                {
                    cout << "*";
                }
            }
            else if ((j == width / 2 - (i - (height / 2 + 1)) ||
                j == width / 2 + (i - (height / 2 + 1))) ||
                i > height / 2 + 1)
            {
                cout << "*";
            }
            else
            {
                cout << "#";
            }
        }
        cout << endl;
    }
    return 0;
}
