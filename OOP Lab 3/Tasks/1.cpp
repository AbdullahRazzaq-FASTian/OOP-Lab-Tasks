#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

class MarkerPen{
    private:
        int inkLevel = 100; // By default 100%
    public:
        bool refillabile;
        string brand;
        string color;

        void write(int amount) {
            if(inkLevel>0){
                inkLevel -= amount;
                if(inkLevel<0) inkLevel = 0;
                cout << "Current Ink level is: " << inkLevel << "%" << endl;
            }
            else
                cout << "Marker is out of Ink." << endl;
        }
        void refill() { 
            if(refillabile){
                inkLevel = 100;
                cout << "Marker Refilled. Current Ink level is: " << inkLevel << "%" << endl;
            }    
            else
                cout << "This marker isn't Refillable." << endl;
        }
        void status() {
            cout << "Marker Brand: " << brand << endl;
            cout << "Marker Color: " << color << endl;
            cout << "Marker Refillability: " << (refillabile? "Yes" : "No") << endl;
        }
};

int main()
{
    MarkerPen m1;
    m1.brand = "Dollar", m1.color = "Blue", m1.refillabile = true;
    m1.write(100);
    m1.write(1);
    m1.refill();
    m1.status();
    return 0;
}