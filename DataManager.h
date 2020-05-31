#if ! defined ( DATA_MANAGER_H )
#define DATA_MANAGER_H

#pragma once
#include <vector>
#include "User.h"
#include "Employee.h"
#include "CompanyOwner.h"
#include "Measure.h"
#include "Sensor.h"
#include "MeasureType.h"

using namespace std;

class Employee;
class DataManager
{
public:
	DataManager();
	~DataManager();

	//vector<User> getUsers();
	vector<Sensor> getSensors() const { return sensors; };
	vector<MeasureType> getMeasureTypes() const { return measureTypes; };
	vector<Measure> getMeasures() const { return measures; };
	vector<CompanyOwner> getCompanyOwners() const { return companyOwners; };
	vector<Employee> getEmployees() const { return employees; };

	//vector<User> getUsers();
	vector<Sensor> initSensors();
	vector<MeasureType> initMeasureTypes();
	vector<Measure> initMeasures();
	vector<CompanyOwner> initCompanyOwners();
	vector<Employee> initEmployees();

private:
	//vector<User> users;
	vector<Sensor> sensors;
	vector<MeasureType> measureTypes;
	vector<Measure> measures;
	vector<CompanyOwner> companyOwners;
	vector<Employee> employees;
};

#endif //DATA_MANAGER_H

