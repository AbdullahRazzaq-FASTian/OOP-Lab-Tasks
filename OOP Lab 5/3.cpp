#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

class Professor{
    string name;
    string department;
public:
    Professor(string name, string dep) : name(name), department(dep) {}
    string getName() const {return name;}
    string getDepartment() const {return department;}
};

class University{
    Professor** profList;
    int currentProf;
public:
    University() : currentProf(0) {
        profList = new Professor*[currentProf];
    }
    void addProf(Professor& Prof) {
        Professor** temp = new Professor*[currentProf+1];
        for(int i=0; i<currentProf; i++){
            temp[i] = profList[i];
        }
        delete[] profList;
        profList = temp;
        profList[currentProf] = new Professor(Prof);
        currentProf++;
    }
    void display() {
        if(currentProf == 0){
            cout << "There is no Professor Added!\n";
        }
        else{
            cout << left << setw(20) << "Professor Name" << setw(20) << "Department" << endl;
            for(int i=0; i<currentProf; i++){
                cout << left << setw(20) << profList[i]->getName() << setw(20) << profList[i]->getDepartment() << endl;
            }
        }
    }
};

int main()
{
    Professor prof1("Talha Shahid","Cyber");
    Professor prof2("Basit Ali","CS");
    Professor prof3("Dr. Shahnawaz","Social");

    University uni;
    uni.addProf(prof1);
    uni.addProf(prof2);
    uni.addProf(prof3);
    uni.display();

    return 0;
}