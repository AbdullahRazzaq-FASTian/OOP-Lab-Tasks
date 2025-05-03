#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

int main()
{
    string line;
    ifstream fin("large_log.txt");
    nl;
    getline(fin, line);
    cout << "Position after first reading: " << fin.tellg() << endl;
    nl;
    getline(fin, line);
    cout << "Position after second reading: " << fin.tellg() << endl;
    nl;
    getline(fin, line);
    fin.clear();
    cout << "Position after third reading: " << fin.tellg() << endl;
    nl;
    fin.close();
    return 0;
}