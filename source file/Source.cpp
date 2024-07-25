#include <iostream>
#include"Header.h"

using namespace std;

int main() {
    const int size = 8;
    int arr[] = { 6, 3, 1, 2, 7, 5, 9, 4 };

    cout << "Original Array: " << endl;
    for (int i = 0; i < size; ++i) 
    {
        cout << arr[i] << " ";
    }

    int* sortedArr = sortArray(arr, size);

    cout << "\nSorted Array: "<<endl;
    for (int i = 0; i < size; ++i)
    {
        cout << sortedArr[i] << " "<<endl;
    }

    return 0;
}
