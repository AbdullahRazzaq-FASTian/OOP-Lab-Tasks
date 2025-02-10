#include "bits.h"
#define nl (cout << endl)
using namespace std;

class GroceryStore {
    private:
        string items[100] = {""};      //By default max. items
        float prices[100] = {0.0};
    public:
        int count = 0;
        void add(){
            cin.clear();
            fflush(stdin);
            cout << "=== Adding Item ===" << endl;
            cout << "Enter Item Name: ", getline(cin, items[count]);
            // while(getchar() != '\n');
            cin.clear();
            fflush(stdin);
            cout << "Enter Item Price: ", cin >> prices[count];
            cout << "Item successfully Added!" << endl;
            count++;
        }
        void update(){
            string item;
            cout << "Enter Name of Item to Update Price: ", getline(cin, items[count]);
            for (int i = 0; i < count; i++)
            {
                if(items[i]==item){
                    cout << "Enter New Price: ", cin >> prices[i];
                    break;
                }
            }
        }
        void viewInventory(){
            cout << setfill('=') << setw(20) << "Inventory" << setfill('=')  << setw(12) << " " << setfill(' ') <<endl;
            cout << left << setw(16) << "Items" << left << setw(16) << "Prices" << endl;
            for (int i = 0; i < count; i++)
            {
                cout << left << setw(16) << items[i] << left << setw(16) << prices[i] << endl;
            }
            nl;
        }

        void generateReciept(){
            float total = 0;
            // cout << setfill('=') << setw(30) << "" << setfill(' ') << endl;
            cout << "==============================" << endl;
            cout << "    ZAINAB'S GROCERY STORE    " << endl;
            cout << "            Multan            " << endl;
            cout << "==============================" << endl;
            cout << "Items                 Prices  " << endl;
            cout << "------------------------------" << endl;
            for (int i = 0; i < count; i++)
            {
                cout << left << setw(22) << items[i] << left << setw(4) << prices[i] << "$" << endl;
                // Calculating total price
                total += prices[i];
            }
            cout << "------------------------------" << endl;
            cout << "Total Items:          " << left << setw(4) << count << endl;
            cout << "Total Price:          " << left << setw(4) << "$" << total << endl;
            cout << "==============================" << endl;
            cout << " THANK YOU FOR SHOPPING WITH US! " << endl;
            cout << "==============================" << endl;
            nl;
        }
};

int main()
{
    GroceryStore G1;
    G1.add();
    G1.add();
    G1.add();
    G1.viewInventory();
    G1.generateReciept();
    return 0;
}