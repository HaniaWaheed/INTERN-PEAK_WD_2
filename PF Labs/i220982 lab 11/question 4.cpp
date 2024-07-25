#include <iostream>

using namespace std;
int sum_of_digit(int n, int val)
{
	if (n < 10) 
	{
		val = val + n;
		return val;
	}
	return sum_of_digit(n / 10, (n % 10) + val);
}

// Driver code
int main()
{
	int num ;
	int result;

	cout << "Enter the number " << endl;
	cin >> num;
	 result = sum_of_digit(num, 0);
	cout << "Sum of digits is " << result;
	return 0;
}
