#include "bits.h"
using namespace std;
class car{
    int regNum;
    string modelName;
    string ownerName;
    public:
    car(int r, string m, string o) : regNum(r), modelName(m), ownerName(o){}
    car(const car &obj){
        regNum = obj.regNum;
        modelName = obj.modelName;
    }
    void setOwner(string owner){
        ownerName = owner;
    }
    void display(){
        cout << "Registration Num....: " << regNum<< endl;
        cout << "Model Name....: " << modelName<< endl;
        cout << "Owner Name....: " << ownerName<< endl;
    }   
};
int main(){
    car C1(43214356,"Honda City","Abc");
    car C2(C1);
    C2.setOwner("Xyz");     //New Owner
    C1.display();
    C2.display();
    return 0;
}