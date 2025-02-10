#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

const int monthMaxDay[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
const string monthName[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

class Planner{
    private:
        string** tasks;
    public:
        void allocation(){
            tasks = new string*[12];
            for(int i=0; i<12; i++){
                tasks[i] = new string[monthMaxDay[i]];
            }
            // Filling
            for(int i=0; i<12; i++){
                for(int j=0; j<monthMaxDay[i]; j++){
                    tasks[i][j] = "";
                }
            }
        }

        bool validation(int m, int d){
            bool check = true;
            if(m<0 || m>11)
                check = false;
            else if(d < 1 || d > monthMaxDay[m])
                check = false;
            return check;
        }
        
        void addTask(){
            int m, d;
            cout << "Enter month: ", cin >> m;
            cout << "Enter Day: ", cin >> d;
            m--;
            if(validation(m,d) == false){
                cout << "Incorrect Month or Day!" << endl;
                return;
            }
            d--;
            cout << "Enter Task: ", cin.ignore(), getline(cin, tasks[m][d]);
            cout << "Task Successfully added!" << endl;
        }

        void removeTask(){
            int m, d;
            cout << "Enter month: ", cin >> m;
            cout << "Enter Day: ", cin >> d;
            m--,d--;
            if(validation(m,d) == false){
                cout << "Incorrect Month or Day!" << endl;
                return;
            }
            tasks[m][d] = "";
            cout << "Task Successfully removed!" << endl;
        }

        void display(){
            for(int i=0; i<12; i++){
                cout << "---" << monthName[i] << "---" << endl;
                for(int j=0; j<monthMaxDay[i]; j++){
                    if(tasks[i][j] != ""){
                        cout << "Day " << left << setw(2) << j+1 << ": " << tasks[i][j] << endl;
                    }
                }
            }
        }

        void deallocation() {
            for (int i = 0; i < 12; i++) {
                delete[] tasks[i];
            }
            delete[] tasks;
        }

};

int main() {
    Planner planner;
    planner.allocation();

    int choice;
    do {
        system("cls");
        cout << "1. Add Task\n2. Remove Task\n3. Display Tasks\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                planner.addTask();
                break;
            case 2:
                planner.removeTask();
                break;
            case 3:
                planner.display();
                break;
            case 4:
                planner.deallocation();
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
        cout << "Enter any key to continue...", getchar();
    } while (choice != 4);

    return 0;
}