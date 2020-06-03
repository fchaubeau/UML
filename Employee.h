#if ! defined ( EMPLOYEE_H )
#define EMPLOYEE_H

#include <string>
#include <ctime>
#include <vector>
#include <list>
#include "User.h"
#include "Sensor.h"
#include "DataManager.h"
#include "Cleaning.h"

using namespace std;

class DataManager;
class Employee : public User
{

public:

    Employee(const Employee & anEmployee);
    Employee(const string & mail, const string & name, const string & password, const string & tel, const int & point);
    Employee& operator=(const Employee & source);
    virtual ~Employee();

    list<Sensor> getSimilarSensor(const Sensor & s) const;
    vector<double> getMeanAirQuality(const pair<double, double> & center, const double & radius, const time_t & t, const DataManager & dataManager) const;
    int analyseImpactNiveau(const Cleaning & cleaning, const double & radiusAnalyse, const double & rateAmeliorationP1, const double & rateAmeliorationP2, const DataManager & dataManager);
    void analyseImpactEvolutionDeTemps(const Cleaning & cleaning, const double & radiusAnalyse, const double & rateAmeliorationP1, const double & rateAmeliorationP2, const DataManager & dataManager);
    vector<double> getMeanAirQualityTimeSpawn(const pair<double, double> & center, const double & radius, const time_t & tdebut, const time_t & tFin, const DataManager & dataManager) const;
    double calculRayonEffet(const Cleaning & cleaning, const double & rateAmeliorationP1, const double & rateAmeliorationP2, const DataManager & dataManager);
    bool Menu();
    string toString() const;

protected:
    int point;
};


#endif // EMPLOYEE_H
