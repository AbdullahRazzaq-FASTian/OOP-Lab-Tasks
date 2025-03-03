#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;
// 1. Base Class: Person
// o Data Members: name (string), age (int)
// o Member Functions: displayDetails()
// 2. Derived Class: Teacher
// o Data Member: subject (string)
// o Member Functions: displayDetails()
// 3. Derived Class: Researcher
// o Data Member: researchArea (string)
// o Member Functions: displayDetails()
// 4. Derived Class: Professor
// o Data Member: publications (int)
// o Member Functions: displayDetails()

class Person
{
    string name;
    int age;

public:
    Person(string name, int age) : name(name), age(age) {}
    void displayDetails()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Teacher : public Person
{
    string subject;

public:
    Teacher(string name, int age, string subject) : Person(name, age), subject(subject) {}
    void displayDetails()
    {
        Person::displayDetails();
        cout << "Subject: " << subject << endl;
    }
};

class Researcher : public Person
{
    string researchArea;

public:
    Researcher(string name, int age, string researchArea) : Person(name, age), researchArea(researchArea) {}
    void displayDetails()
    {
        Person::displayDetails();
        cout << "Research Area: " << researchArea << endl;
    }
};

class Professor : Teacher, Researcher
{
    int publications;

public:
    Professor(string name, int age, string subject, string researchArea, int publications) : publications(publications) {}
    void displayDetails()
    {
    }
};

int main()
{

    return 0;
}