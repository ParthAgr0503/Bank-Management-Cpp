#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Account {
    int accNo;
    string name;
    double balance;
};

vector<Account> accounts;

void createAccount() {
    Account acc;
    cout << "Enter Account Number: ";
    cin >> acc.accNo;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, acc.name);
    cout << "Enter Initial Balance: ";
    cin >> acc.balance;
    accounts.push_back(acc);
    cout << "Account Created Successfully!\n";
}

Account* findAccount(int accNo) {
    for (auto& acc : accounts) {
        if (acc.accNo == accNo)
            return &acc;
    }
    return nullptr;
}

void depositMoney() {
    int accNo;
    double amount;
    cout << "Enter Account Number: ";
    cin >> accNo;
    Account* acc = findAccount(accNo);
    if (acc) {
        cout << "Enter amount to deposit: ";
        cin >> amount;
        acc->balance += amount;
        cout << "Deposit successful!\n";
    } else {
        cout << "Account not found.\n";
    }
}

void withdrawMoney() {
    int accNo;
    double amount;
    cout << "Enter Account Number: ";
    cin >> accNo;
    Account* acc = findAccount(accNo);
    if (acc) {
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        if (amount <= acc->balance) {
            acc->balance -= amount;
            cout << "Withdrawal successful!\n";
        } else {
            cout << "Insufficient balance!\n";
        }
    } else {
        cout << "Account not found.\n";
    }
}

void displayAccount() {
    int accNo;
    cout << "Enter Account Number: ";
    cin >> accNo;
    Account* acc = findAccount(accNo);
    if (acc) {
        cout << "Account Number: " << acc->accNo << endl;
        cout << "Name: " << acc->name << endl;
        cout << "Balance: $" << acc->balance << endl;
    } else {
        cout << "Account not found.\n";
    }
}

void menu() {
    int choice;
    do {
        cout << "\n==== Bank Management Menu ====\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Display Account\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: createAccount(); break;
            case 2: depositMoney(); break;
            case 3: withdrawMoney(); break;
            case 4: displayAccount(); break;
            case 5: cout << "Thank you!\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 5);
}

int main() {
    menu();
    return 0;
}
