#include <iostream>
using namespace std;

int global_var = 10; 

int sum_local_global(int local_var) 
{ 
    local_var += 5; 
    return global_var + local_var; 
}

int main()
{
    int local_var = 20;
    cout << "Before function call: " << endl;
    cout << "Local variable in main function: " << local_var << endl;
    cout << "Global variable: " << global_var << endl;

    int sum = sum_local_global(local_var); 
    cout << "After function call: " << endl;
    cout << "Local variable in main function: " << local_var << endl;
    cout << "Sum of local and global variables: " << sum << endl;

    return 0;
}
