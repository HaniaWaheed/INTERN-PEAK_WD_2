/*
                      Hania Waheed
                      22i-0982
                      c
                  */

#include <iostream>

using namespace std;

//global variables
const int MAX_LINES = 100;
const int MAX_LINE_LENGTH = 60;

//function prototype
void createfile(char**& fileNames, char***& fileContents, int*& fileLineCounts, int& fileCount);
void viewFile(char** fileNames, char*** fileContents, int* fileLineCounts, int fileCount);
void editFile(char** fileNames, char*** fileContents, int* fileLineCounts, int fileCount);
void copyFile(char**& fileNames, char***& fileContents, int*& fileLineCounts, int& fileCount);
void deleteFile(char**& fileNames, char***& fileContents, int*& fileLineCounts, int& fileCount);
void listFiles(char** fileNames, int fileCount);
void countWordsCharacters(char** fileNames, char*** fileContents, int* fileLineCounts, int fileCount);
void displayFileStatistics(char** fileNames, char*** fileContents, int* fileLineCounts, int fileCount);
int countWords(const char* line);
int countCharacters(const char* line);
void calculateFileStatistics(char*** fileContents, int fileIndex, int& totalLines, int& totalWords, int& minWords, int& maxWords, int* charFreq);
bool stringsEqual(const char* str1, const char* str2);
int stringLength(const char* str);
void concatenateString(char* dest, const char* src);
char* findSubstring(char* str, const char* substr);

int main() 
{
    char** file_name = nullptr;
    char*** file_content = nullptr;
    int* line_count = nullptr;
    int file_count = 0;
    int choice;

    while (true) 
    {
        cout << "Main Menu:" << endl;
        cout << "1. Create a new file." << endl;
        cout << "2. View an existing file by providing its name." << endl;
        cout << "3. Edit an existing file by providing its name." << endl;
        cout << "4. Copy an existing file to a new file." << endl;
        cout << "5. Delete an existing file by providing its name." << endl;
        cout << "6. View a list of all files with their names." << endl;
        cout << "7. Count words or characters in an existing file." << endl;
        cout << "8. Display file statistics (number of lines, words per line)." << endl;
        cout << "9. Exit." << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            createfile(file_name, file_content, line_count, file_count);
        }
        break;
        case 2:
        {
            viewFile(file_name, file_content, line_count, file_count);
        }
        break;
        case 3: 
        {
            editFile(file_name, file_content, line_count, file_count);
        }
        break;
        case 4: 
        {
            copyFile(file_name, file_content, line_count, file_count);
        }
        break;
        case 5:
        {
            deleteFile(file_name, file_content, line_count, file_count);
        }
        break;
        case 6:
        {
            listFiles(file_name, file_count);
        }
        break;
        case 7: 
        {
            countWordsCharacters(file_name, file_content, line_count, file_count);
        }
        break;
        case 8: 
        {
            displayFileStatistics(file_name, file_content, line_count, file_count);
        }
        break;
        case 9:
            for (int i = 0; i < file_count; ++i)
            {
                for (int j = 0; j < line_count[i]; ++j)
                {
                    delete[] file_content[i][j];
                }
                delete[] file_content[i];
                delete[] file_name[i];
            }
            delete[] file_content;
            delete[] file_name;
            delete[] line_count;
            cout << "Exiting program. All data in memory has been cleared." << endl;
            return 0;
        default:
        {
            cout << "Invalid choice. Please try again." << endl;
        }
        }
    }
    return 0;
}

void createfile(char**& file_name, char***& file_content, int*& line_count, int& file_count) 
{
    char** new_file = new char* [file_count + 1];
    char*** new_content = new char** [file_count + 1];
    int* new_line_count = new int[file_count + 1];

    for (int i = 0; i < file_count; ++i)
    {
        new_file[i] = file_name[i];
        new_content[i] = file_content[i];
        new_line_count[i] = line_count[i];
    }

    delete[] file_name;
    delete[] file_content;
    delete[] line_count;

    file_name = new_file;
    file_content = new_content;
    line_count = new_line_count;

    char fileName[100];
    int numLines;
    cout << "Enter the new file name: ";
    cin.ignore();
    cin.getline(fileName, 100);

    for (int i = 0; i < file_count; ++i) 
    {
        if (stringsEqual(file_name[i], fileName)) 
        {
            cout << "File already exists." << endl;
            return;
        }
    }

    cout << "Enter the number of text lines in the file: ";
    cin >> numLines;
    cin.ignore();

    if (numLines > MAX_LINES) 
    {
        cout << "Number of lines exceeds the limit." << endl;
        return;
    }

    int length = stringLength(fileName);
    file_name[file_count] = new char[length + 1];
    for (int i = 0; i < length; ++i) 
    {
        file_name[file_count][i] = fileName[i];
    }
    file_name[file_count][length] = '\0';
    file_content[file_count] = new char* [numLines];
    line_count[file_count] = numLines;

    cout << "Enter the text lines (each line can have a maximum of 60 characters):" << endl;
    for (int i = 0; i < numLines; ++i) 
    {
        file_content[file_count][i] = new char[MAX_LINE_LENGTH + 1];
        cout << "Line " << i + 1 << ": ";
        cin.getline(file_content[file_count][i], MAX_LINE_LENGTH + 1);
    }

    ++file_count;
    cout << "File created successfully." << endl;
}

void viewFile(char** file_names, char*** file_contents, int* line_Counts, int file_Count) 
{
    char fileName[100];
    cout << "Enter the file name to view: ";
    cin.ignore();
    cin.getline(fileName, 100);

    for (int i = 0; i < file_Count; ++i) 
    {
        if (stringsEqual(file_names[i], fileName))
        {
            cout << "File content:" << endl;
            for (int j = 0; j < line_Counts[i]; ++j) 
            {
                cout << file_contents[i][j] << endl;
            }
            return;
        }
    }
    cout << "File not found." << endl;
}

void editFile(char** file_name, char*** file_Content, int* fileLineCounts, int fileCount) 
{
    char fileName[100];
    cout << "Enter the file name to edit: ";
    cin.ignore();
    cin.getline(fileName, 100);

    for (int i = 0; i < fileCount; ++i) 
    {
        if (stringsEqual(file_name[i], fileName)) 
        {
            int choice;
            cout << "1. Edit a specific line." << endl;
            cout << "2. Replace a word throughout the file." << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore(); 

            if (choice == 1) 
            {
                int lineNumber;
                cout << "Enter the line number to edit: ";
                cin >> lineNumber;
                cin.ignore(); 

                if (lineNumber < 1 || lineNumber > fileLineCounts[i])
                {
                    cout << "Invalid line number." << endl;
                    return;
                }

                cout << "Enter the new text: ";
                cin.getline(file_Content[i][lineNumber - 1], MAX_LINE_LENGTH + 1);
                cout << "Line updated successfully." << endl;
            }
            else if (choice == 2)
            {
                char oldWord[60];
                char newWord[60];
                cout << "Enter the word to replace: ";
                cin.getline(oldWord, 60);
                cout << "Enter the new word: ";
                cin.getline(newWord, 60);

                for (int j = 0; j < fileLineCounts[i]; ++j) 
                {
                    char* start = findSubstring(file_Content[i][j], oldWord);
                    while (start != nullptr)
                    {
                        int index = start - file_Content[i][j];
                        char temp[MAX_LINE_LENGTH + 1];
                        for (int k = 0; k < stringLength(file_Content[i][j] + index + stringLength(oldWord)); ++k) 
                        {
                            temp[k] = file_Content[i][j][index + stringLength(oldWord) + k];
                        }
                        temp[stringLength(file_Content[i][j] + index + stringLength(oldWord))] = '\0';
                        file_Content[i][j][index] = '\0';
                        concatenateString(file_Content[i][j], newWord);
                        concatenateString(file_Content[i][j], temp);
                        start = findSubstring(file_Content[i][j], oldWord);
                    }
                }
                cout << "Word replaced successfully." << endl;
            }
            else
            {
                cout << "Invalid choice." << endl;
            }
            return;
        }
    }
    cout << "File not found." << endl;
}

void copyFile(char**& fileNames, char***& fileContents, int*& fileLineCounts, int& fileCount) 
{
    char source_name[100];
    char dest_name[100];
    cout << "Enter the source file name: ";
    cin.ignore();
    cin.getline(source_name, 100);

    int index = -1;
    for (int i = 0; i < fileCount; ++i)
    {
        if (stringsEqual(fileNames[i], source_name))
        {
            index = i;
            break;
        }
    }

    if (index == -1) 
    {
        cout << "Source file not found." << endl;
        return;
    }

    cout << "Enter the destination file name: ";
    cin.getline(dest_name, 100);

    for (int i = 0; i < fileCount; ++i) 
    {
        if (stringsEqual(fileNames[i], dest_name)) 
        {
            cout << "Destination file already exists." << endl;
            return;
        }
    }

    char** new_file = new char* [fileCount + 1];
    char*** new_content = new char** [fileCount + 1];
    int* new_line_count = new int[fileCount + 1];

    for (int i = 0; i < fileCount; ++i)
    {
        new_file[i] = fileNames[i];
        new_content[i] = fileContents[i];
        new_line_count[i] = fileLineCounts[i];
    }

    delete[] fileNames;
    delete[] fileContents;
    delete[] fileLineCounts;

    fileNames = new_file;
    fileContents = new_content;
    fileLineCounts = new_line_count;

    int name = stringLength(dest_name);
    fileNames[fileCount] = new char[name + 1];

    for (int i = 0; i < name; ++i) 
    {
        fileNames[fileCount][i] = dest_name[i];
    }

    fileNames[fileCount][name] = '\0';
    fileLineCounts[fileCount] = fileLineCounts[index];
    fileContents[fileCount] = new char* [fileLineCounts[index]];

    for (int i = 0; i < fileLineCounts[index]; ++i) 
    {
        fileContents[fileCount][i] = new char[MAX_LINE_LENGTH + 1];
        for (int j = 0; fileContents[index][i][j] != '\0'; ++j) 
        {
            fileContents[fileCount][i][j] = fileContents[index][i][j];
        }
        fileContents[fileCount][i][stringLength(fileContents[index][i])] = '\0';
    }

    ++fileCount;
    cout << "File copied successfully." << endl;
}

void deleteFile(char**& fileNames, char***& fileContents, int*& fileLineCounts, int& fileCount) 
{
    char file[100];
    char confirm;
    cout << "Enter the file name to delete: ";
    cin.ignore();
    cin.getline(file, 100);

    for (int i = 0; i < fileCount; ++i) 
    {
        if (stringsEqual(fileNames[i], file))
        {
            cout << "Are you sure you want to delete this file? (y/n): ";
            cin >> confirm;
            cin.ignore(); 

            if (confirm == 'y' || confirm == 'Y') 
            {
                for (int j = 0; j < fileLineCounts[i]; ++j) 
                {
                    delete[] fileContents[i][j];
                }

                delete[] fileContents[i];
                delete[] fileNames[i];

                for (int j = i; j < fileCount - 1; ++j) 
                {
                    fileNames[j] = fileNames[j + 1];
                    fileContents[j] = fileContents[j + 1];
                    fileLineCounts[j] = fileLineCounts[j + 1];
                }

                --fileCount;

                char** new_file = new char* [fileCount];
                char*** new_content = new char** [fileCount];
                int* new_line = new int[fileCount];

                for (int i = 0; i < fileCount; ++i) 
                {
                    new_file[i] = fileNames[i];
                    new_content[i] = fileContents[i];
                    new_line[i] = fileLineCounts[i];
                }

                delete[] fileNames;
                delete[] fileContents;
                delete[] fileLineCounts;

                fileNames = new_file;
                fileContents = new_content;
                fileLineCounts = new_line;

                cout << "File deleted successfully." << endl;
            }
            else
            {
                cout << "File deletion cancelled." << endl;
            }
            return;
        }
    }
    cout << "File not found." << endl;
}

void listFiles(char** names, int count) 
{
    if (count == 0) 
    {
        cout << "No files available." << endl;
        return;
    }

    cout << "List of files:" << endl;
    for (int i = 0; i < count; ++i) 
    {
        cout << names[i] << endl;
    }
}

void countWordsCharacters(char** fileNames, char*** fileContents, int* fileLineCounts, int fileCount)
{
    char file_name[100];
    cout << "Enter the file name: ";
    cin.ignore();
    cin.getline(file_name, 100);

    for (int i = 0; i < fileCount; ++i) 
    {
        if (stringsEqual(fileNames[i], file_name)) 
        {
            int word = 0;
            int char_count = 0;
            for (int j = 0; j < fileLineCounts[i]; ++j) 
            {
                word += countWords(fileContents[i][j]);
                char_count += countCharacters(fileContents[i][j]);
            }

            cout << "Total words: " << word << endl;
            cout << "Total characters: " << char_count << endl;
            return;
        }
    }
    cout << "File not found." << endl;
}

void displayFileStatistics(char** fileNames, char*** fileContents, int* fileLineCounts, int fileCount) 
{
    char fileName[100];
    cout << "Enter the file name: ";
    cin.ignore();
    cin.getline(fileName, 100);

    for (int i = 0; i < fileCount; ++i)
    {
        if (stringsEqual(fileNames[i], fileName)) 
        {
            int total = fileLineCounts[i];
            int total_words = 0;
            int min = MAX_LINES;
            int max = 0;
            int freq[26] = { 0 };

            calculateFileStatistics(fileContents, i, total, total_words, min, max, freq);

            double avgWords = double(total_words) / total;

            cout << "File Statistics:" << endl;
            cout << "Total number of lines: " << total << endl;
            cout << "Average number of words per line: " << avgWords << endl;
            cout << "Minimum number of words in a line: " << min << endl;
            cout << "Maximum number of words in a line: " << max << endl;

            cout << "Character distribution:" << endl;
            for (int j = 0; j < 26; ++j)
            {
                if (freq[j] > 0) 
                {
                    cout << char('a' + j) << ": " << freq[j] << endl;
                }
            }
            return;
        }
    }
    cout << "File not found." << endl;
}

int countWords(const char* line)
{
    int count = 0;
    bool word = false;
    for (int i = 0; line[i] != '\0'; ++i) 
    {
        if (line[i] == ' ' || line[i] == '\n' || line[i] == '\t') 
        {
            word = false;
        }
        else if (!word) 
        {
            word = true;
            ++count;
        }
    }
    return count;
}

int countCharacters(const char* line) 
{
    int count = 0;
    for (int i = 0; line[i] != '\0'; ++i) 
    {
        if (line[i] != ' ' && line[i] != '\n' && line[i] != '\t')
        {
            ++count;
        }
    }
    return count;
}

void calculateFileStatistics(char*** fileContents, int fileIndex, int& totalLines, int& totalWords, int& minWords, int& maxWords, int* charFreq) 
{
    totalLines = fileIndex;
    totalWords = 0;
    minWords = MAX_LINES;
    maxWords = 0;

    for (int i = 0; i < totalLines; ++i)
    {
        int wordCount = countWords(fileContents[fileIndex][i]);
        totalWords += wordCount;
        if (wordCount < minWords) minWords = wordCount;
        if (wordCount > maxWords) maxWords = wordCount;

        for (int j = 0; fileContents[fileIndex][i][j] != '\0'; ++j) 
        {
            char c = fileContents[fileIndex][i][j];
            if (c >= 'a' && c <= 'z')
            {
                charFreq[c - 'a']++;
            }
            else if (c >= 'A' && c <= 'Z')
            {
                charFreq[c - 'A']++;
            }
        }
    }
}

bool stringsEqual(char* str1, char* str2) 
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i]) 
        {
            return false;
        }
        i++;
    }
    return str1[i] == str2[i];
}

int stringLength(const char* str)
{
    int length = 0;
    while (str[length] != '\0') 
    {
        length++;
    }
    return length;
}

void concatenateString(char* dest,  char* src) 
{
    int length = stringLength(dest);
    int i = 0;
    while (src[i] != '\0') 
    {
        dest[length + i] = src[i];
        i++;
    }
    dest[length + i] = '\0';
}

char* findSubstring(char* str,  char* substr)
{
    int strLength = stringLength(str);
    int substrLength = stringLength(substr);
    if (substrLength == 0) 
    {
        return str;
    }

    for (int i = 0; i <= strLength - substrLength; ++i)
    {
        int j = 0;
        while (j < substrLength && str[i + j] == substr[j]) 
        {
            j++;
        }
        if (j == substrLength) 
        {
            return str + i;
        }
    }
    return nullptr;
}
