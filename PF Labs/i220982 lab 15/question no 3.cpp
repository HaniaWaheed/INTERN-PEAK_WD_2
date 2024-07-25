#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int* arr = new int[n]; // dynamically allocate memory for an array of integers

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int max = arr[0]; // initialize the maximum element to the first element

    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    cout << "The largest element in the array is: " << max << endl;

    delete[] arr; // free the dynamically allocated memory

    return 0;
}
