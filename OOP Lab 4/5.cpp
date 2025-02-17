#include "bits.h"
#define nl (cout << endl)
using namespace std;

class Book
{
    string title;
    float price;
    int stock;
    int bookId;
    static int idCounter;

public:
    Book()
    {
        title = "Unknown";
        price = 0.0;
        stock = 30;
    }
    Book(string t, float p, int s) : title(t), price(p), stock(s), bookId(++idCounter) {}
    Book(const Book &obj)
    { // Copy Constructor
        title = obj.title;
        price = obj.price;
        stock = obj.stock;
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
    void displayBook()
    {
        cout << "Book ID: " << bookId << endl;
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
        cout << "Stock: " << stock << endl;
    }
    bool stockValidation(int copies)
    {
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
    float calculatePrice(int copies)
    {
        float basePrice = this->price;
        float discount = getDiscount(copies); // Discount Percentage
        discount /= 100.0;
        float totalPrice = copies * basePrice * (1 - discount);
        return totalPrice;
    }
    void purchaseBook(int copies)
    {
        if (!stockValidation(copies))
            return;
        else
        {
            stock -= copies;
            float totalPrice = calculatePrice(copies);
            cout << copies << " " << title << (copies == 1 ? " Book" : " Books") << " puchased for " << totalPrice << "$." << endl;
            cout << "Stock Available = " << stock << endl;
            if (stock < 5)
                cout << "Low Stock Warning" << endl;
        }
    }
    ~Book()
    {
        cout << "Destroying Book.... " << title << endl;
        cout << "Object Memory Released." << endl;
    }
};

int Book::idCounter = 0;

int main()
{
    Book b1("Rich Dad Poor Dad", 100, 25);
    Book b2("Atomic Habits", 120, 30);
    Book b3("The 48 Laws of Power", 150, 10);

    b1.displayBook();
    b2.displayBook();
    b3.displayBook();

    return 0;
}