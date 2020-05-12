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

    Employee(const Employee& anEmployee);
    Employee(string mail, string name, string password, string tel, int point);
    Employee();

    virtual ~Employee();

    double getMeanAirQuality(pair<double, double> center, double radius, time_t t);

    double getMeanAirQUalityTimeSpawn(pair<double, double> center, double radius, time_t tdebut, time_t tFin);

    list<Sensor> getSimilarSensor(Sensor s);

protected:
    int point;
};


#endif // EMPLOYEE_H
