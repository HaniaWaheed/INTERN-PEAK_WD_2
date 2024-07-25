#include <iostream>
#include"Header.h"

int main() {
    int arr[] = { 1, 2, 3, 4, 5, 6 };
    int sizeofArray = sizeof(arr) / sizeof(arr[0]);
    int n = 2;
    int m = 2;
    int* result = rotateArray(arr, sizeofArray, n, m);

    for (int i = 0; i < sizeofArray; i++) {
        std::cout << result[i] << " ";
    }

    delete[] result;  // free the memory allocated for result
    return 0;
}