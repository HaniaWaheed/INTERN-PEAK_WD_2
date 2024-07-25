#include <iostream>
#include <cstring>
#include <ctime>

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

    bool operator<(const Date& other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        if (day != other.day) return day < other.day;
        if (hour != other.hour) return hour < other.hour;
        return minute < other.minute;
    }

    bool operator==(const Date& other) const {
        return year == other.year && month == other.month && day == other.day &&
            hour == other.hour && minute == other.minute;
    }

    double calculateDuration(const Date& other) const {
        tm t1 = { 0, minute, hour, day, month - 1, year - 1900 };
        tm t2 = { 0, other.minute, other.hour, other.day, other.month - 1, other.year - 1900 };
        time_t time1 = mktime(&t1);
        time_t time2 = mktime(&t2);
        return difftime(time2, time1) / 3600.0; // duration in hours
    }

    void differenceInTime(const Date& other, int& hours, int& minutes) const {
        tm t1 = { 0, minute, hour, day, month - 1, year - 1900 };
        tm t2 = { 0, other.minute, other.hour, other.day, other.month - 1, other.year - 1900 };
        time_t time1 = mktime(&t1);
        time_t time2 = mktime(&t2);
        double diff = difftime(time2, time1);
        hours = static_cast<int>(diff / 3600);
        minutes = static_cast<int>((diff - (hours * 3600)) / 60);
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
    double rental_total;
    char additional_services[100];
    int customer_age;

    char available_cars[100][50];
    double car_rates[100][2];
    int numCars;

    bool validateReservationID(const char* id) const;
    bool validateCarMakeAndModel(const char* model) const;
    void calculateRentalDuration();
    void calculateRentalRate();
    void calculateRentalTotal();
    double calculateAdditionalServiceCost() const;
    bool isAlphaNum(char c) const;
    bool isDigit(char c) const;
    bool compareString(const char* str1, const char* str2) const;
    void copyString(char* dest, size_t dest_sz, const char* src, size_t count);

public:
    RentalReservation();
    ~RentalReservation();

    void getReservationDetails() const;
    void updateReservation();
    void addCarModel();
    void removeCarModel();
    void addAdditionalService(const char* service);
    void printAvailableCars() const;
};

RentalReservation::RentalReservation() : rental_duration(0), rental_rate(0), rental_total(0), numCars(0) {
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

    cin.ignore(); 
    cout << "Enter Additional Services (GCI for GPS, Child seat, Insurance, separated by spaces): ";
    cin.getline(additional_services, 100);

    cout << "Enter Customer Age: ";
    cin >> customer_age;

    if (validateReservationID(reservation_id) && validateCarMakeAndModel(car_make_model)) {
        calculateRentalDuration();
        calculateRentalRate();
        calculateRentalTotal();
    }
    else {
        cout << "Invalid reservation details. Please try again." << endl;
    }
}

RentalReservation::~RentalReservation() {
    cout << "Reservation with ID: " << reservation_id << " has been destroyed." << endl;
}

bool RentalReservation::validateReservationID(const char* id) const {
    size_t len = strlen(id);
    if (len != 14) return false;

    for (size_t i = 0; i < 8; ++i) {
        if (!isAlphaNum(id[i])) return false;
    }

    for (size_t i = 8; i < 10; ++i) {
        if (isAlphaNum(id[i])) return false; 
    }

    int digitSum = 0;
    for (size_t i = 10; i < 14; ++i) {
        if (!isDigit(id[i])) return false;
        digitSum += id[i] - '0';
    }

    return digitSum < 18;
}

bool RentalReservation::validateCarMakeAndModel(const char* model) const {
    for (int i = 0; i < numCars; ++i) {
        if (compareString(available_cars[i], model)) {
            return true;
        }
    }
    return false;
}

void RentalReservation::calculateRentalDuration() {
    rental_duration = pickup_date.calculateDuration(return_date);
}

void RentalReservation::calculateRentalRate() {
    for (int i = 0; i < numCars; ++i) {
        if (compareString(available_cars[i], car_make_model)) {
            rental_rate = car_rates[i][0]; 
            if (customer_age < 25) {
                rental_rate *= 1.2;
            }
            return;
        }
    }
}

void RentalReservation::calculateRentalTotal() {
    rental_total = rental_duration * rental_rate;
    if (additional_services[0] != '\0') {
        rental_total += calculateAdditionalServiceCost();
    }
}

double RentalReservation::calculateAdditionalServiceCost() const {
    double totalCost = 0.0;
    const char* service = additional_services;
    while (*service != '\0') {
        switch (*service) {
        case 'G':
            totalCost += 2000; 
            break;
        case 'C':
            totalCost += 7000; 
            break;
        case 'I':
            totalCost += 30000; 
            break;
        default:
            break;
        }
        ++service;
    }
    return totalCost;
}

void RentalReservation::getReservationDetails() const {
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

void RentalReservation::updateReservation() {
    cout << "Enter New Pickup Date (yyyy mm dd hh mm): ";
    int y, m, d, h, min;
    cin >> y >> m >> d >> h >> min;
    Date new_pickup(y, m, d, h, min);

    cout << "Enter New Return Date (yyyy mm dd hh mm): ";
    cin >> y >> m >> d >> h >> min;
    Date new_return(y, m, d, h, min);

    cin.ignore();

    cout << "Enter New Car Make and Model: ";
    char new_car_model[50];
    cin.getline(new_car_model, 50);

    cout << "Enter Additional Services (GCI for GPS, Child seat, Insurance, separated by spaces): ";
    char new_services[100];
    cin.getline(new_services, 100);

    if (!validateCarMakeAndModel(new_car_model)) {
        cout << "Invalid car model. Update failed." << endl;
        return;
    }

    int diff_hours, diff_minutes;
    pickup_date.differenceInTime(new_pickup, diff_hours, diff_minutes);
    cout << "Difference in pickup time: " << diff_hours << " hours and " << diff_minutes << " minutes." << endl;

    return_date.differenceInTime(new_return, diff_hours, diff_minutes);
    cout << "Difference in return time: " << diff_hours << " hours and " << diff_minutes << " minutes." << endl;

    pickup_date = new_pickup;
    return_date = new_return;
    copyString(car_make_model, 50, new_car_model, 50);
    copyString(additional_services, 100, new_services, 100);

    calculateRentalDuration();
    calculateRentalRate();
    calculateRentalTotal();
    cout << "Reservation updated successfully." << endl;
}

void RentalReservation::addCarModel() {
    char model[50];
    double base_rate, peak_rate;

    cout << "Enter Car Model: ";
    cin.ignore();
    cin.getline(model, 50);

    cout << "Enter Base Rate: ";
    cin >> base_rate;

    cout << "Enter Peak Rate: ";
    cin >> peak_rate;

    if (numCars < 100) {
        copyString(available_cars[numCars], 50, model, 50);
        car_rates[numCars][0] = base_rate;
        car_rates[numCars][1] = peak_rate;
        numCars++;
        cout << "Car model added successfully." << endl;
    }
    else {
        cout << "Cannot add more car models. Maximum limit reached." << endl;
    }
}

void RentalReservation::removeCarModel() {
    char model[50];
    cout << "Enter Car Model to Remove: ";
    cin.ignore();
    cin.getline(model, 50);

    for (int i = 0; i < numCars; ++i) {
        if (compareString(available_cars[i], model)) {
            for (int j = i; j < numCars - 1; ++j) {
                copyString(available_cars[j], 50, available_cars[j + 1], 50);
                car_rates[j][0] = car_rates[j + 1][0];
                car_rates[j][1] = car_rates[j + 1][1];
            }
            numCars--;
            cout << "Car model removed successfully." << endl;
            return;
        }
    }
    cout << "Car model not found." << endl;
}

void RentalReservation::addAdditionalService(const char* service) {
    size_t current_len = strlen(additional_services);
    size_t service_len = strlen(service);
    if (current_len + service_len + 1 < sizeof(additional_services)) {
        if (current_len > 0) {
            strcat_s(additional_services, sizeof(additional_services), " ");
        }
        strcat_s(additional_services, sizeof(additional_services), service);
        cout << "Additional service added successfully." << endl;
    }
    else {
        cout << "Cannot add more services. Maximum limit reached." << endl;
    }
}

void RentalReservation::printAvailableCars() const {
    if (numCars == 0) {
        cout << "No available cars." << endl;
        return;
    }
    cout << "Available Cars and Rates:" << endl;
    for (int i = 0; i < numCars; ++i) {
        cout << available_cars[i] << " - Base Rate: " << car_rates[i][0] << ", Peak Rate: " << car_rates[i][1] << endl;
    }
}

bool RentalReservation::isAlphaNum(char c) const {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

bool RentalReservation::isDigit(char c) const {
    return (c >= '0' && c <= '9');
}

bool RentalReservation::compareString(const char* str1, const char* str2) const {
    return strcmp(str1, str2) == 0;
}

void RentalReservation::copyString(char* dest, size_t dest_sz, const char* src, size_t count) {
    strncpy_s(dest, dest_sz, src, count);
}

int main() {
    RentalReservation reservation;

    reservation.getReservationDetails();

    int numModels;
    cout << "Enter number of car models to add: ";
    cin >> numModels;

    for (int i = 0; i < numModels; ++i) {
        reservation.addCarModel();
    }

    reservation.printAvailableCars();

    reservation.updateReservation();

    reservation.getReservationDetails();

    return 0;
}
