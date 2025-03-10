#include <bits/stdc++.h>
#define GETTER(type, var) \
    type get_##var() const { return var; }
#define SETTER(type, var) \
    void set_##var(type val) { this->var = val; }
#define nl (cout << endl)
using namespace std;

class WASATeam
{
protected:
    int teamID;
    string assignedZone;

public:
    WASATeam(int id, string zone) : teamID(id), assignedZone(zone) {}
    void display()
    {
        cout << "Team ID: " << teamID << endl;
        cout << "Team Assigned Zone: " << assignedZone << endl;
    }
};

class OperationalTeam : public WASATeam
{
protected:
public:
    OperationalTeam(int id, string zone) : WASATeam(id,zone) {}
    void display()
    {
        cout << "Team ID: " << teamID << endl;
        cout << "Team Assigned Zone: " << assignedZone << endl;
    }
};

class EquipmentHandler
{
protected:
    int available_tools;

public:
    EquipmentHandler(int available_tools) : available_tools(available_tools) {}
    void display()
    {
        cout << "Available Tools: " << available_tools << endl;
    }
};

class SkilledPersonal
{
protected:
    string specialization;

public:
    SkilledPersonal(string specialization) : specialization(specialization) {}
    void display()
    {
        cout << "Team Specialization: " << specialization << endl;
    }
};

class PipelineRepairTeam : OperationalTeam, EquipmentHandler, SkilledPersonal
{
protected:
    int pipeReplacementStock;

public:
    PipelineRepairTeam(int id, string zone, int available_tools, string specialization, int pipeReplacementStock)
        : OperationalTeam(id, zone), EquipmentHandler(available_tools), SkilledPersonal(specialization), pipeReplacementStock(pipeReplacementStock) {}
    void display() {
        OperationalTeam::display();
        EquipmentHandler::display();
        SkilledPersonal::display();
        cout << "Pipe Replacement Stock : " << pipeReplacementStock << endl;
    }
};

class EmergencyResponseTeam : OperationalTeam, EquipmentHandler, SkilledPersonal
{
protected:
    int emergencyKits;

public:
    EmergencyResponseTeam(int id, string zone, int available_tools, string specialization, int emergencyKits)
        : OperationalTeam(id, zone), EquipmentHandler(available_tools), SkilledPersonal(specialization), emergencyKits(emergencyKits) {}
    void display() {
        OperationalTeam::display();
        EquipmentHandler::display();
        SkilledPersonal::display();
        cout << "Emergency Kits : " << emergencyKits << endl;
    }
};

class WaterMeterInspectionTeam : OperationalTeam, EquipmentHandler, SkilledPersonal
{
protected:
    int inspectionReports;

public:
    WaterMeterInspectionTeam(int id, string zone, int available_tools, string specialization, int inspectionReports)
        : OperationalTeam(id, zone), EquipmentHandler(available_tools), SkilledPersonal(specialization), inspectionReports(inspectionReports) {}
    void display() {
        OperationalTeam::display();
        EquipmentHandler::display();
        SkilledPersonal::display();
        cout << "Inspection Reports : " << inspectionReports << endl;
    }
};

int main()
{
    PipelineRepairTeam t1(101,"North Zone",10,"Pipeline Repair",5);
    t1.display();
    EmergencyResponseTeam t2(102,"East Zone", 15, "Emergency Handling", 8);
    t2.display();
    WaterMeterInspectionTeam t3(103,"South Zone",7,"Meter Inspection", 20);
    t3.display();
    return 0;
}