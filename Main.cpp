#include <iostream>
#include <ctime>
#include <string>

#include "Employee.h"
using namespace std;

int main(int argc, char* argv[])
{
    Employee* emp = new Employee(string("f.chaubeau@gmail.com"), string("Chaubeau"), string("1234"), string("0123456789"), 0);
    cout << emp->toString() << endl;
    delete emp;
    return 0;
}