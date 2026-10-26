
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Account {
public:
    int accountNumber;
    string name;
    double balance;

    Account(int number, string customerName, double amount) {
        accountNumber = number;
        name = customerName;
        balance = amount;
    }

    void display() {
        cout << "\nAccount Number: " << accountNumber;
        cout << "\nCustomer Name: " << name;
        cout << "\nBalance: Rs. " << balance << endl;
    }
};

vector<Account> accounts;

// Load saved accounts from the file
void loadAccounts() {
    ifstream file("accounts.txt");

    int number;
    string name;
    double balance;

    while (file >> number) {
        file.ignore();
        getline(file, name, '|');

        if (file >> balance) {
            accounts.push_back(Account(number, name, balance));
        }

        file.ignore();
    }

    file.close();
}

// Save all accounts to the file
void saveAccounts() {
    ofstream file("accounts.txt");

    for (int i = 0; i < accounts.size(); i++) {
        file << accounts[i].accountNumber << " "
             << accounts[i].name << "|"
             << accounts[i].balance << endl;
    }

    file.close();
}

// Find an account using its account number
int findAccount(int number) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].accountNumber == number) {
            return i;
        }
    }

    return -1;
}

// Create a new account
void createAccount() {
    int number = 1001;

    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].accountNumber >= number) {
            number = accounts[i].accountNumber + 1;
        }
    }

    string name;
    double amount;

    cout << "\nEnter customer name: ";
    getline(cin >> ws, name);

    cout << "Enter initial deposit (Rs.): ";
    if (!(cin >> amount) || amount < 0) {
        cout << "Invalid amount!\n";
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }

    accounts.push_back(Account(number, name, amount));
    saveAccounts();

    cout << "\nAccount created successfully!";
    cout << "\nYour account number is: " << number << endl;
}

// Deposit money
void depositMoney() {
    int number;
    double amount;

    cout << "\nEnter account number: ";
    if (!(cin >> number)) {
        cout << "Invalid account number!\n";
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }

    int index = findAccount(number);

    if (index == -1) {
        cout << "Account not found!\n";
        return;
    }

    cout << "Enter amount to deposit: Rs. ";
    if (!(cin >> amount) || amount <= 0) {
        cout << "Enter a valid positive amount!\n";
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }

    accounts[index].balance += amount;
    saveAccounts();

    cout << "Deposit successful!";
    cout << "\nUpdated balance: Rs. "
         << accounts[index].balance << endl;
}

// Withdraw money
void withdrawMoney() {
    int number;
    double amount;

    cout << "\nEnter account number: ";
    if (!(cin >> number)) {
        cout << "Invalid account number!\n";
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }

    int index = findAccount(number);

    if (index == -1) {
        cout << "Account not found!\n";
        return;
    }

    cout << "Enter amount to withdraw: Rs. ";
    if (!(cin >> amount) || amount <= 0) {
        cout << "Enter a valid positive amount!\n";
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }

    if (amount > accounts[index].balance) {
        cout << "Insufficient balance!\n";
        return;
    }

    accounts[index].balance -= amount;
    saveAccounts();

    cout << "Withdrawal successful!";
    cout << "\nRemaining balance: Rs. "
         << accounts[index].balance << endl;
}

// Check account balance
void checkBalance() {
    int number;

    cout << "\nEnter account number: ";
    if (!(cin >> number)) {
        cout << "Invalid account number!\n";
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }

    int index = findAccount(number);

    if (index == -1) {
        cout << "Account not found!\n";
    } else {
        accounts[index].display();
    }
}

int main() {
    loadAccounts();

    int choice;

    do {
        cout << "\n\n===== BANK MANAGEMENT SYSTEM =====";
        cout << "\n1. Create Account";
        cout << "\n2. Deposit Money";
        cout << "\n3. Withdraw Money";
        cout << "\n4. Check Balance";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";

        if (!(cin >> choice)) {
            cout << "Please enter a valid number!\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1:
                createAccount();
                break;

            case 2:
                depositMoney();
                break;

            case 3:
                withdrawMoney();
                break;

            case 4:
                checkBalance();
                break;

            case 5:
                cout << "\nThank you for using our bank!";
                break;

            default:
                cout << "\nInvalid choice! Try again.";
        }

    } while (choice != 5);

    return 0;
}
