#include <iostream>
#include <string>

using namespace std;

class conversion
{
private:
    string conversionString;
    int base;
    int decimalValue;

    int binaryToDecimal(const string& binary) const
    {
        int decimal = 0;
        int power = 1;
        for (int i = binary.size() - 1; i >= 0; --i)
        {
            if (binary[i] == '1') 
            {
                decimal += power;
            }
            power *= 2;
        }
        return decimal;
    }

    string decimalToBinary(int decimal) const 
    {
        if (decimal == 0)
        {
            return "0";
        }
        string binary = "";
        while (decimal > 0) 
        {
            binary = (decimal % 2 == 0 ? "0" : "1") + binary;
            decimal /= 2;
        }
        return binary;
    }

    void convertToBase2() 
    {
        if (base != 2) 
        {
            decimalValue = stoi(conversionString, nullptr, base);
            conversionString = decimalToBinary(decimalValue);
            base = 2;
        }
        else 
        {
            decimalValue = binaryToDecimal(conversionString);
        }
    }

public:
    conversion(string conversionStr, int base = 2) : conversionString(conversionStr), base(base) {
        convertToBase2();
    }

    conversion operator+(const conversion& other) const {
        int result = decimalValue + other.decimalValue;
        return conversion(decimalToBinary(result), 2);
    }

    conversion operator-(const conversion& other) const {
        int result = decimalValue - other.decimalValue;
        return conversion(decimalToBinary(result), 2);
    }
    conversion& operator+=(const conversion& other) {
        decimalValue += other.decimalValue;
        conversionString = decimalToBinary(decimalValue);
        return *this;
    }

    conversion& operator-=(const conversion& other) {
        decimalValue -= other.decimalValue;
        conversionString = decimalToBinary(decimalValue);
        return *this;
    }

    conversion operator*(const conversion& other) const {
        int result = decimalValue * other.decimalValue;
        return conversion(decimalToBinary(result), 2);
    }

    conversion operator/(const conversion& other) const {
        int result = decimalValue / other.decimalValue;
        return conversion(decimalToBinary(result), 2);
    }

    conversion operator%(const conversion& other) const {
        int result = decimalValue % other.decimalValue;
        return conversion(decimalToBinary(result), 2);
    }

    conversion operator|(const conversion& other) const {
        int result = decimalValue | other.decimalValue;
        return conversion(decimalToBinary(result), 2);
    }

    conversion operator^(const conversion& other) const {
        int result = decimalValue ^ other.decimalValue;
        return conversion(decimalToBinary(result), 2);
    }

    conversion operator&(const conversion& other) const {
        int result = decimalValue & other.decimalValue;
        return conversion(decimalToBinary(result), 2);
    }

    conversion operator!() const {
        int result = ~decimalValue + 1;
        return conversion(decimalToBinary(result), 2);
    }

    conversion operator~() const {
        int result = ~decimalValue;
        return conversion(decimalToBinary(result), 2);
    }

    conversion operator<<(int shiftAmount) const {
        int result = decimalValue << shiftAmount;
        return conversion(decimalToBinary(result), 2);
    }

    conversion operator>>(int shiftAmount) const {
        int result = decimalValue >> shiftAmount;
        return conversion(decimalToBinary(result), 2);
    }

    friend istream& operator>>(istream& input, conversion& other) {
        input >> other.conversionString >> other.base;
        other.convertToBase2();
        return input;
    }

    friend ostream& operator<<(ostream& output, const conversion& other) {
        output << "Binary: " << other.conversionString << " Decimal: " << other.decimalValue;
        return output;
    }
};

int main() {
    conversion c1("", 2); 
    conversion c2("", 2); 

    cout << "Enter the first binary number and its base (e.g., '1101 2'): ";
    cin >> c1;
    cout << "Enter the second binary number and its base (e.g., '101 2'): ";
    cin >> c2;

    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;

    conversion c3 = c1 + c2;
    cout << "c1 + c2: " << c3 << endl;

    c3 = c1 - c2;
    cout << "c1 - c2: " << c3 << endl;

    c3 = c1 * c2;
    cout << "c1 * c2: " << c3 << endl;

    c3 = c1 / c2;
    cout << "c1 / c2: " << c3 << endl;

    c3 = c1 % c2;
    cout << "c1 % c2: " << c3 << endl;

    c3 = c1 | c2;
    cout << "c1 | c2: " << c3 << endl;

    c3 = c1 ^ c2;
    cout << "c1 ^ c2: " << c3 << endl;

    c3 = c1 & c2;
    cout << "c1 & c2: " << c3 << endl;

    c3 = !c1;
    cout << "!c1: " << c3 << endl;

    c3 = ~c1;
    cout << "~c1: " << c3 << endl;

    c3 = c1 << 2;
    cout << "c1 << 2: " << c3 << endl;

    c3 = c1 >> 2;
    cout << "c1 >> 2: " << c3 << endl;

    return 0;
}
