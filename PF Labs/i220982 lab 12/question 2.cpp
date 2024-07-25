#include <iostream>
using namespace std;

void Fabinoccian_Series(int n, int t1=0, int t2=1, int nextTerm=0)
{
    for (int i = 1; i <= n; ++i) {
        // Prints the first two terms.
        if (i == 1) {
            cout << t1 << ", ";
            continue;
        }
        if (i == 2) {
            cout << t2 << ", ";
            continue;
        }
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;

        cout << nextTerm << ", ";
    }
}

int main()
{
int n;
int t1 = 0; int t2 = 1; int nextTerm = 0;

    cout << "Enter the number of terms: ";
    cin >> n;

    cout << "Fibonacci Series: ";
    Fabinoccian_Series(n, t1, t2, nextTerm);

    return 0;
}
