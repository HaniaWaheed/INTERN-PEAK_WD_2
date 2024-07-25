/* Hania Waheef
roll no: 22i-0982
Section C
*/

#include <iostream>
#include <cstring>

using namespace std;

class BankAccount {
public:
    char accountNumber[50];
    char pin[50];
    double balance;

    BankAccount() : balance(0) {
        accountNumber[0] = '\0';
        pin[0] = '\0';
    }

    BankAccount(const char* accNo, const char* pinCode, double initialBalance)
        : balance(initialBalance) {
        copy(accountNumber, accNo);
        copy(pin, pinCode);
    }

    void copy(char* dest, const char* src) const {
        int i = 0;
        while (src[i] != '\0') {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }

    bool compare(const char* str1, const char* str2) const {
        return strcmp(str1, str2) == 0;
    }
};

class Bank {
public:
    BankAccount accounts[100];
    int numAccounts = 0;

    void openAccount() {
        char accNo[50];
        char pin[50];
        double initialBalance;

        cout << "Enter account number: ";
        cin >> accNo;
        cout << "Enter PIN: ";
        cin >> pin;
        cout << "Enter initial balance: ";
        cin >> initialBalance;

        if (numAccounts < 100) {
            accounts[numAccounts] = BankAccount(accNo, pin, initialBalance);
            numAccounts++;
            cout << "Account successfully created.\n";
        }
        else {
            cout << "Bank account limit reached. Cannot open more accounts.\n";
        }
    }

    void viewAccountDetails() const {
        char accNo[50];
        cout << "Enter account number: ";
        cin >> accNo;

        int index = findAccountIndex(accNo);
        if (index != -1) {
            cout << "Account Number: " << accounts[index].accountNumber << "\n"
                << "Balance: " << accounts[index].balance << "\n";
        }
        else {
            cout << "Account not found.\n";
        }
    }

    void depositCash() {
        char accNo[50];
        double amount;

        cout << "Enter account number: ";
        cin >> accNo;
        cout << "Enter amount to deposit: ";
        cin >> amount;

        int index = findAccountIndex(accNo);
        if (index != -1) {
            accounts[index].balance += amount;
            cout << "Deposit successful. New balance: " << accounts[index].balance << "\n";
        }
        else {
            cout << "Account not found.\n";
        }
    }

    void withdrawCash() {
        char accNo[50];
        double amount;

        cout << "Enter account number: ";
        cin >> accNo;
        cout << "Enter amount to withdraw: ";
        cin >> amount;

        int index = findAccountIndex(accNo);
        if (index != -1) {
            if (accounts[index].balance >= amount) {
                accounts[index].balance -= amount;
                cout << "Withdrawal successful. New balance: " << accounts[index].balance << "\n";
            }
            else {
                cout << "Insufficient balance.\n";
            }
        }
        else {
            cout << "Account not found.\n";
        }
    }

    void payBill() {
        char accNo[50];
        double amount;

        cout << "Enter account number: ";
        cin >> accNo;
        cout << "Enter bill amount: ";
        cin >> amount;

        int index = findAccountIndex(accNo);
        if (index != -1) {
            if (accounts[index].balance >= amount) {
                accounts[index].balance -= amount;
                cout << "Bill payment successful. New balance: " << accounts[index].balance << "\n";
            }
            else {
                cout << "Insufficient balance.\n";
            }
        }
        else {
            cout << "Account not found.\n";
        }
    }

    bool isValidAccountNumber(const char* accNo) const {
        return findAccountIndex(accNo) != -1;
    }

    int findAccountIndex(const char* accNo) const {
        for (int i = 0; i < numAccounts; ++i) {
            if (accounts[i].compare(accounts[i].accountNumber, accNo)) {
                return i;
            }
        }
        return -1;
    }
};

class ATM {
public:
    void validateCardAndPin(const Bank& bank) const {
        char accNo[50];
        char pin[50];
        int attempts = 0;

        while (attempts < 3) {
            cout << "Enter account number: ";
            cin >> accNo;
            cout << "Enter PIN: ";
            cin >> pin;

            int index = bank.findAccountIndex(accNo);
            if (index != -1 && bank.accounts[index].compare(bank.accounts[index].pin, pin)) {
                cout << "Authentication successful.\n";
                return;
            }
            cout << "Invalid account number or PIN. Please try again.\n";
            attempts++;
        }
        cout << "Too many incorrect attempts. Exiting ATM.\n";
    }

    void withdrawCash(Bank& bank) {
        char accNo[50];
        char pin[50];
        double amount;

        cout << "Enter account number: ";
        cin >> accNo;
        cout << "Enter PIN: ";
        cin >> pin;

        int index = bank.findAccountIndex(accNo);
        if (index != -1 && bank.accounts[index].compare(bank.accounts[index].pin, pin)) {
            cout << "Enter amount to withdraw: ";
            cin >> amount;

            if (bank.accounts[index].balance >= amount) {
                bank.accounts[index].balance -= amount;
                cout << "Withdrawal successful. New balance: " << bank.accounts[index].balance << "\n";
            }
            else {
                cout << "Insufficient balance.\n";
            }
        }
        else {
            cout << "Invalid account number or PIN.\n";
        }
    }

    void changePin(Bank& bank) {
        char accNo[50];
        char oldPin[50];
        char newPin[50];

        cout << "Enter account number: ";
        cin >> accNo;
        cout << "Enter old PIN: ";
        cin >> oldPin;

        int index = bank.findAccountIndex(accNo);
        if (index != -1 && bank.accounts[index].compare(bank.accounts[index].pin, oldPin)) {
            cout << "Enter new PIN: ";
            cin >> newPin;
            bank.accounts[index].copy(bank.accounts[index].pin, newPin);
            cout << "PIN successfully changed.\n";
        }
        else {
            cout << "Invalid account number or old PIN.\n";
        }
    }

    void checkBalance(const Bank& bank) const {
        char accNo[50];
        char pin[50];

        cout << "Enter account number: ";
        cin >> accNo;
        cout << "Enter PIN: ";
        cin >> pin;

        int index = bank.findAccountIndex(accNo);
        if (index != -1 && bank.accounts[index].compare(bank.accounts[index].pin, pin)) {
            cout << "Current balance: " << bank.accounts[index].balance << "\n";
        }
        else {
            cout << "Invalid account number or PIN.\n";
        }
    }
};

class Administrator {
public:
    char username[50];
    char password[50];

    Administrator(const char* user, const char* pass) {
        BankAccount().copy(username, user);
        BankAccount().copy(password, pass);
    }

    void processBillPayments(Bank& bank) const {
        cout << "Processing bill payments...\n";
        for (int i = 0; i < bank.numAccounts; ++i) {
            double billAmount = 50.0;
            if (bank.accounts[i].balance >= billAmount) {
                bank.accounts[i].balance -= billAmount;
                cout << "Bill payment successful for account: " << bank.accounts[i].accountNumber << "\n";
            }
            else {
                cout << "Insufficient balance for bill payment in account: " << bank.accounts[i].accountNumber << "\n";
            }
        }
        cout << "Bill payments processed.\n";
    }

    void processAccountOpenings(Bank& bank) const {
        cout << "Processing account openings...\n";
        bank.openAccount();
        cout << "Account openings processed.\n";
    }

    bool authenticate() const {
        char enteredUsername[50];
        char enteredPassword[50];

        cout << "Enter username: ";
        cin >> enteredUsername;
        cout << "Enter password: ";
        cin >> enteredPassword;

        if (BankAccount().compare(username, enteredUsername) &&
            BankAccount().compare(password, enteredPassword)) {
            cout << "Authentication successful.\n";
            return true;
        }
        else {
            cout << "Authentication failed.\n";
            return false;
        }
    }
};

int main() {
    Bank bank;
    ATM atm;
    Administrator admin("admin", "password");

    cout << "            WELCOME TO THE BANK SYSTEM                  " << endl;
    cout << "              These are our services                       " << endl;
    cout << "Press Enter to proceed to the main menu...";
    cin.get(); // Wait for user to press Enter
    cin.ignore(); // Clear input buffer

    int mainMenuChoice;
    do {
        cout << "\n=== Main Menu ===\n";
        cout << "1. Enter Bank\n";
        cout << "2. Enter ATM\n";
        cout << "3. Administrator Access\n";
        cout << "4. Exit System\n";
        cout << "Enter your choice: ";
        cin >> mainMenuChoice;

        switch (mainMenuChoice) {
        case 1:
            int bankChoice;
            do {
                cout << "\n=== Bank Menu ===\n";
                cout << "1. Open Account\n";
                cout << "2. View Account Details\n";
                cout << "3. Deposit Cash\n";
                cout << "4. Withdraw Cash\n";
                cout << "5. Pay Bill\n";
                cout << "6. Back to Main Menu\n";
                cout << "Enter your choice: ";
                cin >> bankChoice;

                switch (bankChoice) {
                case 1:
                    bank.openAccount();
                    break;
                case 2:
                    bank.viewAccountDetails();
                    break;
                case 3:
                    bank.depositCash();
                    break;
                case 4:
                    bank.withdrawCash();
                    break;
                case 5:
                    bank.payBill();
                    break;
                case 6:
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
                    break;
                }
            } while (bankChoice != 6);
            break;

        case 2:
            int atmChoice;
            do {
                cout << "\n=== ATM Menu ===\n";
                cout << "1. Validate Card and PIN\n";
                cout << "2. Withdraw Cash\n";
                cout << "3. Change PIN\n";
                cout << "4. Check Balance\n";
                cout << "5. Back to Main Menu\n";
                cout << "Enter your choice: ";
                cin >> atmChoice;

                switch (atmChoice) {
                case 1:
                    atm.validateCardAndPin(bank);
                    break;
                case 2:
                    atm.withdrawCash(bank);
                    break;
                case 3:
                    atm.changePin(bank);
                    break;
                case 4:
                    atm.checkBalance(bank);
                    break;
                case 5:
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
                    break;
                }
            } while (atmChoice != 5);
            break;

        case 3:
            if (admin.authenticate()) {
                int adminChoice;
                do {
                    cout << "\n=== Administrator Menu ===\n";
                    cout << "1. Process Bill Payments\n";
                    cout << "2. Process Account Openings\n";
                    cout << "3. Back to Main Menu\n";
                    cout << "Enter your choice: ";
                    cin >> adminChoice;

                    switch (adminChoice) {
                    case 1:
                        admin.processBillPayments(bank);
                        break;
                    case 2:
                        admin.processAccountOpenings(bank);
                        break;
                    case 3:
                        break;
                    default:
                        cout << "Invalid choice. Please try again.\n";
                        break;
                    }
                } while (adminChoice != 3);
            }
            break;

        case 4:
            cout << "Exiting the system. Thank you for using our services.\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (mainMenuChoice != 4);

    return 0;
}
