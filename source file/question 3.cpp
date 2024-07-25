#include <iostream>
#include"Header.h"


int main() {
    const int size = 8;
    int arr[] = { 6, 3, 1, 2, 7, 5, 9, 4 };

    std::cout << "Original Array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }

    int* sortedArr = sortArray(arr, size);

    std::cout << "\nSorted Array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << sortedArr[i] << " ";
    }

    return 0;
}
