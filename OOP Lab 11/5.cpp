#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

template <class X>
class InsufficientFundException
{
public:
    X deficit;
    InsufficientFundException(X deficit) : deficit(deficit) {}
    void displayException() const noexcept
    {
        cout << "Deficit: $" << deficit << endl;
    }
};

template <class T>
class BankAccount
{
private:
    T balance;

public:
    BankAccount(T balance) : balance(balance) {}
    void withdraw(T amount)
    {
        if (amount > balance)
            throw InsufficientFundException<T>(amount - balance);
        balance -= amount;
    }
};

int main()
{
    BankAccount<double> acc(350.60);
    nl;
    try
    {
        acc.withdraw(400.99);
    }
    catch (InsufficientFundException<double> &e)
    {
        cout << "Insufficient Balance: ";
        e.displayException();
        nl;
    }
    return 0;
}