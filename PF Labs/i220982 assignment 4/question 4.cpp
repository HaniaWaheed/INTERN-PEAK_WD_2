#include <iostream>
using namespace std;

int frequency_Digits(int N, int D)
{
    int c = 0;
    while (N > 0)
    {
        if (N % 10 == D)
        {
            c++;
        }
        N = N / 10; // Move the division outside the if statement
    }
    return c;
}

int main()
{
    int Num, max_freq = 0, max_digit = -1;
    cout << "Enter the positive integer: " << endl;
    cin >> Num;
    for (int d = 0; d <= 9; d++)
    {
        int freq = frequency_Digits(Num, d);
        if (freq > max_freq)
        {
            max_freq = freq;
            max_digit = d;
        }
    }
    if (max_digit != -1)
    {
        cout << "Digit with the maximum frequency in " << Num << " is " << max_digit << " with a frequency of " << max_freq << endl;
    }
    else
    {
        cout << "No digit found in " << Num << endl;
    }
    return 0;
}
