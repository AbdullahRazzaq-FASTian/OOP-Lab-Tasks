    #include <bits/stdc++.h>
    #define nl (cout << endl)
    using namespace std;
    class car
    {
        int *regNum;
        string *modelName;
        string *ownerName;

    public:
        car(int regNum, string model, string owner) : regNum(new int(regNum)), modelName(new string(model)), ownerName(new string(owner)) {}
        car(const car &obj, string& newOwner)
        {
            this->regNum = new int(*obj.regNum);
            this->modelName = new string(*obj.modelName);
            this->ownerName = new string(newOwner);
        }
        void display()
        {
            cout << "Registration Num: " << *regNum << endl
                << "Model Name: " << *modelName << endl
                << "Owner Name: " << *ownerName << endl;
        }
        ~car() {
            delete regNum;
            delete modelName;
            delete ownerName;
        }
    };
    int main()
    {
        car C1(43214356, "Honda City", "Abc");
        string newOwner = "Xyz";
        car C2(C1,newOwner);
        nl;
        C1.display();
        nl;
        C2.display();
        nl;
        return 0;
    }