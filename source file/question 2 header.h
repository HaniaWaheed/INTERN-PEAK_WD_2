#pragma once

using namespace std;
char printAndUpdatePointer(char* inputStr) 
{
    cout << inputStr[0] << " ";
    cout << "Pointer: " << static_cast<void*>(inputStr) << " ";
    cout << inputStr[19] << std::endl;
    inputStr += 2;
    cout << "Updated Pointer: " << static_cast<void*>(inputStr) << " ";
    cout << inputStr[0] << " " << inputStr[1] << std::endl;
    return inputStr[0];
}
