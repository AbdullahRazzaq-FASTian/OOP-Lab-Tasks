#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

class Activity
{
public:
    virtual double calculateCaloriesBurned() = 0;
};

class Running : public Activity
{
protected:
    double distance;
    double time;

public:
    Running(double distance, double time) : distance(distance), time(time) {}
    double calculateCaloriesBurned()
    {
        return distance * time * 1.036;
    }
};

class Cycling : public Activity
{
protected:
    double speed;
    double time;

public:
    Cycling(double speed, double time) : speed(speed), time(time) {}
    double calculateCaloriesBurned()
    {
        return speed / time * 7.032;
    }
};

// These are just arbitrary formulas not the correct one just for example purpose

int main()
{
    Running R(34.1, 60.2);
    Cycling C(12.1, 56.1);
    nl;
    cout << "Calories burned through Running: " << R.calculateCaloriesBurned() << "J" << endl;
    cout << "Calories burned through Cycling: " << C.calculateCaloriesBurned() << "J" << endl;
    nl;
    return 0;
}