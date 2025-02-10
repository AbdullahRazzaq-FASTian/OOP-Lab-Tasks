#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

class TeaMug{
    private:
        int currentFillLevel; // By default 100%
    public:
        string brand;
        string color;
        int capacity;

        void set(){
            currentFillLevel = capacity;
        }
        void sip(int amount) {
            if(currentFillLevel>0){
                currentFillLevel -= amount;
                if(currentFillLevel<0) currentFillLevel = 0;
                cout << "Siping..... Current Tea Level: " << currentFillLevel << "ml" << endl;
            }
            else
                cout << "Mug is Out of tea....It's time for a fresh cup-can." << endl;
        }
        void refill() {
            currentFillLevel = 100;
            cout << "Mug Refilled. Enjoy your Tea." << endl;
        }
        bool isEmpty(){
            return currentFillLevel == 0;
        }
        void status() {
            cout << "Mug Brand: " << brand << endl;
            cout << "Mug Color: " << color << endl;
            cout << "Mug Capacity: " << capacity << "ml" << endl;
        }
};

int main()
{
    TeaMug m1;
    m1.brand = "Starbucks", m1.color = "White", m1.capacity = 250;
    m1.set();
    m1.sip(100);
    m1.sip(50);
    m1.refill();
    if(m1.isEmpty()) cout << "The Mug is Empty....Need a fresh one" <<endl;
    m1.status();
    return 0;
}