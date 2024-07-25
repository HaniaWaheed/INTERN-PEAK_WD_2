/* Hania Waheef
roll no: 22i-0982
Section C
*/

#include <iostream>
#include<cstring>

using namespace std;

class BigNumber
{
private:
    char number[10000]; 
    bool isNegative;

    int Lenght(const char* str) const
    {
        int length = 0;
        while (str[length] != '\0')
        {
            length++;
        }
        return length;
    }

    void Copy(char* dest, const char* src) const 
    {
        int i = 0;
        while (src[i] != '\0') 
        {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }

    void Move(char* dest, const char* src, int length) const 
    {
        if (dest < src)
        {
            for (int i = 0; i < length; i++)
            {
                dest[i] = src[i];
            }
        }
        else {
            for (int i = length - 1; i >= 0; i--) 
            {
                dest[i] = src[i];
            }
        }
        dest[length] = '\0';
    }

    int compare(const BigNumber& other) const 
    {
        int len1 = Lenght(number);
        int len2 = Lenght(other.number);

        if (len1 > len2)
        {
            return 1;
        }
        if (len1 < len2)
        {
            return -1;
        }

        for (int i = 0; i < len1; i++) 
        {
            if (number[i] > other.number[i])
            {
                return 1;
            }
            if (number[i] < other.number[i])
            {
                return -1;
            }
        }
        return 0;
    }

    void subtractInternal(const BigNumber& other, BigNumber& result) const
    {
        int len1 = Lenght(number);
        int len2 = Lenght(other.number);
        int borrow = 0;

        for (int i = 0; i < len1; i++) 
        {
            int diff = (number[len1 - 1 - i] - '0') - (i < len2 ? other.number[len2 - 1 - i] - '0' : 0) - borrow;
            if (diff < 0)
            {
                diff += 10;
                borrow = 1;
            }
            else 
            {
                borrow = 0;
            }
            result.number[len1 - 1 - i] = diff + '0';
        }

        int start = 0;
        while (start < len1 && result.number[start] == '0') 
        {
            start++;
        }

        if (start == len1) 
        {
            result.number[0] = '0';
            result.number[1] = '\0';
        }
        else
        {
            Move(result.number, result.number + start, len1 - start);
        }
    }

public:

    BigNumber(const char* num)
    {
        isNegative = false;
        if (num[0] == '-')
        {
            isNegative = true;
            Copy(number, num + 1);
        }
        else 
        {
            Copy(number, num);
        }
    }

    BigNumber(long long num) 
    {
        isNegative = num < 0;
        if (isNegative) 
        {
            num = -num;
        }

        int i = 0;
        while (num > 0) 
        {
            number[i++] = (num % 10) + '0';
            num /= 10;
        }
        number[i] = '\0';

        for (int j = 0; j < i / 2; j++)
        {
            swap(number[j], number[i - j - 1]);
        }
    }

    BigNumber() : isNegative(false) 
    {
        number[0] = '0';
        number[1] = '\0';
    }

    void add(const BigNumber& other, BigNumber& result) const 
    {
        result.isNegative = false; 

        int len1 = Lenght(number);
        int len2 = Lenght(other.number);
        int maxLength = len1 > len2 ? len1 : len2;

        int carry = 0;
        int i = len1 - 1, j = len2 - 1, k = maxLength;
        result.number[k + 1] = '\0';

        while (i >= 0 || j >= 0 || carry)
        {
            int sum = carry;
            if (i >= 0)
            {
                sum += number[i--] - '0';
            }
            if (j >= 0)
            {
                sum += other.number[j--] - '0';
            }

            result.number[k--] = (sum % 10) + '0';
            carry = sum / 10;
        }

        if (k == 0)
        {
            Move(result.number, result.number + 1, maxLength + 1);
        }
    }

    void addLL(long long other, BigNumber& result) const 
    {
        BigNumber otherBN(other);
        add(otherBN, result);
    }

    void addStr(const std::string& other, BigNumber& result) const 
    {
        BigNumber otherBN(other.c_str());
        add(otherBN, result);
    }

    void subtract(const BigNumber& other, BigNumber& result) const
    {
        if (compare(other) < 0)
        {
            std::cerr << "Subtraction results in a negative number, which is not handled in this implementation." << std::endl;
            return;
        }
        result.isNegative = false;
        subtractInternal(other, result);
    }

    void subtractLL(long long other, BigNumber& result) const 
    {
        BigNumber otherBN(other);
        subtract(otherBN, result);
    }

    void subtractStr(const std::string& other, BigNumber& result) const 
    {
        BigNumber otherBN(other.c_str());
        subtract(otherBN, result);
    }

    void multiply(const BigNumber& other, BigNumber& result) const 
    {
        int len1 = Lenght(number);
        int len2 = Lenght(other.number);
        int maxLength = len1 + len2;

        int tempResult[2000] = { 0 };

        for (int i = len1 - 1; i >= 0; i--)
        {
            for (int j = len2 - 1; j >= 0; j--)
            {
                int mul = (number[i] - '0') * (other.number[j] - '0');
                int sum = tempResult[i + j + 1] + mul;
                tempResult[i + j + 1] = sum % 10;
                tempResult[i + j] += sum / 10;
            }
        }

        int k = 0;
        while (k < maxLength && tempResult[k] == 0)
        {
            k++;
        }

        int index = 0;
        while (k < maxLength)
        {
            result.number[index++] = tempResult[k++] + '0';
        }
        result.number[index] = '\0';

        if (index == 0)
        {
            result.number[0] = '0';
            result.number[1] = '\0';
        }
    }

    void multiplyLL(long long other, BigNumber& result) const
    {
        BigNumber otherBN(other);
        multiply(otherBN, result);
    }

    void multiplyStr(const string& other, BigNumber& result) const
    {
        BigNumber otherBN(other.c_str());
        multiply(otherBN, result);
    }

    void divide(const BigNumber& other, BigNumber& result) const
    {
        if (compare(other) < 0)
        {
            result.number[0] = '0';
            result.number[1] = '\0';
            return;
        }

        BigNumber temp;
        Copy(temp.number, number);
        int len1 = Lenght(number);
        int len2 = Lenght(other.number);
        int k = len1 - len2;
        result.number[k + 1] = '\0';

        BigNumber divisor;
        Copy(divisor.number, other.number);
        Move(divisor.number + k, divisor.number, len2 + 1);

        while (k >= 0)
        {
            int count = 0;
            while (temp.compare(divisor) >= 0) 
            {
                temp.subtractInternal(divisor, temp);
                count++;
            }
            result.number[k] = count + '0';
            Move(divisor.number + 1, divisor.number, len2 + 1);
            divisor.number[0] = '0';
            k--;
        }
        result.number[len1 - len2 + 1] = '\0';

        int start = 0;
        while (start < len1 - len2 + 1 && result.number[start] == '0') 
        {
            start++;
        }
        if (start == len1 - len2 + 1) 
        {
            result.number[0] = '0';
            result.number[1] = '\0';
        }
        else
        {
            Move(result.number, result.number + start, len1 - len2 + 2 - start);
        }
    }

    void divideLL(long long other, BigNumber& result) const 
    {
        BigNumber otherBN(other);
        divide(otherBN, result);
    }

    void divideStr(const string& other, BigNumber& result) const 
    {
        BigNumber otherBN(other.c_str());
        divide(otherBN, result);
    }

    void print() const 
    {
        if (isNegative) 
        {
           cout << '-';
        }
       cout << number << endl;
    }
};

int main() 
{
    char num1[1000];
    char num2[1000];

    cout << "Enter the first big number: ";
    cin >> num1;
    cout << "Enter the second big number: ";
    cin >> num2;

    BigNumber bigNum1(num1);
    BigNumber bigNum2(num2);
    BigNumber result;

    bigNum1.add(bigNum2, result);
    cout << "Sum: ";
    result.print();

    long long num3;
    cout << "Enter a long long number for addition: ";
    cin >> num3;
    bigNum1.addLL(num3, result);
    cout << "Sum with long long: ";
    result.print();

    string num4;
    cout << "Enter a string number for addition: ";
    cin >> num4;
    bigNum1.addStr(num4, result);
    cout << "Sum with string: ";
    result.print();

    bigNum1.multiply(bigNum2, result);
    cout << "Product: ";
    result.print();

    cout << "Enter a long long number for multiplication: ";
    cin >> num3;
    bigNum1.multiplyLL(num3, result);
    cout << "Product with long long: ";
    result.print();

    cout << "Enter a string number for multiplication: ";
    cin >> num4;
    bigNum1.multiplyStr(num4, result);
    cout << "Product with string: ";
    result.print();

    bigNum1.divide(bigNum2, result);
    cout << "Quotient: ";
    result.print();

    cout << "Enter a long long number for division: ";
    cin >> num3;
    bigNum1.divideLL(num3, result);
    cout << "Quotient with long long: ";
    result.print();

    cout << "Enter a string number for division: ";
    cin >> num4;
    bigNum1.divideStr(num4, result);
    cout << "Quotient with string: ";
    result.print();

    return 0;
}
