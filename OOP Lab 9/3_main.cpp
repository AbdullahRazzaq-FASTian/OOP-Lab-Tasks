#include <bits/stdc++.h>
#include "Book.h"
#define nl (cout << endl)
using namespace std;

int main()
{
    Book B("Unknown", "Anonymous", "XXX-XXXXXX");
    nl;
    cout << "Book Title: " << B.getTitle() << endl;
    cout << "Author: " << B.getAuthor() << endl;
    cout << "ISBN: " << B.getISBN() << endl;
    nl;

    return 0;
}
//g++ 3_main.cpp Book.cpp -o 3.exe