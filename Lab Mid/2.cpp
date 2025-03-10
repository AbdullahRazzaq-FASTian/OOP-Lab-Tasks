#include <bits/stdc++.h>
#define GETTER(type, var) \
    type get_##var() const { return var; }
#define SETTER(type, var) \
    void set_##var(type val) { this->var = val; }
#define nl (cout << endl)
using namespace std;

class Course
{
    static int id_counter;
    int id;
    string name;
    string instructor;
    bool availability;

public:
    Course(string name = "", string instructor = "", bool avaialablity = true)
        : name(name), instructor(instructor), availability(availability) { id = id_counter++; }

    GETTER(int, id)
    GETTER(string, name)
    GETTER(string, instructor)
    GETTER(bool, availability)
    Course* get_course() {return this;}

    SETTER(bool, availability)

    void display()
    {
        cout << "Course ID: " << id << endl;
        cout << "Course Name: " << name << endl;
        cout << "Course Instructor: " << instructor << endl;
        cout << "Course Availability: " << (availability ? "Opened" : "Closed") << endl;
    }
};
int Course::id_counter = 0;

class CourseManagement
{
    Course *course = nullptr;
    int courses;
    int capacity;

public:
    CourseManagement(int capacity) : capacity(capacity)
    {
        course = new Course[capacity];
        courses = 0;
    }
    GETTER(int, courses)

    void add_course(string name, string instructor)
    {
        if (courses < capacity)
        {
            course[courses] = Course(name, instructor);
            courses++;
        }
        else
        {
            cout << "Capacity Full\n";
        }
    }

    void display_all()
    {
        if (courses == 0)
        {
            cout << "There is no course currently\n";
            return;
        }
        cout << "Totle Courses = " << courses << endl;
        for (int i = 0; i < courses; i++)
        {
            cout << "Course " << i + 1 << ":\n";
            course[i].display();
        }
    }

    Course* find_course(int id)
    {
        int i;
        for (i = 0; i < courses; i++)
        {
            if (course[i].get_id() == id)
            {
                break;
            }
        }
        if (i == courses)
            cout << "Course wasn't found\n";
        else{
            cout << "Course Found\n";
        }
        return course[i].get_course();
    }

    void toggle_avaialablity(int id)
    {
        int i;
        for (i = 0; i < courses; i++)
        {
            if (course[i].get_id() == id)
            {
                break;
            }
        }
        if (i == courses)
            cout << "Course wasn't found\n";
        else
        {
            if (course[i].get_availability() == false)
                course[i].set_availability(true);
            else
                course[i].set_availability(false);
        }
    }
};

int main()
{
    CourseManagement Fast(2);
    Fast.add_course("PF","Fahad Hussain");
    Fast.add_course("OOP","Talha Shahid");

    Fast.display_all();
    return 0;
}