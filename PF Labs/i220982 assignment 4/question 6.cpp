//Hania Waheed
//Roll Number: 22i-0982
//Section: F

//Main Library
#include <iostream>
#include <cmath>

using namespace std;

//Calling Function
int digit(int n, int k)
{
    //First Condition 
    if (n < 0 || k < 0)
    {
        return -1;
    }

    //Declaring Variable
    int num_digits = log10(n) + 1;

    //Second Condition
    if (k >= num_digits)
    {
        return -1;
    }
    return (n / (int)pow(10, num_digits - k - 1)) % 10;
}
//End of Program

//Main Function
int main()
{
    //Declaring Variable
    int N;
    int K;
    int d;

    cout << "Enter a positive integer i.e N" << endl;
    cin >> N;
    cout << "Enter the value of K" << endl;
    cin >> K;
    d = digit(N, K);
    //First Condition
    if (d == -1)
    {
        cout << "Error:The value of k is  out of range." << endl;
    }
    else
    {
        cout << "The " << K << "th digit of " << N << " is " << d << endl;
    }
    return 0;
}

//End of Program