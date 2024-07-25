/*
                      Hania Waheed
                      22i-0982
                      c
                  */

#include <iostream>
#include <string>

using namespace std;

bool isBalanced(string expr) 
{
    int paren= 0;
    int square = 0;
    int curly= 0;
    int index = 0; 

    for (const char& c : expr) 
    {
        if (c == '(' || c == ')') 
        {
            if (c == '(')
            {
                paren++;
            }
            else 
            {
                if (paren > 0)
                {
                    paren--;
                }
                else
                {
                    return false;
                }
            }
        }
        else if (c == '[' || c == ']')
        {
            if (c == '[')
            {
                square++;
            }
            else 
            {
                if (square > 0)
                {
                    square--;
                }
                else
                {
                    return false;
                }
            }
        }
        else if (c == '{' || c == '}')
        {
            if (c == '{')
            {
                curly++;
            }
            else
            {
                if (curly > 0)
                {
                    curly--;
                }
                else
                {
                    return false;
                }
            }
        }
    }

    return (paren + square + curly) == 0;
}

int main() 
{
    string sent;

    cout << "Enter a sentence " << endl;
    getline(cin, input);

    if (isBalanced(input)) 
    {
        cout << "Balanced Brackets" << endl;
    }
    else 
    {
        cout << "Not Balanced Brackets" << endl;
    }

    return 0;
}
