#include <iostream>

using namespace std;

void Swaply(int& num1, int* num2, int product) 
{
	int temp = num1; 
	num1 = *num2; 
	*num2 = temp; 
	product = (num1 / 10) * (*num2 / 10);

	cout << "Inside Swaply function:" << endl;
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << *num2 << endl;
}

int main()
{
	int num1 = 23;
	int num2 = 54;
	int product = 0;

	cout << "Before Swaply function:" << endl;
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;
	cout << "product = " << product << endl;

	Swaply(num1, &num2, product);

	cout << "After Swaply function:" << endl;
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;

	return 0;
}
