#pragma once
#include <vector>

#include "User.h"

using namespace std;

class DataManager
{
public:
	DataManager();
	~DataManager();

	vector<User> getUsers();
	vector<Sensor> getSensors();
	vector<MeasureType> getMeasureTypes();
	vector<Measure> getMeasures();
	vector<CompanyOwner> getCompanyOwners();
	vector<Employee> getEmployees();
};

