#pragma once

//Function Calling
int myStrLen(char* str) 
{
    //Declare variable
    int length = 0;

    //first loop
    while (*str != '\0')
    {
        length++;
        str++;
    }
    return length;
}