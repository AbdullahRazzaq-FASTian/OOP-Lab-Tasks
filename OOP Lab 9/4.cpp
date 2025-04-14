#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

class PaymentMethod
{
public:
    virtual void processPayment(double amount) = 0;
};

class CreditCard : public PaymentMethod
{
    string cardNumber;

public:
    CreditCard(string num) : cardNumber(num) {}
    void processPayment(double amount)
    {
        int cardNum = stoi(cardNumber);
        if(cardNum >= 0000 && cardNum <= 9999)
            cout << "Validation Successful. Processing Payment.....Amount = " << amount<< "$\n";
        else
            cout << "Validation Unsuccessful. Invalid Card Number\n";
    }
};

class DigitalWallet : public PaymentMethod
{
    double balance;

public:
    DigitalWallet(double balance) : balance(balance){}
    void processPayment(double amount)
    {
        if(amount >= 5000 && amount <= 199999 && amount < balance)
            cout << "Validation Successful. Processing Payment.....Amount = " << amount<< "$\n";
        else
            cout << "Validation Unsuccessful. Insufficient Money\n";
    }
};

int main()
{
    CreditCard CC("345");
    DigitalWallet DW(50000);
    nl;
    CC.processPayment(5000);
    DW.processPayment(5001);
    nl;
    return 0;
}