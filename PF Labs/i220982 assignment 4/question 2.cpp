//Hania Waheed
//Roll Number: 22i-0982
//Section: F

//Main Library
#include <iostream> 
#include <iomanip> 

using namespace std; 

//User Function:

bool isPerfect(int number) 
{ 
	// Inputs

	int sumOfDivisors = 1;   
	//Iteration Loop

	for (int i = 2; i <= number / 2; i++)  
	{
		if ((number % i) == 0)
		{
			sumOfDivisors += i;
		}
	}
	return (sumOfDivisors == number);
}

//Main Function:

int main()
{
	cout << "Perfect numbers between 1 and 1000" << endl; 
	
	//Iteration Loop
	for (int number = 1; number <= 1000; number++) 	
	{
		if (isPerfect(number)) 
		{
			cout << setw(8) << number << " = " << setw(5) << "1"; 	
			for (int i = 2; i <= number / 2; i++)  			
			{
				if ((number % i) == 0)
				{
					cout << " + " << setw(5) << i;
				}
			}
			cout <<endl;
		}
	}
	return 0;
}

//End of program