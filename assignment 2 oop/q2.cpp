/* Hania Waheef
roll no: 22i-0982
Section C
*/

#include <iostream>

using namespace std;

// char* smallest_substring_with_k_occurrences(const char *s, const char *t, int k);

char* smallest_substring_with_k_occurrences(const char* s, const char* t, int k) 
{
    int m = 0;
    int n = 0;
    while (s[m] != '\0')
    {
        m++;
    }
    while (t[n] != '\0')
    {
        n++;
    }

    if (m < n * k)
    {
        return nullptr;
    }

    int Alpha[256] = { 0 };
    int Count[256] = { 0 };

    for (int i = 0; i < n; ++i) 
    {
        Alpha[t[i]] += k;
    }

    int max = 0;
    int min = 0;
    for (int i = 0; i < 256; ++i) 
    {
        if (Alpha[i] > 0) 
        {
            min++;
        }
    }

    int start = 0;
    int end = 0;
    int Len = m + 1;
    int Start = 0;

    while (end <= m) 
    {
        if (Alpha[s[end]] > 0) 
        {
            Count[s[end]]++;
            if (Count[s[end]] == Alpha[s[end]]) 
            {
                max++;
            }
        }
        end++;

        while (max == min) 
        {
            if (end - start < Len)
            {
                Len = end - start;
                Start = start;
            }

            if (Alpha[s[start]] > 0) 
            {
                Count[s[start]]--;
                if (Count[s[start]] < Alpha[s[start]]) 
                {
                    max--;
                }
            }
            start++;
        }
    }

    if (Len == m + 1)
    {
        return nullptr;
    }

    char* result = new char[Len + 1];
    for (int i = 0; i < Len; ++i) 
    {
        result[i] = s[Start + i];
    }
    result[Len] = '\0'; 
    {
        return result;
    }
}


int main()
{
    char s[100];
    char t[50];
    int k;

    cout << "Enter string s: ";
    cin.getline(s, 100);

    cout << "Enter string t: ";
    cin.getline(t, 50);

    cout << "Enter value for k: ";
    cin >> k;

    char* result = smallest_substring_with_k_occurrences(s, t, k);

    if (result) 
    {
        cout << "Smallest substring: " << result << endl;
        delete[] result;
    }
    else
    {
        cout << "No substring found.\n";
    }

    return 0;
}
