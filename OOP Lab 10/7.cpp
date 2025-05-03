#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

int main()
{
    ofstream fout("sensor_log.txt");
    nl;
    fout << "Hi, this file is for sensor data";
    cout << "Position of cursor in file after first write: " << fout.tellp() << endl;
    fout << endl;
    nl;
    fout << "Currently writing invisible sensor data";
    cout << "Position of cursor in file after second write: " << fout.tellp() << endl;
    fout << endl;
    fout.close();
    nl;
    
    return 0;
}