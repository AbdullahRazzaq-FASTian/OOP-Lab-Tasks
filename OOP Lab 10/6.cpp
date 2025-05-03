#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

struct InventoryItem{
    int id;
    char name[20];
};

class FileHandler
{
private:
    ifstream fin;
    ofstream fout;

public:
    void writeFile(string fileName, InventoryItem& s)
    {
        fout.open(fileName, ios::binary);
        fout.write((char*)&s, sizeof(s));
        cout << "Successfully written content" << endl;
        fout.close();
    }
    void readFile(string fileName, InventoryItem& s)
    {
        fin.open(fileName, ios::binary);
        fin.read((char*)&s, sizeof(s));
        cout << "Successfully read content" << endl;
        fin.close();
    }
};

int main()
{
    InventoryItem s1 = {101, "Shahmir"};
    InventoryItem s2;

    FileHandler f1, f2;

    f1.writeFile("inventory.dat", s1);
    f1.readFile("inventory.dat", s2);

    nl;
    cout << "Item Id: " << s2.id << endl;
    cout << "Item Name: " << s2.name << endl;
    nl;

    return 0;
}