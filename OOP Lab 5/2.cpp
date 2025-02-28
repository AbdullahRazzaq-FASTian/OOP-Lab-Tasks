#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

class Patient
{
    static int idCounter;
    int id;
    string name;
    int *test;
    int numTest;

public:
    Patient(int id, string name, int num) : id(id), name(name), numTest(num)
    {
        test = new int[numTest];
        enterTests();
    }
    void enterTests()
    {
        cout << "Enter Tests Details: " << endl;
        for (int i = 0; i < numTest; i++)
        {
            cout << "Test " << i + 1 << ": ";
            cin >> test[i];
        }
    }
    Patient(const Patient &obj)
    {
        id = obj.id;
        name = obj.name;
        numTest = obj.numTest;
        test = new int[numTest];
        for (int i = 0; i < numTest; i++)
        {
            test[i] = obj.test[i];
        }
    }
    void display()
    {
        nl;
        cout << "Patient Id: " << id << endl;
        cout << "Patient Name: " << name << endl;
        cout << "Patient Test scores: " << endl;
        for (int i = 0; i < numTest; i++)
        {
            cout << "Test " << i + 1 << " " << test[i] << endl;
        }
    }
    ~Patient()
    {
        delete[] test;
    }
};
int Patient:: idCounter = 0;

int main()
{
    Patient p1(16, "Muhib Ahmed Khan", 3);
    cout << "\n\tActual Data";
    p1.display();
    Patient analysis(p1);
    cout << "\n\tFor Analysis Purpose";
    analysis.display();
    nl;
    return 0;
}