//Name: Hania Waheed 
//Roll number: 22i-0982
//Section: H

//Main Library
#include<iostream>

using namespace std;

//Function prototype
int passedSeconds(int hour, int minute, int second);
int difference(int hour, int minute, int second);

//Main function
int main()
{
    int hour1;
    int minute1;
    int second1;
    int hour2;
    int minute2;
    int second2;

    //Input user
    cout << "1. Enter hours, minutes and seconds (range 00:00:00 - 23:59:59): ";
    cin >> hour1;
    cin >> minute1;
    cin >> second1;

    //First Loop
    while (hour1 > 23 || minute1 > 59 || second1 > 59)
    {
        if (hour1 < 23)
            cout << "Enter correct hours value!"<<endl;
        if (minute1 < 59)
            cout << "Enter correct minutes value!" << endl;
        if (second1 < 59)
            cout << "Enter correct seconds value!"<< endl;

        cout << "1. Enter hours, minutes and seconds: ";
        cin >> hour1;
        cin >> minute1;
        cin >> second1;
    }

    // 2 user input
    cout << "Passed seconds from last 12 (am or pm): " << passedSeconds(hour1, minute1, second1);
    cout << "2. Enter hours, minutes and seconds (range 00:00:00 - 23:59:59): " << endl;
    cin >> hour2;
    cin >> minute2;
    cin >> second2;

    // 2 Loop
    while (hour2 > 23 || minute2 > 59 || second2 > 59)
    {
        if (hour2 < 23)
            cout << "Enter correct hours value!" <<endl;
        if (minute2 < 59)
            cout << "Enter correct minutes value!" <<endl;
        if (second2 < 59)
            cout << "Enter correct seconds value!" <<endl;

        cout << "2. Enter hours, minutes and seconds: " << endl;
        cin >> hour2;
        cin >> minute2;
        cin >> second2;
    }

    //For difference
    cout << "Difference between two times is "<< difference(hour2, minute2, second2)
        - difference(hour1, minute1, second1)  << " seconds.";
    return 0;
}

//1 Function
int passedSeconds(int hour, int minute, int second)
{
    if (hour >= 12)
        hour -= 12;

    return hour * 60 * 60 + minute * 60 + second;
}

// 2 Function
int difference(int hour, int minute, int second)
{
    return hour * 60 * 60 + minute * 60 + second;
}

//End of program