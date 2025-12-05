#include <iostream>
#include <string>
using namespace std;

// -------------------------------------------------------
// BASE CLASS: BankAccount (Encapsulation + Inheritance)
// -------------------------------------------------------
class BankAccount {
protected:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(string accNo, string holder, double bal)
        : accountNumber(accNo), accountHolderName(holder), balance(bal) {}

    // Deposit
    virtual void deposit(double amount) {
        balance += amount;
        cout << "Amount Deposited Successfully!\n";
    }

    // Withdraw
    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawal Successful!\n";
        } else {
            cout << "Insufficient Balance!\n";
        }
    }

    // Getter (Encapsulation)
    double getBalance() const {
        return balance;
    }

    // Polymorphic method
    virtual void displayAccountInfo() {
        cout << "\n--- Account Details ---\n";
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }

    // Polymorphic interest method
    virtual double calculateInterest() {
        return 0.0; // Default
    }

    virtual ~BankAccount() {}
};


// -------------------------------------------------------
// DERIVED CLASS 1: SavingsAccount
// -------------------------------------------------------
class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(string accNo, string holder, double bal, double rate)
        : BankAccount(accNo, holder, bal), interestRate(rate) {}

    double calculateInterest() override {
        return balance * interestRate / 100;
    }

    void displayAccountInfo() override {
        BankAccount::displayAccountInfo();
        cout << "Interest Rate: " << interestRate << "%" << endl;
        cout << "Calculated Interest: " << calculateInterest() << endl;
    }
};


// -------------------------------------------------------
// DERIVED CLASS 2: CheckingAccount
// -------------------------------------------------------
class CheckingAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CheckingAccount(string accNo, string holder, double bal, double limit)
        : BankAccount(accNo, holder, bal), overdraftLimit(limit) {}

    void withdraw(double amount) override {
        if (amount <= balance + overdraftLimit) {
            balance -= amount;
            cout << "Withdrawal Successful (Overdraft applied if needed)!\n";
        } else {
            cout << "Exceeded Overdraft Limit!\n";
        }
    }

    void displayAccountInfo() override {
        BankAccount::displayAccountInfo();
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};


// -------------------------------------------------------
// DERIVED CLASS 3: FixedDepositAccount
// -------------------------------------------------------
class FixedDepositAccount : public BankAccount {
private:
    int term;           // in months
    double interestRate;

public:
    FixedDepositAccount(string accNo, string holder, double bal, int t, double rate)
        : BankAccount(accNo, holder, bal), term(t), interestRate(rate) {}

    double calculateInterest() override {
        return (balance * interestRate * term) / (100 * 12);
    }

    void displayAccountInfo() override {
        BankAccount::displayAccountInfo();
        cout << "Term: " << term << " months\n";
        cout << "Interest Rate: " << interestRate << "%\n";
        cout << "Maturity Interest: " << calculateInterest() << endl;
    }
};


// -------------------------------------------------------
// MAIN MENU-DRIVEN SYSTEM
// -------------------------------------------------------
int main() {
    BankAccount* account = nullptr;
    int choice;

    cout << "\n========== SIMPLE BANKING SYSTEM ==========\n";

    while (true) {
        cout << "\n--- Create Account ---\n";
        cout << "1. Savings Account\n";
        cout << "2. Checking Account\n";
        cout << "3. Fixed Deposit Account\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 4) break;

        string accNo, holder;
        double bal, rate, limit;
        int term;

        cout << "Enter Account Number: ";
        cin >> accNo;
        cout << "Enter Account Holder Name: ";
        cin >> holder;
        cout << "Enter Initial Balance: ";
        cin >> bal;

        switch (choice) {
        case 1:
            cout << "Enter Interest Rate (%): ";
            cin >> rate;
            account = new SavingsAccount(accNo, holder, bal, rate);
            break;

        case 2:
            cout << "Enter Overdraft Limit: ";
            cin >> limit;
            account = new CheckingAccount(accNo, holder, bal, limit);
            break;

        case 3:
            cout << "Enter Term (Months): ";
            cin >> term;
            cout << "Enter Interest Rate (%): ";
            cin >> rate;
            account = new FixedDepositAccount(accNo, holder, bal, term, rate);
            break;
        }

        // Sub-menu for operations
        int opt;
        while (true) {
            cout << "\n--- Account Menu ---\n";
            cout << "1. Deposit\n";
            cout << "2. Withdraw\n";
            cout << "3. Display Account Info\n";
            cout << "4. Show Interest\n";
            cout << "5. Back to Main Menu\n";
            cout << "Enter option: ";
            cin >> opt;

            if (opt == 5) {
                delete account;
                break;
            }

            double amount;
            switch (opt) {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                account->deposit(amount);
                break;

            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                account->withdraw(amount);
                break;

            case 3:
                account->displayAccountInfo();
                break;

            case 4:
                cout << "Interest = " << account->calculateInterest() << endl;
                break;
            }
        }
    }

    cout << "\nThank you for using the Banking System!\n";
    return 0;
}

