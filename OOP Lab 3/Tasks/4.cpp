#include "iostream"
#include "string"
#define nl (cout << endl)
using namespace std;

class Laptop
{
private:
    string ownerName;
    string brand;
    string model;
    string processor;
    int RAM;
    int storage;

public:
    Laptop() {} // Defautlt Constructor
    Laptop(string ownerName, string brand, string model, string processor, int RAM, int storage)
    {
        this->ownerName = ownerName;
        this->brand = brand;
        this->model = model;
        this->processor = processor;
        this->RAM = RAM;
        this->storage = storage;
    }
    bool isOn = false;
    void turnPC(string turn)
    {
        if (turn == "On")
        {
            isOn = true;
            cout << "Computer is now On\n";
        }
        else
        {
            isOn = false;
            cout << "Computer is now Off\n";
        }
    }
    void runProgram(string Program)
    {
        if (isOn)
        {
            cout << "Running " << Program << " on " << brand << " " << model << "....\n";
        }
        else
        {
            cout << "PC is turned off!\n";
        }
    }
    void checkSpecification()
    {
        cout << "---" << ownerName << "---\n";
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Processor: " << processor << endl;
        cout << "RAM: " << RAM << " GB" << endl;
        cout << "Storage: " << storage << " GB" << endl;
    }
};

int main()
{
    Laptop Bilal("Bilal", "Dell", "XPS 13", "Intel i7", 16, 512);
    Laptop Ayesha("Ayesha", "HP", "Pavilion", "Intel i3", 32, 1024);
    Bilal.turnPC("On");
    Bilal.runProgram("Chrome");
    Bilal.checkSpecification();
    return 0;
}