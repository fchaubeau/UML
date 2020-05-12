#if ! defined ( EMPLOYEE_H )
#define EMPLOYEE_H

#include <string>
#include <ctime>
#include <list>
#include "User.h"
#include "Sensor.h"
#include "CompanyOwner.h"


class Employee : User
{

public:

    Employee(const Employee & anEmployee);
    Employee(const string & mail, const string & name, const string & password, const string & tel, const int & point);
    virtual ~Employee();

    double getMeanAirQuality(const pair<double, double> & center, const double & radius, const time_t & t) const;
    double getMeanAirQUalityTimeSpawn(const pair<double, double> & center, const double & radius, const time_t & tdebut, const time_t & tFin) const;
    list<Sensor> getSimilarSensor(const Sensor & s) const;

protected:
    int point;
};


#endif // EMPLOYEE_H
