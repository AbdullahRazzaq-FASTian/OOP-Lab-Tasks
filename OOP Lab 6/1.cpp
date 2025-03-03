#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

class Employee
{
protected:
    string name;
    float salary;

public:
    Employee(string name, float salary) : name(name), salary(salary) {}
    void displayDetails()
    {
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }
};
class Manager : public Employee
{
    float bonus;

public:
    Manager(string name, float salary, float bonus) : Employee(name, salary), bonus(bonus) {}
    void displayDetails()
    {
        Employee::displayDetails();
        cout << "Bonus: " << bonus << endl;
    }
};

int main()
{
    Manager m1("Muzammil", 29000, 5000);
    m1.displayDetails();
    return 0;
}