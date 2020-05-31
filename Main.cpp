#include <iostream>
#include <ctime>
#include <string>

#include "Employee.h"
#include "Measure.h"
using namespace std;

int main(int argc, char* argv[])
{
    Employee* emp = new Employee(string("f.chaubeau@gmail.com"), string("Chaubeau"), string("1234"), string("0123456789"), 0);

    DataManager* dataManager = new DataManager();

    vector<double> meanAirQuality = emp->getMeanAirQuality(make_pair(45.0,0.0), 4.0, 1580468400, *dataManager);
    cout << "concentration of O3 = " << meanAirQuality.at(1) << endl;
    cout << "concentration of SO2 = " << meanAirQuality.at(2) << endl;
    cout << "concentration of NO2 = " << meanAirQuality.at(3) << endl;
    cout << "concentration of PM10 = " << meanAirQuality.at(4) << endl;
    cout << endl;

    vector<double> meanAirQualityTimeSpawn = emp->getMeanAirQualityTimeSpawn(make_pair(45.0,0.0), 1.0, 1580209200, 1580468400, *dataManager);
    cout << "concentration of O3 = " << meanAirQualityTimeSpawn.at(1) << endl;
    cout << "concentration of SO2 = " << meanAirQualityTimeSpawn.at(2) << endl;
    cout << "concentration of NO2 = " << meanAirQualityTimeSpawn.at(3) << endl;
    cout << "concentration of PM10 = " << meanAirQualityTimeSpawn.at(4) << endl;

    delete emp;
    delete dataManager;

    return 0;
}