#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

class Battery{
    int capacity;
    string type;
    float voltage;
public:
    void setCapacity(int capacity) {this->capacity = capacity;}
    void setType(string type) {this->type = type;}
    void setVoltage(float voltage) {this->voltage = voltage;}

    int getCapacity() const {return capacity;}
    string getType() const {return type;}
    float getVoltage() const {return voltage;}   
};

class Smartphone {
    string brand;
    string model;
    Battery battery;
public:
    Smartphone(string brand, string model, int capacity, string type, float voltage){
        this->brand = brand;
        this->model = model;
        battery.setCapacity(capacity);
        battery.setType(type);
        battery.setVoltage(voltage);
    }
    void display(){
        cout << "Smartphone Details\n";
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Battery Details\n";
        cout << "Capacity: " << battery.getCapacity() << "mAh" << endl;
        cout << "Type: " << battery.getType() << endl;
        cout << "Voltage: " << battery.getVoltage() << "V" << endl;
    }
};

int main()
{
    Smartphone phone1("Samsung", "Galaxy S23", 5000, "Li-Ion", 3.85);
    Smartphone phone2("Apple", "iPhone 14", 4323, "Li-Po", 3.7);

    nl;
    phone1.display();
    nl;
    phone2.display();
    nl;

    return 0;
}