/*
Hania Waheed
Roll Number: 22i-0982
Section: C
*/

#include <iostream>
#include <string>
#include <cstdlib> 

using namespace std;

class Car {
private:
    string name;
    string dateCrawled;
    string sellerType;
    string offerType;
    double price;
    string abTestInfo;
    string vehicleType;
    int yearOfRegistration;
    string gearboxType;
    int powerOutput;
    string model;
    int kilometersDriven;
    int monthOfRegistration;
    string fuelType;
    string brand;
    string notRepairedDamage;
    string dateCreated;
    int numberOfPictures;
    string postalCode;
    string lastSeen;

public:
    Car() : name(""), dateCrawled(""), sellerType(""), offerType(""), price(0.0), abTestInfo(""),
        vehicleType(""), yearOfRegistration(0), gearboxType(""), powerOutput(0), model(""),
        kilometersDriven(0), monthOfRegistration(0), fuelType(""), brand(""), notRepairedDamage(""),
        dateCreated(""), numberOfPictures(0), postalCode(""), lastSeen("")
    {
    
    }

    Car operator+(const Car& other) const 
    {
        Car result = *this;
        result.price += other.price;
        result.powerOutput += other.powerOutput;
        result.kilometersDriven += other.kilometersDriven;
        result.numberOfPictures += other.numberOfPictures;
        return result;
    }

    Car& operator+=(const Car& other) 
    {
        this->price += other.price;
        this->powerOutput += other.powerOutput;
        this->kilometersDriven += other.kilometersDriven;
        this->numberOfPictures += other.numberOfPictures;
        return *this;
    }

    double operator-(const Car& other) const
    {
        return this->price - other.price;
    }

    Car& operator-=(const Car& other) 
    {
        this->price -= other.price;
        this->powerOutput -= other.powerOutput;
        this->kilometersDriven -= other.kilometersDriven;
        this->numberOfPictures -= other.numberOfPictures;
        return *this;
    }

    bool operator==(const Car& other) const 
    {
        return name == other.name &&
            dateCrawled == other.dateCrawled &&
            sellerType == other.sellerType &&
            offerType == other.offerType &&
            price == other.price &&
            abTestInfo == other.abTestInfo &&
            vehicleType == other.vehicleType &&
            yearOfRegistration == other.yearOfRegistration &&
            gearboxType == other.gearboxType &&
            powerOutput == other.powerOutput &&
            model == other.model &&
            kilometersDriven == other.kilometersDriven &&
            monthOfRegistration == other.monthOfRegistration &&
            fuelType == other.fuelType &&
            brand == other.brand &&
            notRepairedDamage == other.notRepairedDamage &&
            dateCreated == other.dateCreated &&
            numberOfPictures == other.numberOfPictures &&
            postalCode == other.postalCode &&
            lastSeen == other.lastSeen;
    }

    bool operator>(const Car& other) const
    {
        return price > other.price;
    }

    bool operator<(const Car& other) const 
    {
        return price < other.price;
    }

    bool operator>=(const Car& other) const 
    {
        return price >= other.price;
    }

    bool operator<=(const Car& other) const
    {
        return price <= other.price;
    }

    bool operator!=(const Car& other) const 
    {
        return !(*this == other);
    }

    friend ostream& operator<<(ostream& os, const Car& car)
    {
        os << "Name: " << car.name << endl;
        os << "Date Crawled: " << car.dateCrawled << endl;
        os << "Seller Type: " << car.sellerType << endl;
        os << "Offer Type: " << car.offerType << endl;
        os << "Price: " << car.price << endl;
        os << "A/B Testing Info: " << car.abTestInfo << endl;
        os << "Vehicle Type: " << car.vehicleType << endl;
        os << "Year of Registration: " << car.yearOfRegistration << endl;
        os << "Gearbox Type: " << car.gearboxType << endl;
        os << "Power Output: " << car.powerOutput << endl;
        os << "Model: " << car.model << endl;
        os << "Kilometers Driven: " << car.kilometersDriven << endl;
        os << "Month of Registration: " << car.monthOfRegistration << endl;
        os << "Fuel Type: " << car.fuelType << endl;
        os << "Brand: " << car.brand << endl;
        os << "Not Repaired Damage: " << car.notRepairedDamage << endl;
        os << "Date Created: " << car.dateCreated << endl;
        os << "Number of Pictures: " << car.numberOfPictures << endl;
        os << "Postal Code: " << car.postalCode << endl;
        os << "Last Seen: " << car.lastSeen << endl;
        return os;
    }

    friend istream& operator>>(istream& is, Car& car)
    {
        cout << "Enter Name: ";
        is >> car.name;
        cout << "Enter Date Crawled: ";
        is.ignore();
        getline(is, car.dateCrawled);
        cout << "Enter Seller Type: ";
        is >> car.sellerType;
        cout << "Enter Offer Type: ";
        is >> car.offerType;
        cout << "Enter Price: ";
        is >> car.price;
        cout << "Enter A/B Testing Info: ";
        is >> car.abTestInfo;
        cout << "Enter Vehicle Type: ";
        is >> car.vehicleType;
        cout << "Enter Year of Registration: ";
        is >> car.yearOfRegistration;
        cout << "Enter Gearbox Type: ";
        is >> car.gearboxType;
        cout << "Enter Power Output: ";
        is >> car.powerOutput;
        cout << "Enter Model: ";
        is >> car.model;
        cout << "Enter Kilometers Driven: ";
        is >> car.kilometersDriven;
        cout << "Enter Month of Registration: ";
        is >> car.monthOfRegistration;
        cout << "Enter Fuel Type: ";
        is >> car.fuelType;
        cout << "Enter Brand: ";
        is >> car.brand;
        cout << "Enter Not Repaired Damage: ";
        is >> car.notRepairedDamage;
        cout << "Enter Date Created: ";
        is.ignore();
        getline(is, car.dateCreated);
        cout << "Enter Number of Pictures: ";
        is >> car.numberOfPictures;
        cout << "Enter Postal Code: ";
        is >> car.postalCode;
        cout << "Enter Last Seen: ";
        is.ignore();
        getline(is, car.lastSeen);
        return is;
    }

    Car operator+() const 
    {
        Car result = *this;
        result.price = abs(result.price);
        result.powerOutput = abs(result.powerOutput);
        result.kilometersDriven = abs(result.kilometersDriven);
        result.numberOfPictures = abs(result.numberOfPictures);
        return result;
    }

    Car operator-() const 
    {
        Car result = *this;
        result.price = -result.price;
        result.powerOutput = -result.powerOutput;
        result.kilometersDriven = -result.kilometersDriven;
        result.numberOfPictures = -result.numberOfPictures;
        return result;
    }
};

int main() 
{
    Car car1;
    Car car2;
    cout << "Please provide details for the first car:" << endl;
    cin >> car1;
    cout << "Now, please provide details for the second car:" << endl;
    cin >> car2;

    Car car3 = car1 + car2;
    cout << "Details of car 3 (car1 + car2):" << endl;
    cout << car3 << endl;

    car1 += car2;
    cout << "Details of car1 after car1 += car2:" << endl;
    cout << car1 << endl;

    double priceDifference = car1 - car2;
    cout << "Price difference between car1 and car2: " << priceDifference << endl;

    car1 -= car2;
    cout << "Details of car1 after car1 -= car2:" << endl;
    cout << car1 << endl;

    bool areEqual = (car1 == car2);
    cout << "Are car1 and car2 equal? " << (areEqual ? "Yes" : "No") << endl;

    bool isCar1MoreExpensive = (car1 > car2);
    cout << "Is car1 more expensive than car2? " << (isCar1MoreExpensive ? "Yes" : "No") << endl;

    return 0;
}
