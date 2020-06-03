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
#include "Cleaning.h"

using namespace std;

class Employee;
class DataManager
{
public:
	DataManager();
	~DataManager();

	vector<User> getUsers() const { return users; };
	vector<Sensor> getSensors() const { return sensors; };
	vector<MeasureType> getMeasureTypes() const { return measureTypes; };
	vector<Measure> getMeasures() const { return measures; };
	vector<CompanyOwner> getCompanyOwners() const { return companyOwners; };
	vector<Employee> getEmployees() const { return employees; };
	vector<Cleaning> getCleanings() const { return cleanings; };

	vector<User> initUsers();
	vector<Sensor> initSensors();
	vector<MeasureType> initMeasureTypes();
	vector<Measure> initMeasures();
	vector<CompanyOwner> initCompanyOwners();
	vector<Employee> initEmployees();
	vector<Cleaning> initCleanings();

private:
	vector<User> users;
	vector<Sensor> sensors;
	vector<MeasureType> measureTypes;
	vector<Measure> measures;
	vector<CompanyOwner> companyOwners;
	vector<Employee> employees;
	vector<Cleaning> cleanings;
};

#endif //DATA_MANAGER_H

