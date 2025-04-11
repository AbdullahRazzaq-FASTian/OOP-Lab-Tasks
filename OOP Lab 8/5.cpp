#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

float calculateGcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

class Fraction
{
    float num;
    float den;

public:
    Fraction(float num, float den) : num(num), den(den) {}

    Fraction operator+(Fraction F)
    {
        float numR = (num * F.den) + (F.num * den);
        float denR = (den * F.den);
        float gcd = calculateGcd(numR, denR);
        return Fraction(numR/gcd, denR/gcd);
    }

    Fraction operator-(Fraction F)
    {
        float numR = (num * F.den) - (F.num * den);
        float denR = (den * F.den);
        float gcd = calculateGcd(numR, denR);
        return Fraction(numR/gcd, denR/gcd);
    }

    Fraction operator*(Fraction F)
    {
        float numR = (num * F.num);
        float denR = (den * F.den);
        float gcd = calculateGcd(numR, denR);
        return Fraction(numR/gcd, denR/gcd);
    }

    Fraction operator/(Fraction F)
    {
        float numR = (num * F.den);
        float denR = (den * F.num);
        float gcd = calculateGcd(numR, denR);
        return Fraction(numR/gcd, denR/gcd);
    }

    friend ostream &operator<<(ostream &os, Fraction &F)
    {
        os << F.num << "/" << F.den;
        return os;
    }
};

int main()
{
    Fraction fracA(5, 2);
    Fraction fracB(3, 4);

    Fraction fracAdd = fracA + fracB;
    Fraction fracSub = fracA - fracB;
    Fraction fracMul = fracA * fracB;
    Fraction fracDiv = fracA / fracB;

    nl;
    cout << "Frac A: " << fracA << endl;
    cout << "Frac B: " << fracB << endl;
    nl;
    cout << "Frac Add: " << fracAdd << endl;
    cout << "Frac Sub: " << fracSub << endl;
    cout << "Frac Mul: " << fracMul << endl;
    cout << "Frac Div: " << fracDiv << endl;
    nl;

    return 0;
}