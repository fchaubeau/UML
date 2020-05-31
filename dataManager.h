#if ! defined ( DATA_MANAGER_H )
#define DATA_MANAGER_H

#include <vector>

#include "User.h"
#include "CompanyOwner.h"
#include "Measure.h"
#include "Sensor.h"
#include "MeasureType.h"
#include "Employee.h"

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

private:
	vector<User> users;
	vector<Sensor> sensors;
	vector<MeasureType> measureTypes;
	vector<Measure> measures;
	vector<CompanyOwner> companyOwners;
	vector<Employee> employees;
};

#endif //DATA_MANAGER_H

