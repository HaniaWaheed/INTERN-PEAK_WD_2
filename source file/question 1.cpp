#include <iostream>
#include"Header.h"

using namespace std;

//Function prototype
int myStrLen(char* str);

//Main function
int main()
{
    const int MAX_SIZE = 100;
    char myString[MAX_SIZE];
    int length;

    //User values
    cout << "Enter a string that you want to enter "<< endl;
    cin.getline(myString, MAX_SIZE) ;

    //Declare a function
    length = myStrLen(myString);

    //Length of the string return value into inteher value
    cout << "Length of the string: " << length << endl;

    return 0;
}

