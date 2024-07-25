//Hania Waheed
//Roll Number: 22i-0982
//Section: F
// 
//Main Library
#include<iostream>

using namespace std;

//Calling First Function
bool isHappyNumber(int num)
{
    //User Inputs
    int i = 0;
    int sum = 0;
    int m;

    //First Iteration
    while (i < 100) 
    {
        if (num == 1)
        {
            return true;
        }
        //Second Iteration
        while (num > 0)
        {
            m = num % 10;
            sum += (m * m);
            num /= 10;
        }
        num = sum;
        i++;
    }
    return false;
}

//Main Function
int main()
{
    //User Input
    int num;

    cout << "Enter The number you want to enter " << endl;
    cin >> num;
    // First Condition
    if (isHappyNumber(num))
    {
        cout << "Happy Number";
    }
    else
    {
        cout << "Sad Number";
    }
    return 0;
}
//End of program