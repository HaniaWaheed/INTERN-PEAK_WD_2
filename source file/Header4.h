#pragma once

int* resizeArray(int* arr, int& capacity) {
    capacity *= 2; // Double the capacity

    // Create a new dynamic array with the updated capacity
    int* newArr = new int[capacity];

    // Copy the elements from the old array to the new array
    for (int i = 0; i < capacity / 2; ++i) {
        newArr[i] = arr[i];
    }

    // Deallocate memory for the old array
    delete[] arr;

    return newArr;
}