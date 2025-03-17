#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

typedef enum Type
{
    current = 1,
    saving = 2
} Type;

class Account
{
    int accountNumber;
    double balance;
    string accountHolderName;
    Type accountType;
    double transactionHistory[10];
    int transactionNum;

public:
    Account(int accountNumber = 123456789, double balance = 0, string accountHolderName = "", Type accountType = current)
        : accountNumber(accountNumber), balance(balance), accountHolderName(accountHolderName), accountType(accountType)
    {
        transactionNum = 0;
    }

    void updateTransaction(string transactionType, double amount)
    {
        if (transactionType == "deposit")
        {
            transactionHistory[transactionNum++] = 1 * amount;
        }
        else if (transactionType == "withdraw")
        {
            transactionHistory[transactionNum++] = -1 * amount;
        }
        else
            cout << "Incorrect Input\n";
    }

    void depositAmount(double amount)
    {
        if (amount >= 0)
        {
            balance += amount;
            cout << "Successfully deposited " << amount << "Rs. Remaing balance: " << balance << endl;
            updateTransaction("deposit", amount);
        }
        else
        {
            cout << "Incorrect input\n";
        }
    }

    double withdraw(double amount)
    {
        if (amount >= 0)
        {
            balance -= amount;
            cout << "Successfully withdrew " << amount << "Rs. Remaing balance: " << balance << endl;
            updateTransaction("withdraw", amount);
            return amount;
        }
        else
        {
            cout << "Incorrect input\n";
            return -1;
        }
    }

    double calculateInterest(double amount, double rate, int time)
    {
        double interest = 0;
        if (amount < 0 && rate < 0 && time < 0)
        {
            cout << "Incorrect Input\n";
            return -1;
        }
        else
        {
            interest = amount * rate * time;
            interest /= 100.0;
            cout << "Simple Interest Calculated as: " << interest << endl;
        }
        return interest;
    }
    void printStatement()
};

int main()
{

    return 0;
}