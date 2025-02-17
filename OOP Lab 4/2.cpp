#include "bits.h"
#define nl (cout << endl)
using namespace std;

class Book
{
    string title;
    float price;
    int stock;

public:
    Book()
    {
        title = "Unknown";
        price = 0.0;
        stock = 30;
    }
    Book(string t, float p, int s)
    {
        title = t;
        price = p;
        stock = s;
    }
    void updateTitle(string title)
    {
        this->title = title;
    }
    void updateTitle(float price)
    {
        this->price = price;
    }
    void updateTitle(int stock)
    {
        this->stock = stock;
    }
    bool stockValidation(int copies){
        if (copies < 1)
        {
            cout << "Invalid Input" << endl;
            return false;
        }
        else if (copies > stock)
        {
            cout << "The purchase limit exceed the max. available quantity....i.e: " << stock << endl;
            return false;
        }
        return true;
    }
    int getDiscount(int copies)
    {
        if (copies > 5 && copies < 10)
            return 5;
        else if (copies > 10)
            return 10;
        else 
            return 0;
    }
    void purchaseBook(int copies)
    {
        if(!stockValidation(copies)) return;
        else
        {
            stock -= copies;
            float d = getDiscount(copies)/100.0;
            float totalPrice = copies * price * (1-d);
            if (stock < 5)
                cout << "Low Stock Warning" << endl;
            cout << copies << " " << title << (copies == 1 ? " Book" : " Books") << " puchased for " << totalPrice << "$." << endl;
            cout << "Stock Available = " << stock << endl;
        }
    }
};

int main()
{
    Book b1("Rich Dad Poor Dad", 100, 25);
    b1.purchaseBook(1);
    b1.purchaseBook(6);
    b1.purchaseBook(11);
}