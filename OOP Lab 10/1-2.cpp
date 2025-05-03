#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

int main()
{
    string line;

    ifstream fin;
    fin.open("vehicles.txt");
    if(!fin){
        cerr << "File Not Found!" << endl;
        exit(1);
    }
    int i = 0;
    nl;
    while(getline(fin,line)){
        if(line[0]=='/' || line[0]=='\0'){
            continue;
        }
        istringstream sin(line);
        string type, id, name, year, extra, cert;

        getline(sin, type, ',');
        getline(sin, id, ',');
        getline(sin, name, ',');
        getline(sin, year, ',');
        getline(sin, extra, ',');
        getline(sin, cert, ',');

        cout << "Vehicle: " << i+1 << endl;        
        cout << "Type: " << type << endl;
        cout << "Id: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Year: " << year << endl;
        cout << "Extra Details: " << extra << endl;
        cout << "Certification: " << cert << endl;
        nl;

        i++;
    }
    fin.close();
    return 0;
}