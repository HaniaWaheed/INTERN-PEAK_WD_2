#include <iostream>
#include"Header.h"

const int SENTINEL = -1;
const int INITIAL_CAPACITY = 5; 


int main()
{
    int capacity = INITIAL_CAPACITY;
    int* dynamicArray = new int[capacity];
    int size = 0;

    std::cout << "Enter integers (enter -1 to stop):" << std::endl;

    int userInput;
    while (true)
    {
        std::cin >> userInput;

        if (userInput == SENTINEL) 
        {
            break;
        }
        if (size == capacity) 
        {
            dynamicArray = resizeArray(dynamicArray, capacity);
        }
        dynamicArray[size] = userInput;
        size++;
    }

    std::cout << "Entered integers:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << dynamicArray[i] << " ";
    }
    delete[] dynamicArray;

    return 0;
}
