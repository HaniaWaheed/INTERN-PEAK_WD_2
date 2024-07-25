#pragma once
/*
        Your Name:Hania Waheed
        Your Roll# 22i-0982
        Your Section: D

*/

#include<iostream>
using namespace std;

// DON'T CHANGE THE PROTOTYPES OF FUNCTION

const int max_page = 10;
const int max_l_p_page = 10;
const int max_cha_p_l = 40;

//----------------------- Q1 -----------------------
char* BaseConverter(float number, int base)
{
    if (base < 2 || base > 36)
    {
        char* error = new char[100];
        char Message[] = "The base should be between 2 to 36.";
        for (int i = 0; i < 99; i++)
        {
            error[i] = Message[i];
        }
        error[99] = '\0';
        return error;
    }
    bool Negative = false;
    if (number < 0)
    {
        Negative = true;
        // number = abs(number);
    }
    int part = static_cast<int>(number);
    float fraction = number - part;
    char result[50];
    int index = 0;
    while (part > 0)
    {
        int remaind = part % base;
        result[index++] = (remaind < 10) ? (remaind + '0') : (remaind - 10 + 'A');
        part /= base;
    }
    if (index == 0)
    {
        result[index++] = '0';
    }
    result[index] = '\0';
    char frac[50];
    int i = 0;
    while (fraction > 0 && i < 10)
    {
        fraction = fraction * base;
        int integralPart = static_cast<int>(fraction);
        frac[i++] = (integralPart < 10) ? (integralPart + '0') : (integralPart - 10 + 'A');
        fraction = fraction - integralPart;
    }
    frac[i] = '\0';
    char* resultPtr = new char[100];
    int Result = 0;
    if (Negative)
    {
        resultPtr[Result++] = '-';
    }
    for (int i = index - 1; i >= 0; --i)
    {
        resultPtr[Result++] = result[i];
    }
    if (i > 0)
    {
        resultPtr[Result++] = '.';
        for (int i = 0; i < i ; ++i)
        {
            resultPtr[Result++] = frac[i];
        }
    }
    resultPtr[Result] = '\0';

    return resultPtr;
}
////----------------------- Q2 -----------------------
//void makeBook(char* text, char***& book, int& totalPages)
//{
//    int textLength = strlen(text);
//    totalPages = (textLength / (max_l_p_page * max_cha_p_l)) + 1;
//
//    // Dynamically allocate memory for each layer
//    book = new char** [totalPages];
//    for (int i = 0; i < totalPages; i++) {
//        book[i] = new char* [max_l_p_page];
//        for (int j = 0; j < max_l_p_page; j++) {
//            book[i][j] = new char[max_cha_p_l + 1]; // Allocate +1 for null terminator
//            // Initialize each character array with null characters
//            for (int k = 0; k < max_cha_p_l; k++) {
//                book[i][j][k] = '\0';
//            }
//        }
//    }
//
//    // Fill the book array with data from the text array
//    int currentPage = 0, currentLine = 0, currentChar = 0;
//    for (int i = 0; i < textLength && currentPage < totalPages; i++) {
//        if (text[i] == '\n' || currentChar == max_cha_p_l)
//        {
//            currentLine++;
//            currentChar = 0;
//            if (currentLine == max_l_p_page)
//            {
//                currentLine = 0;
//                currentPage++;
//            }
//        }
//        book[currentPage][currentLine][currentChar] = text[i];
//        currentChar++;
//    }
//}
//void cut(char***& book, int& totalPages, int FromPage, int ToPage, int FromLine, int ToLine, int FromWord, int ToWord, char*& clipboard)
//{
//    // Calculate the size of the clipboard buffer
//    int clipboardSize = (ToWord - FromWord) + 1;
//    clipboard = new char[clipboardSize]; // Allocate memory for clipboard
//    int in = 0;
//    // Loop through the specified range of pages, lines, and words
//    for (int i = FromPage; i <= ToPage; ++i) {
//        for (int j = (i == FromPage ? FromLine : 0); j <= (i == ToPage ? ToLine : max_l_p_page - 1); ++j) {
//            for (int k = ((i == FromPage && j == FromLine) ? FromWord : 0); k <= ((i == ToPage && j == ToLine) ? ToWord : max_cha_p_l - 1); ++k) {
//                clipboard[in++] = book[i][j][k]; // Copy characters to clipboard
//                book[i][j][k] = '\0';  // Cut the text by replacing with null characters
//            }
//        }
//    }
//    clipboard[in] = '\0'; // Null-terminate the clipboard buffer
//}
//void copy(char***& book, int totalPages, int FromPage, int ToPage, int FromLine, int ToLine, int FromWord, int ToWord, char*& clipboard)
//{
//    // Calculate the size of the clipboard buffer
//    int clipboardSize = (ToWord - FromWord) + 1;
//    clipboard = new char[clipboardSize]; // Allocate memory for clipboard
//    int index = 0;
//    // Loop through the specified range of pages, lines, and words
//    for (int i = FromPage; i <= ToPage; ++i) {
//        for (int j = (i == FromPage ? FromLine : 0); j <= (i == ToPage ? ToLine : max_l_p_page - 1); ++j) {
//            for (int k = ((i == FromPage && j == FromLine) ? FromWord : 0); k <= ((i == ToPage && j == ToLine) ? ToWord : max_cha_p_l - 1); ++k) {
//                clipboard[index++] = book[i][j][k]; // Copy characters to clipboard
//            }
//        }
//    }
//    clipboard[index] = '\0'; // Null-terminate the clipboard buffer
//}
//void paste(char***& book, int& totalPages, char* clipboard, int atPage, int atLine, int afterWord)
//{
//    int clipboardSize = strlen(clipboard); // Get the size of the clipboard buffer
//    int index = 0;
//    // Loop through the pages, lines, and words to paste the clipboard content
//    for (int i = atPage; i < totalPages && index < clipboardSize; ++i) {
//        for (int j = atLine; j < max_l_p_page && index < clipboardSize; ++j) {
//            for (int k = afterWord; k < max_cha_p_l && index < clipboardSize; ++k) {
//                if (clipboard[index] != '\0') {
//                    book[i][j][k] = clipboard[index++]; // Paste characters from clipboard
//                }
//                else {
//                    break;
//                }
//            }
//            afterWord = 0; // After the first line, start from the beginning of the line
//        }
//        atLine = 0; // After the first page, start from the beginning of the page
//    }
//}
//void Delete(char***& book, int& totalPages, int page)
//{
//    // Check if the page index is valid
//    if (page < 0 || page >= totalPages)
//    {
//        cout << "Invalid page index to delete!" << endl;
//        return;
//    }
//
//    // Deallocate memory for the lines in the page
//    for (int line = 0; line < max_l_p_page; ++line)
//    {
//        delete[] book[page][line];
//    }
//
//    // Deallocate memory for the page itself
//    delete[] book[page];
//
//    // Shift the contents of the subsequent pages to fill the gap
//    for (int i = page; i < totalPages - 1; ++i)
//    {
//        book[i] = book[i + 1];
//    }
//
//    // Update totalPages
//    totalPages--;
//
//    cout << "Page " << page << " has been deleted." << endl;
//}
//void Delete(char***& book, int& totalPages, int page, int line)
//{
//    // Check if the page and line indices are valid
//    if (page < 0 || page >= totalPages || line < 0 || line >= max_l_p_page)
//    {
//        cout << "Invalid page or line index to delete!" << endl;
//        return;
//    }
//
//    // Deallocate memory for the line
//    delete[] book[page][line];
//
//    // Shift the contents of the subsequent lines to fill the gap
//    for (int i = line; i < max_l_p_page - 1; ++i)
//    {
//        book[page][i] = book[page][i + 1];
//    }
//
//    // Allocate memory for the last line to ensure it is not dangling
//    book[page][max_l_p_page - 1] = new char[max_cha_p_l + 1];
//    book[page][max_l_p_page - 1][0] = '\0'; // Null-terminate the last line
//
//    cout << "Line " << line << " on page " << page << " has been deleted." << endl;
//}
////void DeleteText(char***& book, int& totalPages, char* text) //For text deletion
////{
////
////}
//
//void insert(char***& book, int& totalPages, int position) // insert empty page after position
//{
//    // Check if the position is valid
//    if (position < 0 || position > totalPages) {
//        cout << "Invalid position to insert page!" << endl;
//        return;
//    }
//
//    // Allocate memory for the new page
//    char*** newBook = new char** [totalPages + 1];
//    for (int i = 0; i < position; ++i) {
//        newBook[i] = book[i];
//    }
//    newBook[position] = new char* [max_l_p_page];
//    //for (int i = 0; i < max_l_p_page; ++i) {
//    //    newBook[position][i] = new char[max_cha_p_l + 1]; // +1 for null terminator
//    //    strcpy(newBook[position][i], "New page content.");
//    //}
//    for (int i = position; i < totalPages; ++i) {
//        newBook[i + 1] = book[i];
//    }
//
//    // Deallocate memory for the old book
//    delete[] book;
//
//    // Update book to point to the new book
//    book = newBook;
//    totalPages++;
//
//    cout << "Page inserted at position " << position << "." << endl;
//}
//void insert(char***& book, int& totalPages, int page, int position) // insert empty line on page
//{
//    // Check if the page index and position are valid
//    if (page < 0 || page >= totalPages || position < 0 || position > max_l_p_page) {
//        cout << "Invalid page index or position to insert lines!" << endl;
//        return;
//    }
//
//    // Shift the lines after the insertion point
//    for (int i = max_l_p_page - 1; i > position; --i) {
//        book[page][i] = book[page][i - 1];
//    }
//
//    // Allocate memory for the new line(s)
//    //book[page][position] = new char[max_cha_p_l + 1]; // +1 for null terminator
//    //strcpy(book[page][position], "New line content.");
//
//    cout << "Line(s) inserted at position " << position << " on page " << page << "." << endl;
//}
//
//void insertText(char***& book, int& totalPages, int page, int line, int word, char* text) // Insert text after the word.
//{
//    // Check if the page index, line index, and position are valid
//    if (page < 0 || page >= totalPages || line < 0 || line >= max_l_p_page || word < 0 || word > max_cha_p_l) {
//        cout << "Invalid page, line, or position to insert text!" << endl;
//        return;
//    }
//
//    // Get the pointer to the line
//    char* currentLine = book[page][line];
//
//    // Calculate the length of the current line
//    int currentLength = strlen(currentLine);
//
//    // Calculate the length of the new text
//    int newLength = strlen(text);
//
//    // Shift the characters after the insertion point
//    for (int i = currentLength; i >= word; --i) {
//        currentLine[i + newLength] = currentLine[i];
//    }
//
//    // Copy the new text into the line at the specified position
//    //strncpy(currentLine + word, text, newLength);
//
//    cout << "Text inserted at position " << word << " on page " << page << ", line " << line << "." << endl;
//}
////void removeDoubleSpaces(char***& book, int& totalPages)
////{
////
////}
//
////void concatenateBooks(char***& book1, int totalPages1, char***& book2, int totalPages2, char***& newBook, int& newPages)
////{
////
////}
//
//char* toString(char***& book, int totalPages) //return book with format given below
//{
//    // Implementation for converting book to string
//    char* str = new char[1];
//    str[0] = '\0';
//    return str;
//}

//----------------------- Q3 -----------------------
bool royalHarmony(int**& board, int row, int column, int queens)
{

    if (queens == 0)
    {
        return true;
    }
    if (row >= column)
    {
        return false;
    }
    for (int i = 0; i < column; i++)
    {
        if (board[row][i] == 0)
        {
            board[row][i] = 1;
            for (int j = row + 1; j < column; j++)
            {
                board[j][i] = -1;
                if (i - (j - row) >= 0)
                {
                    board[j][i - (j - row)] = -1;
                }
                if (i + (j - row) < column)
                {
                    board[j][i + (j - row)] = -1;
                }
            }
            if (royalHarmony(board, row + 1, column, queens - 1))
            {
                return true;
            }
            board[row][i] = 0;
            for (int j = row + 1; j < column; j++)
            {
                board[j][i] = 0;
                if (i - (j - row) >= 0)
                {
                    board[j][i - (j - row)] = 0;
                }
                if (i + (j - row) < column)
                {
                    board[j][i + (j - row)] = 0;
                }
            }
        }
    }
    return false;
}
//----------------------- Q4 -----------------------

void RecursivePattern1(int start, int end);
void printHash(int print)
{
    if (print == 0)
        return;
    cout << "#";
    printHash(print - 1);
}
void printSpace(int n)
{
    if (n == 0)
        return;
    cout << " ";
    printSpace(n - 1);
}

void PrintPattern_1(int end, int start)
{
    if (start == end - 1) {
        return;
    }
    printSpace(start);
    cout << "#";
    if (start == end - 1) {
        cout << "#";
    }
    cout << endl;
    PrintPattern_1(end, start + 2);


}
void PrintPatternMain1(int start, int end)
{
    int star = end;
    if (end == 0)
        return;
    printSpace(end - 2);
    printHash(star - end + 1);
    cout << endl;
    PrintPatternMain1(star, end - 2);
}
void RecursivePattern1(int start, int end)
{
    start = end;
    if (end == 0) //base condition
        return;
    printSpace(end - 2);
    printHash(start - end + 1);
    cout << endl;
    PrintPatternMain1(start, end - 2);
    if (end == start) { //start the 2nd Part of the pattern
        start = 1;
        PrintPattern_1(end, start);
    }

}

void RecursivePattern2(int n1, int n2);
void printspaces(int num)
{
    // base case
    if (num == 0)
        return;
    cout << " ";

    // recursively calling printn()
    printspaces(num - 1);
}
void printspaces2(int n)
{
    if (n == 0)
        return;
    cout << " ";
    printspaces2(n - 1);
}
void printstars2(int num)
{
    // base case
    if (num == 0)
        return;
    cout << "*";

    // recursively calling printn()
    printstars2(num - 1);
}
void printstars(int n)
{
    if (n == 0)
        return;
    cout << "*";
    printstars(n - 1);
}

void printHollowDiamondMain2(int n, int p)
{
    int j = 1;
    int k = 0;
    int num = n;
    //int num = n;
    if (n == 0)
        return;
    printstars2(p - n + 1);
    printspaces2(n); printspaces2(n - 1);
    printstars2(p - n + 1);
    cout << endl;
    printHollowDiamondMain2(n - 1, p);
}
void printHollowDiamondMain(int n, int p)
{
    int j = 1;
    int k = 0;
    int num = n;
    //int num = n;
    if (n == 0)
        return;
    printstars(n);
    printspaces(p - n + 1); printspaces(p - n);
    printstars(n);
    cout << endl;
    printHollowDiamondMain(n - 1, p);
}

void printline(int n)
{
    if (n == 0)
        return;
    cout << "*";
    printline(n - 1);
}
void RecursivePattern2(int n) //start 1, end 16
{
    int i = n;
    int j = 1;
    int k = 0;
    int num = n;
    if (i == 0)
        return;
    printline(n * 2 + 1);
    cout << endl;
    printHollowDiamondMain(n, n);
    printHollowDiamondMain2(n, n);
    printline(n * 2 + 1);
    cout << endl;


}


void RecursivePattern3(int n1, int n2);
void printHash2(int print)
{
    if (print == 0)
        return;
    cout << " #";
    printHash2(print - 1);
}

void printSpace2(int n)
{
    if (n == 0) {
        return;
    }
    cout << "  ";
    printSpace2(n - 1);
}
void printdot(int n)
{
    if (n == 0) {
        cout << " .";
        return;
    }
    cout << " .";
    printdot(n - 1);
}

void printstars3(int num, int n)
{
    if (num == n)
        return;
    cout << " *";

    printstars3(num - 1, n);
}
void printspace4(int num)
{

    if (num == 0)
        return;
    cout << "  ";
    printspace4(num - 1);
}

void printstars4(int num)
{
    if (num == 1)
        return;
    cout << " *";
    printstars4(num - 1);
}

void markhalf(int print)
{
    if (print == 0)
        return;
    cout << " |";
    markhalf(print - 1);
}
void PrintPattern2Low(int n, int num, int size)
{
    if (n == 1) {
        return;
    }
    printspace4(size - n + 1);

    printHash2(1);
    printdot(size - n + 1);
    printstars4(n - 1);
    printstars4(n - 1);
    markhalf(1);
    printstars4(n - 1);
    printstars4(n - 1);
    printdot(size - n + 1);
    printHash2(1);

    cout << endl;
    PrintPattern2Low(n - 1, num + 1, size);

}
void RecursivePattern3(int n, int num)
{
    if (n == 0) {
        PrintPattern2Low(num / 2, num / 2, num / 2); //after the first part ends, the value of n & num switches
        return;
    }
    printSpace2(n - 1);
    printHash2(1);
    printdot(n - 1);
    printstars3(num, n);
    markhalf(1);
    printstars3(num, n);
    printdot(n - 1);
    printHash2(1);
    cout << endl;
    RecursivePattern3(n - 1, num + 1);
}




//----------------------- Q5 -----------------------

struct SavingAccount
{

    char* name;
    float annualInterestRate;
    double savingBalance;
    char* accountNum;
};
void OpenCustomerAccount(SavingAccount* savers[], int& accountsOpen, char* name, float interestRate, double balance) // a function to create a new account and assign it an account number.
{
    SavingAccount* newAccount = new SavingAccount;
    (*newAccount).name = name;
    (*newAccount).annualInterestRate = interestRate;
    (*newAccount).savingBalance = balance;
    char accountNumber[4];
    accountNumber[0] = 'S';
    accountNumber[1] = 'A';
    accountNumber[2] = '0' + (accountsOpen / 10);
    accountNumber[3] = '0' + (accountsOpen % 10);
    (*newAccount).accountNum = new char[4];
    for (int i = 0; i < 4; i++)
    {
        (*newAccount).accountNum[i] = accountNumber[i];
    }
    savers[accountsOpen] = newAccount;
    accountsOpen++;
}

float calculateMonthlyInterest(SavingAccount* saver) // that calculates the monthly interest by multiplying the balance by annualInterestRate divided by 12
{
    return ((*saver).savingBalance * (*saver).annualInterestRate) / 12;
}

void modifyInterestRate(SavingAccount* saver, float newValue)
{
    saver->annualInterestRate = newValue;
}

int SearchCustomer(SavingAccount* savers[], int accountsOpen, char* accountNum) // a function that searches for an account using an account number. If the customer is found it returns the array index otherwise return -1
{
    for (int i = 0; i < accountsOpen; i++)
    {
        int j;
        for (j = 0; j < 4 && (*savers[i]).accountNum[j] != '\0' && accountNum[j] != '\0'; j++)
        {
            if ((*savers[i]).accountNum[j] != accountNum[j])
            {
                break;
            }
        }
        if (j == 4 && (*savers[i]).accountNum[j] == '\0' && accountNum[j] == '\0')
        {
            return i;
        }
    }
    return -1;
}

bool UpdateAccountBalance(SavingAccount* savers[], int accountsOpen, char* accountNumVal, double balanceVal) // a function that updates a customer’s balance
{
    int index = SearchCustomer(savers, accountsOpen, accountNumVal);
    if (index != -1)
    {
        (*savers[index]).savingBalance = balanceVal;
        return true;
    }
    return false;
}
