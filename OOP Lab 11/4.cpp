#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

class NegativeNumberException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Input must be non-negative!";
    }
};

class InvalidTypeException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Non-numeric type detected!";
    }
};

template<typename T>
T mySqrt(T num) {
    throw InvalidTypeException();
}

template<>
int mySqrt<int>(int num) {
    if (num < 0)
        throw NegativeNumberException();
    return static_cast<int>(sqrt(num));
}

template<>
double mySqrt<double>(double num) {
    if (num < 0)
        throw NegativeNumberException();
    return sqrt(num);
}

int main()
{
    nl;
    try{
        string sq = mySqrt<string>("Abdullah");
    }
    catch (InvalidTypeException& e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    catch (NegativeNumberException& e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    try{
        double squared = mySqrt<double>(-4.5);
    }
    catch (InvalidTypeException& e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    catch (NegativeNumberException& e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    nl;
    return 0;
}