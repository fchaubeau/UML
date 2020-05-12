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

Employee::Employee(string mail, string name, string password, string tel, int point)
{
    this->mail = mail;
    this->name = name;
    this->password = password;
    this->tel = tel;
    this->point = point;
}


Employee::Employee()

{
#ifdef MAP
    cout << "Appel au constructeur de <Ensemble>" << endl;
#endif
}


Employee::~Employee()
{
}

double Employee::getMeanAirQUalityTimeSpawn(pair<double, double> center, double radius, time_t tdebut, time_t tFin)
{
    
    return 0.0;
}
