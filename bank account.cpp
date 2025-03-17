#include <iostream>
#include <vector>
#include <string>

using namespace std;

// BankAccount class definition
class BankAccount {
private:
    string accountHolderName;
    int accountNumber;
    double balance;
    vector<string> transactions;

public:
    // Constructor to initialize account
    BankAccount(string name, int accNumber, double initialDeposit) {
        accountHolderName = name;
        accountNumber = accNumber;
        balance = initialDeposit;
        transactions.push_back("Account created with initial deposit: $" + to_string(initialDeposit));
    }

    // Deposit function
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            transactions.push_back("Deposited: $" + to_string(amount));
            cout << "$" << amount << " deposited successfully!" << endl;
        } else {
            cout << "Invalid amount!" << endl;
        }
    }

    // Withdraw function
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            transactions.push_back("Withdrew: $" + to_string(amount));
            cout << "$" << amount << " withdrawn successfully!" << endl;
        } else {
            cout << "Insufficient balance or invalid amount!" << endl;
        }
    }

    // Check balance function
    void checkBalance() const {
        cout << "Current balance: $" << balance << endl;
    }

    // View transaction history
    void viewTransactions() const {
        cout << "Transaction history for account " << accountNumber << ":" << endl;
        for (const string& transaction : transactions) {
            cout << transaction << endl;
        }
    }

    // Get account holder's name
    string getAccountHolderName() const {
        return accountHolderName;
    }

    // Get account number
    int getAccountNumber() const {
        return accountNumber;
    }
};

// Main function to drive the program
int main() {
    string name;
    int accountNumber;
    double initialDeposit;

    // User input to create account
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your account number: ";
    cin >> accountNumber;
    cout << "Enter initial deposit: $";
    cin >> initialDeposit;

    // Create a bank account object
    BankAccount account(name, accountNumber, initialDeposit);

    // Menu-driven interface
    int choice;
    do {
        cout << "\n=== Bank Account System ===" << endl;
        cout << "1. Deposit Money" << endl;
        cout << "2. Withdraw Money" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. View Transaction History" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                double depositAmount;
                cout << "Enter deposit amount: $";
                cin >> depositAmount;
                account.deposit(depositAmount);
                break;
            }
            case 2: {
                double withdrawAmount;
                cout << "Enter withdrawal amount: $";
                cin >> withdrawAmount;
                account.withdraw(withdrawAmount);
                break;
            }
            case 3: {
                account.checkBalance();
                break;
            }
            case 4: {
                account.viewTransactions();
                break;
            }
            case 5: {
                cout << "Thank you for using the Bank Account System!" << endl;
                break;
            }
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
