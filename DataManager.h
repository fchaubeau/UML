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

class DataManager
{
public:
	DataManager();
	~DataManager();

	//vector<User> getUsers();
	vector<Sensor> getSensors() { return sensors; };
	vector<MeasureType> getMeasureTypes() { return measureTypes; };
	vector<Measure> getMeasures() { return measures; };
	vector<CompanyOwner> getCompanyOwners() { return companyOwners; };
	vector<Employee> getEmployees() { return employees; };

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

