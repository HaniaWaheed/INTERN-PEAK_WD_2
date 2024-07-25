/*
                      Hania Waheed
                      22i-0982
                      c
                  */

#include <iostream>

using namespace std;

int Length(char* str)
{
    int start = 0;
    while (str[start] != '\0') 
    {
        start++;
    }
    return start;
}

bool checksimilar(char* str1, char* str2) 
{
    int len1 = Length(str1);
    int len2 = Length(str2);

    if (len1 < len2) 
    {
        char* temp = str1;
        str1 = str2;
        str2 = temp;
        int Len = len1;
        len1 = len2;
        len2 = Len;
    }

    char* start1 = str1;
    char* end1 = str1 + len1 - 1;
    char* start2 = str2;
    char* end2 = str2 + len2 - 1;

    while (start2 <= end2 && *start1 == *start2)
    {
        start1++;
        start2++;
    }

    while (start2 <= end2 && *end1 == *end2) 
    {
        end1--;
        end2--;
    }

    return start2 > end2;
}

float percentagesimilarity(char* str1, char* str2)
{
    int len1 = Length(str1);
    int len2 = Length(str2);
    int c = 0;

    for (int i = 0; i < len1 && i < len2; i++) 
    {
        if (str1[i] == str2[i])
        {
            c++;
        }
    }

    float max = (len1 > len2) ? len1 : len2;
    return (c / max) * 100;
}

int main()
{
    char sentence1[100];
    char sentence2[100];

    cout << "Enter first sentence: " << endl;
    cin.getline(sentence1, 100);

    cout << "Enter second sentence: "<< endl;
    cin.getline(sentence2, 100);

    if (checksimilar(sentence1, sentence2))
    {
        cout << "The sentences are similar." << endl;
    }
    else 
    {
        cout << "The sentences are not similar." << endl;
    }

    float similar = percentagesimilarity(sentence1, sentence2);
   cout << "The percentage of similarity between the sentences is: " << similar<< "%" << endl;

    return 0;
}
