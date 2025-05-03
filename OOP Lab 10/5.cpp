#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

int main()
{
    string line;

    ifstream fin;
    fin.open("vehicles.txt");
    if (!fin)
    {
        cerr << "File Not Found!" << endl;
        exit(1);
    }
    int i = 1;
    nl;
    while (getline(fin, line))
    {
        if (line[0] == '/' || line[0] == '\0')
        {
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

        cout << "Vehicle: " << i << endl;
        if (type == "AutonomousCar")
        {
            float SW;
            size_t pos = extra.find(':');
            if (pos != string::npos)
            {
                SW = stof(extra.substr(pos + 1));
                cout << "SW for the Vehicle is: " << SW << endl;
            }
            else
            {
                cout << "Data not found" << endl;
            }
        }
        else if (type == "ElectricVehicle")
        {
            int batteryLvl;
            size_t pos = extra.find(':');
            if (pos != string::npos)
            {
                batteryLvl = stoi(extra.substr(pos + 1));
                cout << "Battery Lvl of the Vehicle is: " << batteryLvl << endl;
            }
            else
            {
                cout << "Data not found" << endl;
            }
        }
        else if (type == "HybridTruck")
        {
            int batteryLvl, cargo;

            size_t posColon = extra.find(':');
            size_t posPipe = extra.find('|');

            if (posColon == string::npos && posPipe == string::npos)
            {
                cout << "Data not found" << endl;
            }
            if (posColon != string::npos)
            {
                cargo = stoi(extra.substr(posColon + 1, posPipe - (posColon + 1)));
                cout << "Cargo for the Vehicle is: " << cargo << endl;
            }
            if (posPipe != string::npos)
            {
                batteryLvl = stoi(extra.substr(posPipe + 9));
                cout << "Battery Lvl of the Vehicle is: " << batteryLvl << endl;
            }
        }
        else
        {
            cout << "Unknown Vehicle!" << endl;
        }
        nl;
        i++;
    }
    fin.close();
    return 0;
}