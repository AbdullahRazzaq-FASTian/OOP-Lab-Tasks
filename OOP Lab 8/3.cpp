#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

class Teacher;

class Student
{
private:
    string name;
    float grades[3];

public:
    Student(string name, float g1, float g2, float g3) : name(name)
    {
        grades[0] = g1;
        grades[1] = g2;
        grades[2] = g3;
    }
    friend class Teacher;
    friend float calculateAverage(const Student &S);
};
float calculateAverage(const Student &S)
{
    return (S.grades[0] + S.grades[1] + S.grades[2]) / 3.0;
}

class Teacher
{
public:
    void updateGrade(Student &S, int index, float newGrade)
    {
        if (index < 0 && index > 2)
        {
            cout << "Invalid grade Index" << endl;
        }
        else
        {
            S.grades[index] = newGrade;
            cout << "Grade Updated" << endl;
        }
    }
    void viewGrade(const Student &S)
    {
        cout << "Grades for Student: " << S.name << endl;
        cout << "\tSubject 1: " << S.grades[0] << endl;
        cout << "\tSubject 2: " << S.grades[1] << endl;
        cout << "\tSubject 3: " << S.grades[2] << endl;
    }
};

int main()
{
    Student S("Muhammad Rehan Sidiqui", 99.0, 95.0, 100.0);
    Teacher T;

    nl;
    T.viewGrade(S);
    nl;
    T.updateGrade(S, 1, 98.0);
    nl;
    cout << "Average Grade: " << calculateAverage(S) << endl;
    nl;

    return 0;
}