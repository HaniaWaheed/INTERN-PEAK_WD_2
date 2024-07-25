/* 
Hania Waheed
Roll number: 22i-0982
Section: c
*/
#include <iostream>

using namespace std;

class Rational 
{
private:
    int numerator;
    int denominator;

    void reduce()
    {
        int gcd = findGCD(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
        if (denominator < 0)
        {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    int findGCD(int a, int b) const 
    {
        if (b == 0)
        {
            return a;
        }
        return findGCD(b, a % b);
    }

public:
    Rational() : numerator(0), denominator(1) 
    {
    
    }

    Rational(int num, int denom) : numerator(num), denominator(denom) 
    {
        if (denom == 0) 
        {
            cout << "Error: Denominator cannot be zero. Setting to 1." << endl;
            denominator = 1;
        }
        reduce();
    }

    Rational(const Rational& other) : numerator(other.numerator), denominator(other.denominator)
    {
    
    }

    ~Rational()
    {
    
    }

    Rational operator+(const Rational& other) const
    {
        int num = numerator * other.denominator + other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Rational(num, denom);
    }

    Rational operator-(const Rational& other) const 
    {
        int num = numerator * other.denominator - other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Rational(num, denom);
    }

    Rational operator*(const Rational& other) const 
    {
        int num = numerator * other.numerator;
        int denom = denominator * other.denominator;
        return Rational(num, denom);
    }
  


    Rational operator/(const Rational& other) const 
    {
        if (other.numerator == 0) 
        {
            cout << "Error: Cannot divide by zero. Returning original value." << endl;
            return *this;
        }
        int num = numerator * other.denominator;
        int denom = denominator * other.numerator;
        return Rational(num, denom);
    }

    bool operator==(const Rational& other) const
    {
        return numerator == other.numerator && denominator == other.denominator;
    }

    bool operator!=(const Rational& other) const
    {
        return !(*this == other);
    }

    friend ostream& operator<<(ostream& os, const Rational& rational) 
    {
        os << rational.numerator << "/" << rational.denominator;
        return os;
    }

    friend istream& operator>>(istream& is, Rational& rational)
    {
        char choice;
        is >> rational.numerator >> choice >> rational.denominator;
        if (rational.denominator == 0) 
        {
            cout << "Error: Denominator cannot be zero. Setting to 1." << endl;
            rational.denominator = 1;
        }
        rational.reduce();
        return is;
    }

    void display() const
    {
        cout << numerator << "/" << denominator << endl;
    }
};

int main()
{
    Rational r1;
    Rational r2;

    cout << "ENter the value of rational 1" << endl;
    cin >> r1;
    cout << "ENter the value of rational 2" << endl;
    cin >> r2;

    Rational r3 = r1 + r2;
    r3.display(); 

    Rational r4 = r1 - r2;
    r4.display(); 

    Rational r5 = r1 * r2;
    r5.display(); 

    Rational r6 = r1 / r2;
    r6.display(); 

    cout << (r1 == r2) << endl; 
    cout << (r1 != r2) << endl; 

    return 0;
}
