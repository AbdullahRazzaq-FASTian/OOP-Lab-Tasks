#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

class InvalidValueException : public exception
{
public:
    const char* what() const noexcept override{
        return "Age cannot be negative or exceed 120.";
    }
};

void validateAge(int age){
    if(age < 0 || age > 120) throw InvalidValueException();
    else cout << "Age is valid" << endl;
}

int main()
{
    nl;
    try{
        validateAge(15);
    }
    catch (InvalidValueException& e){
        cout << "Exception caught: " << e.what() << endl;
    }
    try{
        validateAge(-15);
    }
    catch (InvalidValueException& e){
        cout << "Exception caught: " << e.what() << endl;
    }
    try{
        validateAge(150);
    }
    catch (InvalidValueException& e){
        cout << "Exception caught: " << e.what() << endl;
    }
    nl;
    return 0;
}