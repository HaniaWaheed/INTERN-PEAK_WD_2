#include <iostream>

using namespace std;

class DynamicArray
{
private:
    int* data;
    int length;

public:
    DynamicArray(int size) : length(size)
    {
        data = new int[size]();
    }

    DynamicArray(const DynamicArray& other) : length(other.length)
    {
        data = new int[length];
        for (int i = 0; i < length; ++i)
        {
            data[i] = other.data[i];
        }
    }

    ~DynamicArray()
    {
        delete[] data;
    }

    int& operator[](int index)
    {
        if (index < 0 || index >= length)
        {
            cout << "Index out of range" << endl;
            exit(1);
        }
        return data[index];
    }

    const int& operator[](int index) const
    {
        if (index < 0 || index >= length)
        {
            cout << "Index out of range" << endl;
            exit(1); 
        }
        return data[index];
    }

    DynamicArray& operator=(const DynamicArray& other)
    {
        if (this == &other)
        {
            return *this;
        }
        delete[] data;
        length = other.length;
        data = new int[length];
        for (int i = 0; i < length; ++i)
        {
            data[i] = other.data[i];
        }
        return *this;
    }

    DynamicArray& operator+=(const DynamicArray& other)
    {
        if (length != other.length)
        {
            cout << "Arrays must be of the same size" << endl;
            exit(1); 
        }
        for (int i = 0; i < length; ++i)
        {
            data[i] += other.data[i];
        }
        return *this;
    }

    DynamicArray operator+(const DynamicArray& other) const
    {
        if (length != other.length)
        {
            cout << "Arrays must be of the same size" << endl;
            exit(1); 
        }
        DynamicArray result(length);
        for (int i = 0; i < length; ++i)
        {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    }

    friend ostream& operator<<(ostream& os, const DynamicArray& arr);

    int size() const
    {
        return length;
    }
};

ostream& operator<<(std::ostream& os, const DynamicArray& arr)
{
    os << "[";
    for (int i = 0; i < arr.length; ++i)
    {
        os << arr.data[i];
        if (i < arr.length - 1)
        {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

int main()
{
    int size;
    cout << "Enter the number of products: ";
    cin >> size;

    DynamicArray inventory1(size);
    DynamicArray inventory2(size);

    cout << "Enter quantities for inventory1:" << endl;
    for (int i = 0; i < size; ++i)
    {
        cout << "Product " << i + 1 << ": ";
        cin >> inventory1[i];
    }

    cout << "Enter quantities for inventory2:" << endl;
    for (int i = 0; i < size; ++i)
    {
        cout << "Product " << i + 1 << ": ";
        cin >> inventory2[i];
    }

    inventory1 += inventory2; 

    DynamicArray totalInventory = inventory1 + inventory2;

    cout << "Total Inventory: " << totalInventory << endl;

    cout << "Total products: " << totalInventory.size() << endl;

    return 0;
}
