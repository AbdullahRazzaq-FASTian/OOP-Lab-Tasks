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
        // transactionType = toupper(transactionType);
        if (transactionType == "deposit")
        {
            if (transactionNum < 10)
            {
                transactionHistory[transactionNum++] = 1 * amount;
            }
            else
            {
                for (int i = 0; i < transactionNum - 1; i++)
                {
                    transactionHistory[i] = transactionHistory[i + 1];
                }
                transactionHistory[transactionNum] = 1 * amount;
            }
        }
        else if (transactionType == "withdraw")
        {
            if (transactionNum < 10)
            {
                transactionHistory[transactionNum++] = -1 * amount;
            }
            else
            {
                for (int i = 0; i < transactionNum - 1; i++)
                {
                    transactionHistory[i] = transactionHistory[i + 1];
                }
                transactionHistory[transactionNum] = -1 * amount;
            }
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
            return 0;
        }
        else
        {
            interest = amount * rate * time;
            interest /= 100.0;
            cout << "Simple Interest Calculated as: " << interest << endl;
        }
        return interest;
    }
};

int main()
{

    return 0;
}