#include <iostream>

using namespace std;

int main()
{
	int num = 24;
	char letter = 'd';
	float decimal = 5.67;

	int* num_ptr = &num;
	char* letter_ptr = &letter;
	float* decimal_ptr = &decimal;

	cout << "Values: " << num << ", " << letter << ", " << decimal << endl;
	cout << "Pointers: " << num_ptr << ", " << static_cast<void*>(letter_ptr) << ", " << decimal_ptr << endl;
	cout << "Addresses: " << &num << ", " << static_cast<void*>(&letter) << ", " << &decimal << endl;
	cout << "Sizes: " << sizeof(num) << ", " << sizeof(letter) << ", " << sizeof(decimal) << endl;
	cout << "Pointer Sizes: " << sizeof(num_ptr) << ", " << sizeof(letter_ptr) << ", " << sizeof(decimal_ptr) << endl;
	return 0;
}
