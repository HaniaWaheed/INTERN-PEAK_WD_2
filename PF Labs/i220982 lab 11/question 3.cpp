#include <iostream>

using namespace std;

// Function to calculate sum of all elements in the array
int calculateSum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// Function to display maximum value occurred in the array
void displayMax(int arr[], int size) {
    int max = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    cout << "Maximum value in the array is: " << max << endl;
}

int main() {
    int arr1[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int arr2[3][3] = { {1, 2, 3}, {4, 3, 6}, {7, 8, 3} };

    // Calculate sum of elements in arr1
    int sum1 = calculateSum(*arr1, 9);
    cout << "Sum of elements in arr1 is: " << sum1 << endl;

    // Display maximum value in arr2
    displayMax(*arr2, 9);

    return 0;
}
