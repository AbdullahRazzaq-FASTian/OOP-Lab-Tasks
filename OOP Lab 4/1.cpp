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
    void updateTitle(string title)
    {
        this->title = title;
    }
    void updatePrice(float price)
    {
        this->price = price;
    }
    void updateStock(int stock)
    {
        this->stock = stock;
    }
     void purchaseBook(int copies)
    {
        if (copies < 1)
        {
            cout << "Invalid Input" << endl;
            return;
        }
        else if (copies > stock)
        {
            cout << "Not enough book." << endl;
            return;
        }
        else
        {
            stock -= copies;
            float totalPrice = copies * price;
            if (stock < 5)
                cout << "Low Stock Warning" << endl;
            cout << copies << " " << title << (copies == 1 ? " Book" : " Books") << " puchased for " << totalPrice << "$." << endl;
            cout << "Stock Available = " << stock << endl;
        }
    }
};

int main()
{
    Book b1;
    b1.updateTitle("Rich Dad Poor Dad");
    b1.updatePrice(100);
    b1.updateStock(15);
    b1.purchaseBook(1);
    b1.purchaseBook(5);
    b1.purchaseBook(3);
}