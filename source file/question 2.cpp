#include <iostream>
#include"Header.h"

using namespace std;

int main() 
{
    char inputStr[] = "A string.";
    char result = printAndUpdatePointer(inputStr);
    cout << "Result: " << result << endl;

    return 0;
}
