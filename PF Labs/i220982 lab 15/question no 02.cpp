#include <iostream>
using namespace std;

int main() {
	int* myInt = new int; 
	*myInt = 42; 
	cout << "The value of myInt is: " << *myInt << endl; 
	delete myInt; 
	return 0;
}
