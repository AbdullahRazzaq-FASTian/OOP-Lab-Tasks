#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

class TourGuide {
    string name;
    int yearOfExperience;
    string specialization;

public:
    TourGuide(string name, int exp, string special) : name(name), yearOfExperience(exp), specialization(special) {}

    string getName() const { return name; }
    int getExp() const { return yearOfExperience; }
    string getSpecialization() const { return specialization; }
};

class TravelAgency {
    TourGuide** guideList;
    int currentGuides;

public:
    TravelAgency() : currentGuides(0) {
        guideList = nullptr;
    }

    ~TravelAgency() {
        for (int i = 0; i < currentGuides; i++) {
            delete guideList[i];
        }
        delete[] guideList;
    }

    void addGuide(TourGuide& Guide) {
        TourGuide** temp = new TourGuide * [currentGuides + 1];
        for (int i = 0; i < currentGuides; i++) {
            temp[i] = guideList[i];
        }
        delete[] guideList;
        guideList = temp;
        guideList[currentGuides] = new TourGuide(Guide);
        currentGuides++;
    }

    void display() {
        if (currentGuides == 0) {
            cout << "There is no Tour Guide yet!\n";
        } else {
            cout << left << setw(20) << "Name" << setw(20) << "Experience" << setw(20) << "Specialization" << endl;
            for (int i = 0; i < currentGuides; i++) {
                cout << left << setw(20) << guideList[i]->getName()
                     << setw(20) << guideList[i]->getExp()
                     << setw(20) << guideList[i]->getSpecialization() << endl;
            }
        }
    }
};

int main() {
    TravelAgency agency;

    TourGuide guide1("John Doe", 10, "Historical Tours");
    TourGuide guide2("Alice Smith", 7, "Adventure Tours");
    TourGuide guide3("Michael Lee", 5, "Cultural Tours");

    agency.addGuide(guide1);
    agency.addGuide(guide2);
    agency.addGuide(guide3);

    nl;
    agency.display();
    nl;

    return 0;
}
