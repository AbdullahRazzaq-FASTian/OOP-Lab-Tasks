#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

class Humidity;

class Temperature
{
private:
    float temp;

public:
    Temperature(float t) : temp(t) {}
    friend float calculateHeatIndex(Temperature t, Humidity h);
};

class Humidity
{
private:
    float humidity; // humidity in %
public:
    Humidity(float h) : humidity(h) {}
    friend float calculateHeatIndex(Temperature t, Humidity h);
};

float calculateHeatIndex(Temperature t, Humidity h)
{
    float HI = -42.379 + 2.04901523 * t.temp + 10.14333127 * h.humidity - 0.22475541 * t.temp * h.humidity;
    return HI;
}

int main()
{
    Temperature temp(32.0);
    Humidity hum(70.0);
    float HI = calculateHeatIndex(temp, hum);
    nl;
    cout << "Heat Index is: " << HI << "C" << endl;
    nl;
    return 0;
}