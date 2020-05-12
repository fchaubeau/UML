#include <iostream>

using namespace std;

#include "Employee.h"


Employee::Employee(const Employee& anEmployee)

{
    mail = anEmployee.mail;
    name = anEmployee.name;
    password = anEmployee.password;
    tel = anEmployee.tel;
    point = anEmployee.point;

}

Employee::Employee(const string & mail = "", const string & name = "", const string & password = "", const string & tel = "", const int & point = 0)
{
    this->mail = mail;
    this->name = name;
    this->password = password;
    this->tel = tel;
    this->point = point;
}

Employee::~Employee() {}

double Employee::getMeanAirQuality(const pair<double, double> & center, const double & radius, const time_t & t) const
{
    return 0.0;
}

double Employee::getMeanAirQUalityTimeSpawn(const pair<double, double> & center, const double & radius, const time_t & tdebut, const time_t & tFin) const
{
    
    return 0.0;
}

list<Sensor> Employee::getSimilarSensor(const Sensor & s) const
{

    return nullptr;
}
