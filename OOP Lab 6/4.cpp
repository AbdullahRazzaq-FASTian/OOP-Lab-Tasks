#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

class Account
{
    int accountNumber;
    float balance;

public:
    Account(int accountNumber, float balance)
        : accountNumber(accountNumber),
          balance(balance) {}

    void displayDetails()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

class SavingsAccount: public Account
{
    float interestRate;

public:
    SavingsAccount(int accountNumber, float balance, float interestRate) 
        : Account(accountNumber,balance),
          interestRate(interestRate) {}
        
    void displayDetails() {
        Account::displayDetails();
        cout << "Interest Rate: " << interestRate << endl;
    }
};

class CheckingAccount: public Account
{
    float overdraftLimit;

public:
    CheckingAccount(int accountNumber, float balance, float overdraftLimit) 
        : Account(accountNumber,balance),
          overdraftLimit(overdraftLimit) {}
        
    void displayDetails() {
        Account::displayDetails();
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};

int main()
{
    SavingsAccount savings(101, 5000.0, 3.5);
    CheckingAccount checking(102, 2000.0, 1000.0);

    nl;
    cout << "Savings Account Details:" << endl;
    savings.displayDetails();
    nl;

    nl;
    cout << "Checking Account Details:" << endl;
    checking.displayDetails();
    nl;
    return 0;
}