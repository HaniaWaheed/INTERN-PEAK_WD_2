#include <iostream>

using namespace std;

class Date {
public:
    int year;
    int month;
    int day;
    int hour;
    int minute;

    Date(int y = 0, int m = 0, int d = 0, int h = 0, int min = 0)
        : year(y), month(m), day(d), hour(h), minute(min) {}

    void setDate(int y, int m, int d, int h, int min) {
        year = y;
        month = m;
        day = d;
        hour = h;
        minute = min;
    }

    void getDate() const {
        cout << year << "-" << month << "-" << day << " " << hour << ":" << minute << endl;
    }
};

class RentalReservation {
private:
    char reservation_id[15];
    char customer_name[50];
    char car_make_model[50];
    Date pickup_date;
    Date return_date;
    double rental_duration;
    double rental_rate;
    double rental_total=0.0;
    char additional_services[100];
    int customer_age;

    char available_cars[100][50];
    double car_rates[100][2];
    int numCars;

    //bool validateReservationID(const char *id) const;
  //  bool validateCarMakeAndModel(const char *model) const;
  //  void calculateRentalDuration();
  //  void calculateRentalRate();
  //  void calculateRentalTotal();
  //  bool isAlphaNum(char c) const;
  //  bool isDigit(char c) const;

public:
    RentalReservation(const char *res_id, const char *cust_name, const char *car_model,
                      const Date &pickup, const Date &ret, const char *services, int age);

    //void getReservationDetails() const;

   // void updateReservation(const Date &new_pickup, const Date &new_return,
                     //      const char *new_car_model, const char *new_services);

    //void addCarModel(const char *model, double base_rate, double peak_rate);

   // void removeCarModel(const char *model);

   // void addAdditionalService(const char *service);

    RentalReservation() : rental_duration(0), rental_rate(0), rental_total(0), numCars(0) {
        cout << "Enter Reservation ID (14 characters): ";
        cin.getline(reservation_id, 15);

        cout << "Enter Customer Name: ";
        cin.getline(customer_name, 50);

        cout << "Enter Car Make and Model: ";
        cin.getline(car_make_model, 50);

        cout << "Enter Pickup Date (yyyy mm dd hh mm): ";
        int y, m, d, h, min;
        cin >> y >> m >> d >> h >> min;
        pickup_date.setDate(y, m, d, h, min);

        cout << "Enter Return Date (yyyy mm dd hh mm): ";
        cin >> y >> m >> d >> h >> min;
        return_date.setDate(y, m, d, h, min);

        cout << "Enter Additional Services (GCI for GPS, Child seat, Insurance, separated by spaces): ";
        cin.ignore(); // Clear input buffer
        cin.getline(additional_services, 100);

        cout << "Enter Customer Age: ";
        cin >> customer_age;

        if (validateReservationID(reservation_id) && validateCarMakeAndModel(car_make_model)) {
            calculateRentalDuration();
            calculateRentalRate();
            calculateRentalTotal();
        } else {
            cout << "Invalid reservation details. Please try again." << endl;
        }
    }

    bool validateReservationID(const char *id) const {
        int len = 0;
        while (id[len] != '\0') {
            ++len;
        }

        if (len != 14) {
            return false;
        }

        for (int i = 0; i < 8; ++i) {
            if (!isAlphaNum(id[i])) {
                return false;
            }
        }

        for (int i = 8; i < 10; ++i) {
            if (isAlphaNum(id[i])) {
                return false; // Must be special characters
            }
        }

        int digitSum = 0;
        for (int i = 10; i < 14; ++i) {
            if (!isDigit(id[i])) {
                return false;
            }
            digitSum += id[i] - '0';
        }

        return digitSum < 18;
    }

    bool validateCarMakeAndModel(const char *model) const {
        for (int i = 0; i < numCars; ++i) {
            if (compareString(available_cars[i], model)) {
                return true;
            }
        }
        return false;
    }

    void calculateRentalDuration() {
        rental_duration = 24; // Example duration for simplicity
    }

    void calculateRentalRate() {
        for (int i = 0; i < numCars; ++i) {
            if (compareString(available_cars[i], car_make_model)) {
                rental_rate = car_rates[i][0]; // Assuming base rate is stored in column 0
                return;
            }
        }
    }

    void calculateRentalTotal() {
        rental_total = rental_duration * rental_rate;
        if (additional_services[0] != '\0') {
            rental_total += calculateAdditionalServiceCost();
        }
    }

    double calculateAdditionalServiceCost() const {
        double totalCost = 0.0;
        const char *service = additional_services;
        while (*service != '\0') {
            switch (*service) {
            case 'G':
                totalCost += 2000; // GPS cost
                break;
            case 'C':
                totalCost += 7000; // Child seat cost
                break;
            case 'I':
                totalCost += 30000; // Insurance cost
                break;
            default:
                break;
            }
            ++service;
        }
        return totalCost;
    }

    void getReservationDetails() const {
        cout << "Reservation ID: " << reservation_id << endl;
        cout << "Customer Name: " << customer_name << endl;
        cout << "Car Make and Model: " << car_make_model << endl;
        cout << "Pickup Date: ";
        pickup_date.getDate();
        cout << "Return Date: ";
        return_date.getDate();
        cout << "Rental Duration (hours): " << rental_duration << endl;
        cout << "Rental Rate (per hour): " << rental_rate << endl;
        cout << "Rental Total: " << rental_total << endl;
        cout << "Additional Services: " << additional_services << endl;
    }

    void updateReservation(const Date &new_pickup, const Date &new_return,
                           const char *new_car_model, const char *new_services) {
        if (!validateCarMakeAndModel(new_car_model)) {
            cout << "Invalid car model. Update failed." << endl;
            return;
        }

        pickup_date = new_pickup;
        return_date = new_return;

        copyString(car_make_model, new_car_model, 49);
        copyString(additional_services, new_services, 99);

        calculateRentalDuration();
        calculateRentalRate();
        calculateRentalTotal();

        cout << "Reservation updated successfully!" << endl;
    }

    void addCarModel(const char *model, double base_rate, double peak_rate) {
        if (numCars < 100) {
            copyString(available_cars[numCars], model, 49);
            car_rates[numCars][0] = base_rate;
            car_rates[numCars][1] = peak_rate;
            ++numCars;
        } else {
            cout << "Cannot add more car models. Maximum limit reached." << endl;
        }
    }

    void removeCarModel(const char *model) {
        for (int i = 0; i < numCars; ++i) {
            if (compareString(available_cars[i], model)) {
                for (int j = i; j < numCars - 1; ++j) {
                    copyString(available_cars[j], available_cars[j + 1], 49);
                    car_rates[j][0] = car_rates[j + 1][0];
                    car_rates[j][1] = car_rates[j + 1][1];
                }
                --numCars;
                cout << "Car model removed successfully." << endl;
                return;
            }
        }
        cout << "Car model not found." << endl;
    }

    void addAdditionalService(const char *service) {
        int len = 0;
        while (additional_services[len] != '\0') {
            ++len;
        }

        int serviceLen = 0;
        while (service[serviceLen] != '\0') {
            additional_services[len + serviceLen] = service[serviceLen];
            ++serviceLen;
        }
        additional_services[len + serviceLen] = '\0';
    }

    bool isAlphaNum(char c) const {
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
    }

    bool isDigit(char c) const {
        return c >= '0' && c <= '9';
    }

    bool compareString(const char *str1, const char *str2) const {
        while (*str1 != '\0' && *str2 != '\0') {
            if (*str1 != *str2) {
                return false;
            }
            ++str1;
            ++str2;
        }
        return *str1 == '\0' && *str2 == '\0';
    }

    void copyString(char *dest, const char *src, int maxLen) {
        int i = 0;
        while (src[i] != '\0' && i < maxLen) {
            dest[i] = src[i];
            ++i;
        }
        dest[i] = '\0';
    }
};

int main() {
    RentalReservation reservation;

    reservation.getReservationDetails();

    Date new_pickup, new_return;
    char new_car_model[50], new_services[100];

    cout << "Enter New Pickup Date (yyyy mm dd hh mm): ";
    int y, m, d, h, min;
    cin >> y >> m >> d >> h >> min;
    new_pickup.setDate(y, m, d, h, min);

    cout << "Enter New Return Date (yyyy mm dd hh mm): ";
    cin >> y >> m >> d >> h >> min;
    new_return.setDate(y, m, d, h, min);

    cin.ignore(); // Clear input buffer
    cout << "Enter New Car Make and Model: ";
    cin.getline(new_car_model, 50);

    cout << "Enter New Additional Services (GCI for GPS, Child seat, Insurance, separated by spaces): ";
    cin.getline(new_services, 100);

    reservation.updateReservation(new_pickup, new_return, new_car_model, new_services);

    reservation.getReservationDetails();

    return 0;
}
