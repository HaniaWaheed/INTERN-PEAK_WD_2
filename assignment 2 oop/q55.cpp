#include <iostream>
#include <string>

using namespace std;

class BigNumber {
public:
    BigNumber(string number);
    BigNumber(long long number);

    BigNumber add(BigNumber other);
    BigNumber subtract(BigNumber other);
    BigNumber multiply(BigNumber other);
    BigNumber divide(BigNumber other);

    string getString() const;

private:
    string numberString;

    string addStrings(const string& num1, const string& num2);
    string subtractStrings(const string& num1, const string& num2);
    string multiplyStrings(const string& num1, const string& num2);
    string divideStrings(const string& num1, const string& num2);
};

BigNumber::BigNumber(string number) : numberString(move(number)) {}

BigNumber::BigNumber(long long number) {
    numberString = to_string(number);
}

BigNumber BigNumber::add(BigNumber other) {
    string result = addStrings(numberString, other.numberString);
    return BigNumber(result);
}

BigNumber BigNumber::subtract(BigNumber other) {
    string result = subtractStrings(numberString, other.numberString);
    return BigNumber(result);
}

BigNumber BigNumber::multiply(BigNumber other) {
    string result = multiplyStrings(numberString, other.numberString);
    return BigNumber(result);
}

BigNumber BigNumber::divide(BigNumber other) {
    string result = divideStrings(numberString, other.numberString);
    return BigNumber(result);
}

string BigNumber::getString() const {
    return numberString;
}

string BigNumber::addStrings(const string& num1, const string& num2) {
    string result;
    int carry = 0;
    int maxLength = max(num1.size(), num2.size());

    for (int i = 0; i < maxLength || carry; ++i) {
        int digit1 = (i < num1.size()) ? num1[num1.size() - 1 - i] - '0' : 0;
        int digit2 = (i < num2.size()) ? num2[num2.size() - 1 - i] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        result = char(sum % 10 + '0') + result;
        carry = sum / 10;
    }

    return result;
}

string BigNumber::subtractStrings(const string& num1, const string& num2) {
    string result;
    int borrow = 0;
    int maxLength = max(num1.size(), num2.size());

    for (int i = 0; i < maxLength; ++i) {
        int digit1 = (i < num1.size()) ? num1[num1.size() - 1 - i] - '0' : 0;
        int digit2 = (i < num2.size()) ? num2[num2.size() - 1 - i] - '0' : 0;
        int diff = digit1 - digit2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        }
        else {
            borrow = 0;
        }
        result = char(diff + '0') + result;
    }

    // Trim leading zeros
    while (result.size() > 1 && result[0] == '0') {
        result = result.substr(1);
    }

    return result;
}

string BigNumber::multiplyStrings(const string& num1, const string& num2) {
    int maxLength = num1.size() + num2.size();
    int* result = new int[maxLength]();  // Allocate and initialize to 0

    for (int i = 0; i < num1.size(); ++i) {
        for (int j = 0; j < num2.size(); ++j) {
            result[i + j] += (num1[num1.size() - 1 - i] - '0') * (num2[num2.size() - 1 - j] - '0');
            result[i + j + 1] += result[i + j] / 10;
            result[i + j] %= 10;
        }
    }

    string resultStr;
    for (int i = 0; i < maxLength; ++i) {
        resultStr = char(result[i] + '0') + resultStr;
    }

    // Trim leading zeros
    while (resultStr.size() > 1 && resultStr[0] == '0') {
        resultStr = resultStr.substr(1);
    }

    delete[] result;  // Free allocated memory

    return resultStr;
}

string BigNumber::divideStrings(const string& num1, const string& num2) {
    if (num2 == "0") {
        return "Error: Division by zero";
    }
    if (num1 == "0" || num1.size() < num2.size() || (num1.size() == num2.size() && num1 < num2)) {
        return "0";
    }

    string quotient;
    string remainder = num1.substr(0, num2.size()); // Initial part of num1 to match num2 size
    int idx = num2.size(); // Index in num1 to append remainder digits

    while (idx <= num1.size()) {
        int count = 0;
        while (remainder >= num2) {
            remainder = subtractStrings(remainder, num2);
            count++;
        }
        quotient += to_string(count);

        if (idx < num1.size()) {
            remainder += num1[idx];
        }
        idx++;
    }

    // Trim leading zeros
    while (quotient.size() > 1 && quotient[0] == '0') {
        quotient = quotient.substr(1);
    }

    return quotient;
}

int main() {
    string input1, input2;

    cout << "Enter the first large number: ";
    cin >> input1;

    cout << "Enter the second large number: ";
    cin >> input2;

    BigNumber num1(input1);
    BigNumber num2(input2);

    BigNumber sum = num1.add(num2);
    BigNumber diff = num1.subtract(num2);
    BigNumber prod = num1.multiply(num2);
    BigNumber divide = num1.divide(num2);

    cout << "Sum: " << sum.getString() << endl;
    cout << "Difference: " << diff.getString() << endl;
    cout << "Product: " << prod.getString() << endl;
    cout << "Divide: " << divide.getString() << endl;

    return 0;
}
