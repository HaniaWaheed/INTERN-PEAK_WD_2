/*
                      Hania Waheed
                      22i-0982
                      c
                  */

#include <iostream>

using namespace std;

//Main function
int Length(char* str)
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}


void Words(char*** words, int* wordCount)
{
    cout << "Enter the number of words: " << endl;
    cin >> *wordCount;
    cin.ignore();

    *words = new char* [*wordCount];

    char temp[100];
    for (int i = 0; i < *wordCount; i++)
    {
        cout << "Enter word " << i + 1 << ": " << endl;
        cin.getline(temp, 100);

        int length = Length(temp);
        (*words)[i] = new char[length + 1];

        for (int j = 0; j <= length; j++)
        {
            (*words)[i][j] = temp[j];
        }
    }
}

bool Pattern(const char* word, const char* pattern)
{
    while (*pattern && *word)
    {
        if (*pattern == '*')
        {
            if (*(pattern + 1) == '\0')
            {
                return true;
            }
            for (const char* w = word; *w; w++)
            {
                if (Pattern(w, pattern + 1))
                {
                    return true;
                }
            }
            return false;
        }
        if (*pattern != *word)
        {
            return false;
        }
        pattern++;
        word++;
    }
    return *pattern == '\0' || *pattern == '*';
}

void sortWord(char** words, int count)
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (Length(words[i]) < Length(words[j]))
            {
                char* temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

char** filter(char** words, int wordCount, const char* pattern, int* matchCount)
{
    char** matching = new char* [wordCount];
    *matchCount = 0;

    for (int i = 0; i < wordCount; i++)
    {
        if (Pattern(words[i], pattern))
        {
            matching[(*matchCount)++] = words[i];
        }
        else
        {
            delete[] words[i];
        }
    }

    sortWord(matching, *matchCount);

    delete[] words;

    char** sortedWords = new char* [*matchCount];
    for (int i = 0; i < *matchCount; i++)
    {
        sortedWords[i] = matching[i];
    }

    delete[] matching;

    return sortedWords;
}

int main()
{
    char** words;
    int wordCount;

    Words(&words, &wordCount);

    cout << "Enter a pattern: " << endl;
    char pattern[100];
    cin.getline(pattern, 100);

    int matchCount;
    char** sortedWords = filter(words, wordCount, pattern, &matchCount);

    cout << "Words matching the pattern sorted by length:" << endl;
    for (int i = 0; i < matchCount; i++)
    {
        cout << sortedWords[i] << endl;
        delete[] sortedWords[i];
    }

    delete[] sortedWords;

    return 0;
}
