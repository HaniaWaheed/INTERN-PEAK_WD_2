#include <iostream>

using namespace std;

int power(int x, int n)
{
	if (n == 0)
		return 1;
	if (x == 0)
		return 0;
	return x * power(x, n - 1);
}
int main()
{
	int x ;
	int n ;

	cout << "Enter the value of x" << endl;
	cin >> x;
	cout << "Enter the value i.e power of y" << endl;
	cin >> n;
	cout << (power(x, n));
	return 0;
}
