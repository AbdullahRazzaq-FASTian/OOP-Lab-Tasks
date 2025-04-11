#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

class Dirham
{
private:
    double value;

public:
    Dirham(double value = 0) : value(value) {}

    void setValue(double value) { this->value = value; }

    Dirham operator-() { return Dirham(-value); }
    Dirham operator+(Dirham D) { return Dirham(value + D.value); }
    Dirham operator-(Dirham D) { return Dirham(value - D.value); }
    Dirham &operator+=(const Dirham &D)
    {
        value += D.value;
        return *this;
    }
    Dirham &operator-=(const Dirham &D)
    {
        value -= D.value;
        return *this;
    }
    friend ostream &operator<<(ostream &out, Dirham &D);
    friend istream &operator>>(istream &in, Dirham &D);
};
ostream &operator<<(ostream &out, Dirham &D)
{
    out << "Currency Value: " << D.value << "AED" << endl;
    return out;
}
istream &operator>>(istream &in, Dirham &D)
{
    in >> D.value;
    return in;
}

int main()
{
    Dirham D;
    nl;
    cout << "Extraction Operator" << endl;
    cin >> D;
    nl;
    cout << "Insertion Operator" << endl;
    cout << D;
    nl;
    cout << "Unary Minus Operator" << endl;
    D = -D;
    cout << D;
    nl;
    cout << "Binary Addition Operator" << endl;
    D = D + D;
    cout << D;
    nl;
    cout << "Binary Subtraction Operator" << endl;
    D = D - D;
    cout << D;
    nl;
    cout << "Setting New Value" << endl;
    D.setValue(29.1);
    nl;
    cout << "Addition Assignment Operator" << endl;
    D += D;
    cout << D;
    nl;
    cout << "Subtraction Assignment Operator" << endl;
    D -= D;
    cout << D;
    nl;

    return 0;
}