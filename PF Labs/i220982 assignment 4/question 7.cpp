//Hania Waheed
//Roll Number: 22i-0982
//Section: F

//Main library
#include<iostream>
using namespace std;

//Function Prototype
int Empty();
int Miss(int EmplCount);
double Average(int EmplCount, int Miss_Days);

//Main Function
int main()
{
	//Variable declare
	int EmplCount = Empty();
	int MissDays = Miss(EmplCount);
	cout << "The average  number of days absent is " << Average(EmplCount, MissDays);
}


//First Function
int Empty()
{
	//Variable Declare
	int num;

	//First Condition
	do
	{
		cout << "Please, enter the number of employees in company: ";
		cin >> num;
		//Second condition
		if (num < 1)
		{
			cout << "Incorrect number. Retry enter!" << endl;
		}
	}

	//Third Condition
	while (num < 1);
	{
		return num;
	}
}

//Second Program
int Miss(int EmplCount)
{
	//Variable declare
	int totalMiss = 0;

	//First Loop
	for (int i = 1; i <= EmplCount; i++)
	{
		int days;

		//Second iteration
		do
		{
			cout << "Enter the number of missed days during the past year for "
				<< "Employee " << i << ": " << endl;
			cin >> days;
			//First Condition
			if (days < 0)
			{
				cout << "Incorrect missed days. Retry enter!" << endl;
			}
			else
			{
				totalMiss += days;
			}
		}
		//Second condition
		while (days < 0);
	}
	return totalMiss;
}
//End of function

//Third Function
double Average(int EmplCount, int MissDays)
{
	//Variable declare
	double AvDays = (double)MissDays / EmplCount;
	return AvDays;
}
