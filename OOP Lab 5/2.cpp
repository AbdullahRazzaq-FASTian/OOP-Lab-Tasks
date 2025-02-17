#include "bits.h"
using namespace std;
class Patient
{
    int id;
    string name;
    int *test;
    int numTest;

public:
    void enterTests()
    {
        test = new int[numTest];
        cout << "Enter Tests Details: " << endl;
        for (int i = 0; i < numTest; i++)
        {
            cout << "Test " << i + 1 << " ";
            cin >> test[i];
        }
    }
    Patient(int i, string n, int num) : id(i), name(n), numTest(num) { enterTests(); }
    Patient(const Patient &obj)
    {
        id = obj.id;
        name = obj.name;
        numTest = obj.numTest;
        test = obj.test;
    }
    void display()
    {
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
int main()
{
    Patient p1(16, "Muhib Ahmed Khan", 3);
    p1.display();
    Patient analysis(p1);
    analysis.display();
    return 0;
}