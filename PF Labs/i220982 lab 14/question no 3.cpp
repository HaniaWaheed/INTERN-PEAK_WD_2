#include <iostream>

using namespace std;

int Adder(int* arr_ptr, int size) 
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += *(arr_ptr + i);
    }
    return sum;
}

int main() 
{
    srand(time(nullptr)); 

    const int size = 5;
    int arr[size];
    for (int i = 0; i < size; i++) 
    {
        arr[i] = rand() % 10; 
    }

    int* arr_ptr = arr; 
    cout << "Array: ";
    for (int i = 0; i < size; i++) 
    {
        cout << arr[i] << " "; 
    }
    cout << endl;

    int sum = Adder(arr_ptr, size);

    cout << "Sum: " << sum << endl;

    return 0;
}
