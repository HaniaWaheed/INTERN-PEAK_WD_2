#pragma once
int* rotateArray(int* arr, int sizeofArray, int n, int m) {
    int* result = new int[sizeofArray];

    // divide array into m parts
    int partSize = sizeofArray / m;

    // shift elements of an array to the right n times
    n = n % sizeofArray;  // to handle cases where n is larger than sizeofArray

    for (int i = 0; i < sizeofArray; i++) {
        int newIndex = (i + n) % sizeofArray;
        int partNumber = newIndex / partSize;
        int newPartIndex = (newIndex % partSize) + partNumber * partSize;
        result[newPartIndex] = arr[i];
    }

    return result;
}