#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

class Account
{
protected:
    int accountNumber;
    double balance;
    string accountHolderName;
    double transactionHistory[10];
    int transactionNum;

public:
    Account(int accountNumber = 123456789, double balance = 0, string accountHolderName = "")
        : accountNumber(accountNumber), balance(balance), accountHolderName(accountHolderName)
    {
        transactionNum = 0;
    }

    virtual void updateTransaction(string transactionType, double amount)
    {
        if (transactionNum == 10)
        {
            cout << "Max Transaction Occured. Can not update history." << endl;
        }
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

    void deposit(double amount)
    {
        if (amount >= 0)
        {
            balance += amount;
            cout << "Successfully deposited " << amount << " Rs. Remaing balance: " << balance << " Rs." << endl;
            updateTransaction("deposit", amount);
        }
        else
        {
            cout << "Incorrect input\n";
        }
    }

    virtual double withdraw(double amount) = 0;
    virtual double calculateInterest(double amount, double rate, int time) = 0;

    virtual void printStatement() const
    {
        cout << "\n---Transaction History---" << endl;
        for (int i = 0; i < transactionNum; i++)
        {
            cout << "Transaction " << i + 1 << ":" << endl;
            if (transactionHistory[i] < 0)
            {
                cout << "Type: Witdraw" << endl;
                cout << "Ammount: " << -1 * transactionHistory[i] << " Rs." << endl;
            }
            else if (transactionHistory[i] > 0)
            {
                cout << "Type: Deposit" << endl;
                cout << "Ammount: " << transactionHistory[i] << " Rs." << endl;
            }
        }
    }

    virtual void getAccountInfo() const
    {
        cout << "Account Number: " << accountNumber
             << "\nHolder: " << accountHolderName
             << "\nBalance: " << balance << endl;
    }
};

class SavingsAccount : public Account
{
protected:
    double interestRate;
    double minimumBalance;

public:
    SavingsAccount(int accNum, double bal, string holder, double rate, double minBal)
        : Account(accNum, bal, holder), interestRate(rate), minimumBalance(minBal) {}

    double calculateInterest(double amount, double rate, int time) override
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
            cout << "Simple Interest Calculated as: " << interest << " Rs." << endl;
        }
        return interest;
    }

    double withdraw(double amount) override
    {
        if (amount >= 500)
        {
            balance -= amount;
            cout << "Successfully withdrew " << amount << " Rs. Remaing balance: " << balance << " Rs." << endl;
            updateTransaction("withdraw", amount);
            return amount;
        }
        else
        {
            cout << "Minimum balance requirment not met. unable to transact.\n";
            return 0;
        }
    }

    void getAccountInfo() const override
    {
        Account::getAccountInfo();
        cout << "Account Type: Savings Account" << endl;
    }
};

class CheckingAccount : public Account
{
public:
    CheckingAccount(int accNum, double bal, string holder)
        : Account(accNum, bal, holder) {}

    double calculateInterest(double amount, double rate, int time) override
    {
        cout << "Checking accounts do not earn interest." << endl;
        return 0;
    }
    double withdraw(double amount) override
    {
        if (amount >= 0)
        {
            balance -= amount;
            cout << "Successfully withdrew " << amount << " Rs. Remaing balance: " << balance << " Rs." << endl;
            updateTransaction("withdraw", amount);
            return amount;
        }
        else
        {
            cout << "invalid Amount\n";
            return 0;
        }
    }
    void getAccountInfo() const override
    {
        Account::getAccountInfo();
        cout << "Account Type: Checking Account" << endl;
    }
};

class FixedDepositAccount : public Account
{
protected:
    string maturityDate;
    double fixedInterestRate;
    bool flag = false;

public:
    FixedDepositAccount(int accNum, double bal, string holder, string maturity, double rate)
        : Account(accNum, bal, holder), maturityDate(maturity), fixedInterestRate(rate) {}

    double calculateInterest(double amount, double rate, int time) override
    {
        double interest = balance * (fixedInterestRate / 100);
        balance += interest;
        cout << "Fixed Interest Added: " << interest << " Rs."<< endl;
    }
    void isMatured(string currentDate)
    {
        if (currentDate >= maturityDate)
            flag = true;
    }
    double withdraw(double amount) override
    {
        if (!flag)
        {
            cout << "Cannot withdraw! Maturity date not reached yet." << endl;
            return 0;
        }
        else if (amount >= 0)
        {
            balance -= amount;
            cout << "Successfully withdrew " << amount << " Rs. Remaing balance: " << balance << " Rs."<< endl;
            updateTransaction("withdraw", amount);
            return amount;
        }
        else
        {
            cout << "invalid Amount\n";
            return 0;
        }
    }
    void getAccountInfo() const override
    {
        Account::getAccountInfo();
        cout << "Account Type: Fixed Deposit Account" << endl;
    }
};

int main()
{
    SavingsAccount sa(123123, 1000, "Alice", 5.0, 500);
    CheckingAccount ca(658405, 1500, "Bob");
    FixedDepositAccount fda(2947616, 5000, "Charlie", "12-12-2025", 7.0);

    nl;
    sa.deposit(500);
    sa.calculateInterest(1500, 5, 4);
    sa.printStatement();
    
    nl;
    ca.withdraw(100);
    ca.calculateInterest(1600, 5, 4);
    ca.printStatement();

    nl;
    fda.isMatured("13-12-2025");
    fda.withdraw(100);
    fda.calculateInterest(4900, 5, 4);
    fda.printStatement();
    nl;
    return 0;
}