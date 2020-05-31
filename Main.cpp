#include <iostream>
#include <ctime>
#include <string>

#include "Employee.h"
#include "Measure.h"
using namespace std;

int main(int argc, char* argv[])
{
    Employee* emp = new Employee(string("f.chaubeau@gmail.com"), string("Chaubeau"), string("1234"), string("0123456789"), 0);
    //cout << emp->toString() << endl;
    DataManager* dataManager = new DataManager();
    cout << "after data manager init \n";
    Measure* measure = new Measure(0,"1542","6756",0.24);
    Measure measurebis = *measure;
    cout << measurebis.getTime() << endl;
    cout << measurebis.getAttributeId() << endl;
    vector<double> meanAirQuality = emp->getMeanAirQuality(make_pair(45.0,0.0), 3.0, 1546344000, *dataManager);
    cout << meanAirQuality.at(0) << endl;

    delete emp;
    delete dataManager;
    delete measure;

    return 0;
}