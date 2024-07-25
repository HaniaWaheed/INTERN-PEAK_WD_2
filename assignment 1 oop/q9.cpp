/*
                      Hania Waheed
                      22i-0982
                      c
                  */

#include <iostream>

using namespace std;

char* Substring(char* str)
{
    if (!str || !*str)
    {
        return str;
    }

    char* max = str;  
    char* start = str + 1;  

    while (*start) 
    {
        char* temp = max;
        char* end = start;

        while (*end && *temp && (*end == *temp)) 
        {
            end++;
            temp++;
        }

        if (*end> *temp) 
        {
            max = start;
        }

        start++;
    }

    return max;
}

int main() 
{ 
    char str[1000];

    cout << "Enter a string: "<< endl;
    cin.getline(str,1000);  

    char* result = Substring(str);
    cout << "Last  substring is: " << result << endl;

    return 0;
}
