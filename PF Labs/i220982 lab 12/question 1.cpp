#include<iostream>
using namespace std;

int area(int);
int area(int, int);
float area(float, float);
float area(float, float, float);
float area(float, int , float);
float area(int, float);
float area(float , int);

int main()
{
    int s, l, b;
    float r, bs, ht;
    float a;
    float ba, height;
    float perpendicular;
    int option;
    cout << "Enter side of a square:";
    cin >> s;
    cout << "Enter length and breadth of rectangle:";
    cin >> l;
    cin >> b;
    cout << "Enter base and height of triangle:";
    cin >> bs >> ht;
    cout << "Enter the side of trapezium" << endl;
    cin >> a;
    cin >> ba;
    cin >> height;
    cout << "Enter base, perpendicular  and height of parallelogram:";
    cin >> bs;
    cin >> perpendicular;
    cin >> ht;
    cout << "Enter the length and heigth of rhombus" << endl;
    cin >> l;
    cin >> height;
    cout << "Enter the length and height of kite" << endl;
    cin >> l;
    cin >> height;
    cout << "1. Area of square" << endl;
    cout << "2. Area of rectangle" << endl;
    cout << "3.Area of triangle" << endl;
    cout << "4. Area of trapezium" << endl;
    cout << "5. Area of parallelogram " << endl;
    cout << "6. Area of rhombus" << endl;
    cout << "7. Area of kite" << endl;
    cout << "Enter your option" << endl;
    cin >> option;
    while (option != 0)
    {
        switch (option)
        {
        case 1:
        {
            cout << "Area of square is" << area(s);
        }
        case 2:
        {
            cout << "\nArea of rectangle is " << area(l, ba);
        }
        case 3:
        {
            cout << "\nArea of triangle is " << area(bs, ht);
        }
        case 4:
        {
            cout << "Area of trapezium is " << area(a, ba, height) << endl;
        }
        case 5:
        {
            cout << "Area of parallelogram is" << area(bs, perpendicular, ht) << endl;
        }
        case 6:
        {
            cout << "Area of Rhombus is " << area(l, height) << endl;
        }
        case 7:
        {
            cout << "Area of kite is" << area(l, height) << endl;
        }
        default:
        {
            cout << "Invalid input" << endl;
        }
        cout << "1. Area of square" << endl;
        cout << "2. Area of rectangle" << endl;
        cout << "3.Area of triangle" << endl;
        cout << "4. Area of trapezium" << endl;
        cout << "5. Area of parallelogram " << endl;
        cout << "6. Area of rhombus" << endl;
        cout << "7. Area of kite" << endl;
        cin >> option;
        }
    }
}
int area(int s)
{
    return(s * s);
}
int area(int l, int ba)
{
    return(l * ba);
}
float area(float r)
{
    return(3.14 * r * r);
}
float area(float bs, float ht)
{
    return((bs * ht) / 2);
}
float area(float a, int ba, float height)
{
    return((a + ba) * height) / 2;
}
float area(float bs, float ht, float perpendicular)
{
    return (bs * ht * perpendicular);
}
float area(int l, float height)
{
    return((l * height) + 2);
}
float area(float l, int height)
{
    return ((l * height) + 2);
}
