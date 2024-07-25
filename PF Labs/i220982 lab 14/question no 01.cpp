#include <iostream>

using namespace std;

int main() 
{
	int num = 42; 
	int* ptr = &num; 
	cout << "Value of num: " << num << endl; 
	cout << "Address of ptr: " << ptr << endl; 

	return 0;
}
