#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

class Librarian;

class Book {
private:
    string title;
    double price;

public:
    Book(string t, double p) : title(t), price(p) {}
    friend class Librarian;
};

class Librarian {
public:
    void displayBookDetails(const Book& book) {
        cout << "Book Title: " << book.title << endl;
        cout << "Book Price: $" << book.price << endl;
    }

    void applyDiscount(Book& book, double discount) {
        book.price -= discount;
        cout << "Discounted Price: $" << book.price << endl;
    }
};

int main() {
    Book book("C++ Programming", 45.99);
    Librarian librarian;

    nl;
    librarian.displayBookDetails(book);
    nl;
    librarian.applyDiscount(book, 10.00);
    nl;

    return 0;
}