            /*
                Hania Waheed
                roll no: 22i-0982
                section:C
            */
#include <iostream>
#include <cstring>
using namespace std;


//Recurrsive Function

void removeDuplication(char* str)
{

    //user value 
    int in = 1;

    //Calculate string lenght
    int lenght = strlen(str);

    while (in < lenght)
    {
        if (str[in] == str[in - 1])
        {
            for (int i = i; i < lenght; ++i)
            {
                str[i] = str[i + 1];
            }
            --lenght;
        }
        else
        {
            ++in;
        }
    }

    // End of string
    str[lenght] = '\0';
}

//second function
void removeZeros(char* str)
{
    //user value
    int in = 0;

    //calculate lenght string
    int lenght = strlen(str);

    while (in < lenght)
    {
        if (str[in] == '0')
        {
            for (int i = in; i < lenght; ++i)
            {
                str[i] = str[i + 1];
            }
            --lenght;
        }
        else
        {
            ++in;
        }
    }
    //ENd of string
    str[lenght] = '\0';
}

string soundex(const string& name)
{
    int index = 1;
    char arr[5] = { '0', '0', '0', '0', '\0' };

    if (name[0] == '\0')
    {
        return "0000";
    }

    arr[0] = name[0] >= 'a' && name[0] <= 'z' ? name[0] - ('a' - 'A') : name[0];

    for (int i = 1; name[i] != '\0'; ++i)
    {
        char c = name[i] >= 'a' && name[i] <= 'z' ? name[i] - ('a' - 'A') : name[i];

        char digit;
        if (c == 'B' || c == 'F' || c == 'P' || c == 'V')
        {
            digit = '1';
        }
        else if (c == 'C' || c == 'G' || c == 'J' || c == 'K' || c == 'Q' || c == 'S' || c == 'X' || c == 'Z')
        {
            digit = '2';
        }
        else if (c == 'D' || c == 'T')
        {
            digit = '3';
        }
        else if (c == 'M' || c == 'N')
        {
            digit = '4';
        }
        else if (c == 'L')
        {
            digit = '5';
        }
        else if (c == 'R')
        {
            digit = '6';
        }
        else
        {
            digit = '0';
        }
        if (digit != '0' && index < 4)
        {
            arr[index++] = digit;
        }
    }
    removeDuplication(arr);
    removeZeros(arr);
    int length = 0;

    while (arr[length] != '\0')
    {
        ++length;
    }

    while (length < 4)
    {
        arr[length++] = '0';
    }
    arr[4] = '\0';

    return string(arr);
}

int main()
{
    string name;
    cout << "Enter the name " << endl;
    cin >> name;
    string code = soundex(name);

    cout << "Soundex code: " << code << endl;

    return 0;
}