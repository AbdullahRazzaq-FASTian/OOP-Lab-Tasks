#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

class Device
{
protected:
    int deviceId;
    bool status;

public:
    Device(int deviceId = 0, bool status = false)
        : deviceId(deviceId),
          status(status) {}

    void displayDetails()
    {
        cout << "Device ID: " << deviceId << endl;
        cout << "Device Status: " << (status ? "On" : "Off") << endl;
    }
};

class SmartPhone : virtual public Device
{
protected:
    float screenSize;

public:
    SmartPhone(int deviceId = 0, bool status = false, float screenSize = 0)
        : Device(deviceId),
          screenSize(screenSize) {}

    void displayDetails()
    {
        Device::displayDetails();
        cout << "Screen Size: " << screenSize << " inches" << endl;
    }
};

class SmartWatch : virtual public Device
{
protected:
    bool heartRateMonitor;

public:
    SmartWatch(int deviceId = 0, bool status = false, bool heartRateMonitor = false)
        : Device(deviceId, status),
          heartRateMonitor(heartRateMonitor) {}

    void displayDetails()
    {
        Device::displayDetails();
        cout << "Heart Rate Monitor: " << (heartRateMonitor ? "Enabled" : "Disabled") << endl;
    }
};

class SmartWearable : SmartPhone, SmartWatch
{
protected:
    int stepCounter;

public:
    SmartWearable(int deviceId = 0, bool status = false, float screenSize = 0, bool heartRateMonitor = false, int stepCounter = 0)
        : Device(deviceId, status),
          SmartPhone(deviceId, status, screenSize),
          SmartWatch(deviceId, status, heartRateMonitor),
          stepCounter(stepCounter) {}

    void displayDetails()
    {
        Device::displayDetails();
        cout << "Screen Size: " << screenSize << " inches" << endl;
        cout << "Heart Rate Monitor: " << (heartRateMonitor ? "Enabled" : "Disabled") << endl;
        cout << "No. of Steps Counted: " << stepCounter << endl;
    }
};

int main()
{
    SmartWearable sw(101, true, 5.5, true, 15000);
    nl;
    cout << "Smart Wearable Details:" << endl;
    sw.displayDetails();
    nl;
    return 0;
}