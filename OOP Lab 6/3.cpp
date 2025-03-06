#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

class Person
{
protected:
    string name;
    int age;

public:
    Person(string name = "", int age = 0) : name(name), age(age) {}
    void displayDetails()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Teacher : virtual public Person
{
protected:
    string subject;

public:
    Teacher(string name = "", int age = 0, string subject = "") : Person(name, age), subject(subject) {}
    void displayDetails()
    {
        Person::displayDetails();
        cout << "Subject: " << subject << endl;
    }
};

class Researcher : virtual public Person
{
protected:
    string researchArea;

public:
    Researcher(string name = "", int age = 0, string researchArea = "") : Person(name, age), researchArea(researchArea) {}
    void displayDetails()
    {
        Person::displayDetails();
        cout << "Research Area: " << researchArea << endl;
    }
};

class Professor : Teacher, Researcher
{
protected:
    int publications;

public:
    Professor(string name = "", int age = 0, string subject = "", string researchArea = "", int publications = 0) 
        : Person(name, age), 
          Teacher(name, age, subject), 
          Researcher(name, age, researchArea), 
          publications(publications) {}
        
    void displayDetails() {
        Person::displayDetails();
        cout << "Subject: " << subject << endl;
        cout << "Research Area: " << researchArea << endl;
        cout << "Publications: " << publications << endl;
    }
};

int main()
{
    nl;
    Professor prof("Usama Antuley", 41, "Calculus", "Artificial Intelligence", 25);
    prof.displayDetails();
    nl;
    return 0;
}