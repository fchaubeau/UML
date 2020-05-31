#include <iostream>
#include <ctime>
#include <string>

#include "Employee.h"
using namespace std;

int main(int argc, char* argv[])
{
    Employee* emp = new Employee(string("f.chaubeau@gmail.com"), string("Chaubeau"), string("1234"), string("0123456789"), 0);
    //cout << emp->toString() << endl;

    DataManager dataManager = new DataManager();
    vector<double> meanAirQuality = emp->getMeanAirQuality(make_pair(45.0,0.0), 3.0, 1546344000, dataManager);
    cout << meanAirQuality << endl;

    delete emp;

    return 0;
}