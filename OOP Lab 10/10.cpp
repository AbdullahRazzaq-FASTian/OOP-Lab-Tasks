#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

int main()
{
    ifstream fin("data_record.txt");
    //The records before third one have total bytes of 9 or offset = 9
    fin.seekg(20, ios::beg);
    string record;
    getline(fin, record);
    cout << record << endl;
    fin.close();
    return 0;
}