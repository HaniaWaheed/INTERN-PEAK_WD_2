#pragma once

void bubbleSort(int* arr, int size)
{
    for (int i = 0; i < size - 1; ++i) 
    {
        for (int j = 0; j < size - i - 1; ++j) 
        {
            if (arr[j] % 2 != 0 && arr[j + 1] % 2 != 0 && arr[j] > arr[j + 1]) 
            {
                // Swap odd values if they are out of order
                std::swap(arr[j], arr[j + 1]);
            }
            else if (arr[j] % 2 == 0 && arr[j + 1] % 2 == 0 && arr[j] > arr[j + 1]) 
            {
                // Swap even values if they are out of order
                std::swap(arr[j], arr[j + 1]);
            }
            else if (arr[j] % 2 != 0 && arr[j + 1] % 2 == 0) {
                // Swap odd and even values to sort odd values first
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int* sortArray(int* arr, int size) {
    bubbleSort(arr, size);
    return arr;
}