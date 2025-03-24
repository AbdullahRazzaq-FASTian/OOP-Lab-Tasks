#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

class Currency
{
protected:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRate;

public:
    Currency(double amount, string code, string symbol, double rate)
        : amount(amount), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}

    string getSymbol() const
    {
        return currencySymbol;
    }

    virtual double convertToBase() const
    {
        return amount * exchangeRate;
    }

    virtual double convertTo(Currency targetCurrency)
    {
        return convertToBase() / targetCurrency.exchangeRate;
    }

    virtual void displayCurrency()
    {
        cout << "Currency Code: " << currencyCode
             << "\nCurrency Symbol: " << currencySymbol
             << "\nAmount: " << amount;
    }
};

class Dollar : public Currency
{
public:
    Dollar(double amount) : Currency(amount, "USD", "$", 1.0) {}

    void displayCurrency() override
    {
        Currency::displayCurrency();
        cout << "\nExchange Rate: " << exchangeRate << endl;
    }
};

class Euro : public Currency
{
public:
    Euro(double amount) : Currency(amount, "EUR", "€", 1.1) {}

    void displayCurrency() override
    {
        Currency::displayCurrency();
        cout << "\nExchange Rate: " << exchangeRate << endl;
    }
};

class Rupee : public Currency
{
public:
    Rupee(double amount) : Currency(amount, "PKR", "Rs.", 0.35) {}

    void displayCurrency() override
    {
        Currency::displayCurrency();
        cout << "Exchange Rate: " << exchangeRate << endl;
    }
};

int main()
{
    Dollar usd(100);
    Euro eur(0);
    Rupee pkr(0);

    cout << "--- Initial Currency Details ---" << endl;
    usd.displayCurrency();

    cout << "--- Converted Currency ---" << endl;
    // Convert 100 USD to Euro
    double convertedEur = usd.convertTo(eur);
    cout << "\n100 USD in Euro: " << convertedEur << " " << eur.getSymbol() << endl;

    // Convert 100 USD to Pakistani Rupees
    double convertedPkr = usd.convertTo(pkr);
    cout << "100 USD in PKR: " << convertedPkr << " " << pkr.getSymbol() << endl;
    nl;

    return 0;
}