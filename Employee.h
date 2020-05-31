#if ! defined ( EMPLOYEE_H )
#define EMPLOYEE_H

#include <string>
#include <ctime>
#include <vector>
#include <list>
#include "User.h"
#include "Sensor.h"
#include "dataManager.h"

using namespace std;

class DataManager;
class Employee : User
{

public:

    Employee(const Employee & anEmployee);
    Employee(const string & mail, const string & name, const string & password, const string & tel, const int & point);
    virtual ~Employee();

    list<Sensor> getSimilarSensor(const Sensor & s) const;
    vector<double> getMeanAirQuality(const pair<double, double> & center, const double & radius, const time_t & t, DataManager & dataManager) const;
    double getMeanAirQualityTimeSpawn(const pair<double, double> & center, const double & radius, const time_t & tdebut, const time_t & tFin) const;
    bool Menu();
    string toString() const;

protected:
    int point;
};


#endif // EMPLOYEE_H
