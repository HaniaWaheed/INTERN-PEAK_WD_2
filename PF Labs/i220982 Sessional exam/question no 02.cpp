#include <iostream>
#include<algorithm>

using namespace std;

bool isRotatedSorted(int arr[], int n, int k)
{
    if (n == 0) 
    {
        return true;
    }
    int i = 0;
    for (; i < n - 1; i++) 
    {
        if (arr[i] > arr[i + 1])
        {
            break;
        }
    }
    if (i == n - 1)
    {
        return true;
    }
    rotate(arr, arr + i + 1, arr + n);
    return is_sorted(arr, arr + n);
}

int main()
{
    int arr[] = { 5, 6, 1, 2, 3, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    cout << isRotatedSorted(arr, n, k) << endl;
    return 0;
}
