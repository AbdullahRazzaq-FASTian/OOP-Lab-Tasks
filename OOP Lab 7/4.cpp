#include <bits/stdc++.h>
#define nl (cout << endl)
#define MAX_STUDENTS 10
using namespace std;

class Person
{
protected:
    string name, address, phoneNumber, email;
    int id;

public:
    Person(string n, int i, string addr, string phone, string mail)
        : name(n), id(i), address(addr), phoneNumber(phone), email(mail) {}
    string getName() const
    {
        return name;
    }
    virtual void displayInfo()
    {
        cout << "Name: " << name << "\nID: " << id
             << "\nAddress: " << address << "\nPhone: " << phoneNumber
             << "\nEmail: " << email << endl;
    }

    void updateInfo(string n, string addr, string phone, string mail)
    {
        name = n;
        address = addr;
        phoneNumber = phone;
        email = mail;
    }
};

class Student : public Person
{
    int enrollmentYear;
    double GPA;
    string coursesEnrolled;

public:
    Student(string n, int i, string addr, string phone, string mail, int year, double gpa, string courses)
        : Person(n, i, addr, phone, mail), enrollmentYear(year), GPA(gpa), coursesEnrolled(courses) {}

    void displayInfo() override
    {
        Person::displayInfo();
        cout << "Enrollment Year: " << enrollmentYear
             << "\nGPA: " << GPA << "\nCourses Enrolled: " << coursesEnrolled << endl;
    }
};

class Professor : public Person
{
    string department, coursesTaught;
    double salary;

public:
    Professor(string n, int i, string addr, string phone, string mail, string dept, string courses, double sal)
        : Person(n, i, addr, phone, mail), department(dept), coursesTaught(courses), salary(sal) {}

    void displayInfo() override
    {
        Person::displayInfo();
        cout << "Department: " << department
             << "\nCourses Taught: " << coursesTaught
             << "\nSalary: $" << salary << endl;
    }
};

class Staff : public Person
{
    string department, position;
    double salary;

public:
    Staff(string n, int i, string addr, string phone, string mail, string dept, string pos, double sal)
        : Person(n, i, addr, phone, mail), department(dept), position(pos), salary(sal) {}

    void displayInfo() override
    {
        Person::displayInfo();
        cout << "Department: " << department
             << "\nPosition: " << position
             << "\nSalary: $" << salary << endl;
    }
};

class Course
{
protected:
    int courseId;
    string courseName;
    int credits;
    Professor *instructor;
    string schedule;
    Student *students[MAX_STUDENTS];
    int studentCnt;

public:
    Course(int courseId, string courseName, int credits, Professor *instructor, string schedule)
        : courseId(courseId), courseName(courseName), credits(credits), instructor(new Professor(*instructor)),
          schedule(schedule), studentCnt(0)
    {
        for (int i = 0; i < MAX_STUDENTS; i++)
        {
            students[i] = nullptr;
        }
    }

    void registerStudent(Student &student)
    {
        if (studentCnt < MAX_STUDENTS)
        {
            students[studentCnt++] = &student;
            cout << "Student " << studentCnt << " registered for " << courseName << endl;
        }
        else
        {
            cout << "Course is full, cannot register more students." << endl;
        }
    }

    void calculateGrade(Student &s)
    {
        cout << s.getName() << " has been graded for " << courseName << endl;
    }

    void displayCourseInfo()
    {
        cout << "Course ID: " << courseId << "\nCourse Name: " << courseName
             << "\nCredits: " << credits << "\nInstructor: " << instructor
             << "\nSchedule: " << schedule << "\nEnrolled Students: " << studentCnt << endl;
    }
};

int main()
{
    // In the main function im highlighting only the main methods of class to give a sample output run

    Professor prof("Dr. Smith", 1001, "123 University Ave", "123-456-7890", "smith@university.com", "Computer Science", "Data Structures", 90000.0);

    Student s1("Alice", 101, "456 Elm St", "987-654-3210", "alice@mail.com", 2022, 3.8, "CS101");
    Student s2("Bob", 102, "789 Maple Dr", "111-222-3333", "bob@mail.com", 2021, 3.5, "CS101");

    cout << "\n=== Updating Student Info ===\n";
    s1.updateInfo("Alice Johnson", "456 Elm St, Apt 5", "987-654-3211", "alice.johnson@mail.com");
    s1.displayInfo();
    nl;

    Course cs101(301, "Data Structures", 3, &prof, "MWF 10AM");

    cout << "\n=== Course Enrollment ===\n";
    cs101.registerStudent(s1);
    cs101.registerStudent(s2);
    nl;

    cout << "\n=== Grade Calculation ===\n";
    cs101.calculateGrade(s1);
    cs101.calculateGrade(s2);
    nl;


    return 0;
}
