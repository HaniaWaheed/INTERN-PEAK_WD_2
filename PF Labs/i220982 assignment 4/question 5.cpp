//Hania Waheed
//Roll Number: 22i-0982
//Section: F

//Main Library
#include <iostream>
using namespace std;

//Main Function
int main() 
{
    //Variable declare
    int a[5];
    int i;
    int j;
    int max = 0;

    //First Iteration
    for (i = 0; i < 5; i++) 
    {
        cout << "Enter the value for " << i + 1 << ": ";
        cin >> a[i];
        //First Condition
        if (a[i] > max)
            max = a[i];
    }
    cout << endl;

    //Second Iteration
    for (i = max; i > 0; i--)
    {
        //Second Condition
        if (i >= 10)
        {
            cout << i << " ";
        }
        else
        {
            cout << "0" << i << " ";
        }
        //Third Iteration
        for (j = 0; j < 5; j++) 
        {
            //Third Condition
            if (i <= a[j])
                cout << "* ";
            else
                cout << "  ";
        }
        cout <<endl;
    }
    cout << "   1 2 3 4 5";
}
//End of Program