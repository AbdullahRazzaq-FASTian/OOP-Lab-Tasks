#include <bits/stdc++.h>
#define GETTER(type, var) \
    type get_##var() const { return var; }
#define SETTER(type, var) \
    void set_##var(type val) { this->var = val; }
#define nl (cout << endl)
using namespace std;

class book
{
    int id;
    string title;
    double price;
    string publisher_name;
    static int counter;

public:
    book(int id = 0, string title = "", double price = 0, string publisher_name= "")
        : id(id), title(title), price(price), publisher_name(publisher_name) { counter++; }

    book(book &obj)
    {
        this->id = obj.id;
        this->title = obj.title;
        this->price = obj.price;
        this->publisher_name = obj.publisher_name;
    }

    GETTER(int, id)
    GETTER(string, title)
    GETTER(double, price)
    GETTER(string, publisher_name)
    static int get_counter() { return counter; }

    int countBook() const { return counter; }

    void display()
    {
        cout << "Book Id: " << id << endl;
        cout << "Book Title: " << title << endl;
        cout << "Book Price: " << price << endl;
        cout << "Book Publisher: " << publisher_name << endl;
    }
};
int book::counter = 0;

int main()
{
    book b[2];
    b[0] = book(101, "Oxford University Press", 2000, "Anonymous");
    b[1] = book(102, "Sang e Meel", 1900, "Anonymous");

    // book b_copy(b[0]);

    for (int i = 0; i < book::get_counter(); i++)
    {
        cout << "\tBook " << i+1 << ":\n";
        b[i].display();
    }

    // int id;
    // cout << "Enter id of Book to search: ", cin >> id;
    // int i;
    // for(int i=0; i<book::get_counter();i++){
    //     if(b[i].get_id() == id) break;
    // }
    // if(i==book::get_counter()){
    //     cout << "Book wasn't found\n";
    // }
    // else{
    //     b[i].display();
    // }
    return 0;
}