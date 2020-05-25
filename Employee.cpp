#include <iostream>
#include <string>

using namespace std;

#include "Employee.h"
#include "dataManager.h"
#include "Measure.h"
#include "Sensor.h"

static vector<int> getSensorIdInAnArea(const pair<double,double> & center, const double & radius)
{
    vector<int> toReturn;
    vector<Sensor> sensors = dataManager->getSensors();
    for(unsigned int i = 0; i < sensors.size(); i++)
    {
        if(center.first)
    }
    return toReturn;
}


Employee::Employee(const Employee& anEmployee) :
User(anEmployee.mail, anEmployee.name, anEmployee.password, anEmployee.tel)

{
    point = anEmployee.point;

}

Employee::Employee(const string & mail = "", const string & name = "", const string & password = "", const string & tel = "", const int & point = 0) :
User(mail,name, password, tel)
{
    this->point = point;
}

Employee::~Employee() {}

double Employee::getMeanAirQuality(const pair<double, double> & center, const double & radius, const time_t & t) const
{
    DataManager* dataManager = new DataManager();
    vector<Measure> measures = dataManager->getMeasures();
    vector<int> sensorsId = dataManager->getSensorIdInAnArea();
    return 0.0;
}

double Employee::getMeanAirQUalityTimeSpawn(const pair<double, double> & center, const double & radius, const time_t & tdebut, const time_t & tFin) const
{
    
    return 0.0;
}

list<Sensor> Employee::getSimilarSensor(const Sensor & s) const
{
    list<Sensor> toReturn;
    return toReturn;
}

bool Employee::Menu()
{
    return true;
}

string Employee::toString() const
{
    string toReturn = "Employee : ";
    toReturn += "name = ";
    toReturn += this->name;
    toReturn += ", mail = ";
    toReturn += this->mail;
    toReturn += ", password = ";
    toReturn += this->password;
    toReturn += ", tel = ";
    toReturn += this->tel;
    return toReturn;
}