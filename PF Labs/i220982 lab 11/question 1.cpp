#include<iostream>

using namespace std;

void swap(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
    cout << "After  swapping." << endl;
    cout << "a = " << a << " b = " << b << endl;
}
int main()
{
    int m;
    int n;
    cout << "Enter the value of m" << endl;
    cin >> m;
    cout << "enter the value of n" << endl;
    cin >> n;
    cout << "Before swapping." << endl;
    cout << "m = " << m << " n = " << n << endl;
    swap(m, n);
    return 0;
}