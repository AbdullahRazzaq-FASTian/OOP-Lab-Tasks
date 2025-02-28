#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

class Product
{
    static int counterId;
    int id;
    string name;
    float price;

public:
    Product() {}
    Product(string name, float price) : name(name), price(price) { id = counterId++; }
    int getId() const { return id; }
    string getName() const { return name; }
    float getPrice() const { return price; }
};
int Product::counterId = 0;

class Store
{
    int size;
    int currentProducts;
    Product **productList = nullptr;

public:
    Store(int size) : size(size)
    {
        currentProducts = 0;
        productList = new Product *[size];
    }
    ~Store()
    {
        for (int i = 0; i < currentProducts; i++)
            delete productList[i];
        delete[] productList;
    }
    void addProduct(string name, float price){
        if(currentProducts < size){
            productList[currentProducts] = new Product(name, price);
            currentProducts++;
        }
        else{
            cout << "\nMax. Capacity Hit\n";
        }
    }
    void sort() {
        bool swapped;
        for(int i=0; i<currentProducts-1; i++){
            swapped = false;
            for(int j=i+1; j<currentProducts; j++){
                if(productList[i]->getPrice() > productList[j]->getPrice()){
                    Product* temp = productList[i];
                    productList[i] = productList[j];
                    productList[j] = temp;
                    swapped = true;
                }
            }
            if(!swapped)
                break;
        }
    }
    void search(string name)
    {
        int i;
        bool found = false;
        for (i = 0; i < currentProducts; i++)
        {
            if (productList[i]->getName() == name)
            {
                found = true;
                break;
            }
        }
        if (found)
        {
            cout << "Product Name: " << productList[i]->getName() << endl
                 << "Product ID: " << productList[i]->getId() << endl 
                 << "Poduct Price: " << productList[i]->getPrice() << " PKR" << endl;
        }
        else
        {
            cout << "Product not found!\n";
        }
    }
    void display()
    {
        if (currentProducts == 0)
        {
            cout << "There is no Product added yet!\n";
        }
        else
        {
            cout << left << setw(5) << "ID" << setw(15) << "Name" << setw(10) << "Price (pkr)" << endl;
            for (int i = 0; i < currentProducts; i++)
            {
                cout << left << setw(5) << productList[i]->getId()
                     << setw(15) << productList[i]->getName()
                     << setw(10) << productList[i]->getPrice() << endl;
            }
        }
    }
};

int main()
{
    Store myStore(5);

    myStore.addProduct("CPU", 20000);
    myStore.addProduct("Monitor", 5000);
    myStore.addProduct("Mouse", 1000);
    myStore.addProduct("Keyboard", 3000);
    myStore.addProduct("Headphone", 1500);
    
    nl;
    // myStore.search("Mouse");
    myStore.sort();
    myStore.display();
    nl;

    return 0;
}