#include "DataManager.h"
#include <fstream>
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

DataManager::DataManager()
{
	this->users = initUsers();
	cout << "users ok" << endl;
	this->sensors = initSensors();
	cout << "sensors ok" << endl;
	this->measures = initMeasures();
	cout << "mesures ok" << endl;
	this->companyOwners = initCompanyOwners();
	cout << "compagny owner ok" << endl;
	this->measureTypes = initMeasureTypes();
	cout << "measures types ok" << endl;
 	//this->employees = initEmployees();
	//cout << "employee ok" << endl;
}


DataManager::~DataManager()
{
}

vector<User> DataManager::initUsers() {
	vector<User> users;
	ifstream file("users.csv");
	while (!file.eof())
	{
		string line;
		vector<string> attributs;

		getline(file, line);
		if (file.eof())
			break;

		size_t current, previous = 0;
		current = line.find(';');
		while (current < line.size()) {
			attributs.push_back(line.substr(previous, current - previous));
			previous = current + 1;
			current = line.find(';', previous);
		}
		attributs.push_back(line.substr(previous, current - previous));

		User toAdd(attributs[0], attributs[1], attributs[2], attributs[3]);
		users.push_back(toAdd);
	}
	file.close();
	return users;
}

vector<Sensor> DataManager::initSensors() {
	vector<Sensor> sensors;
	ifstream file("sensors.csv");
	while (!file.eof())
	{
		string line;
		vector<string> attributs;

		getline(file, line);
		if (file.eof())
			break;

		size_t current, previous = 0;
		current = line.find(';');
		while (current < line.size()) {
			attributs.push_back(line.substr(previous, current - previous));
			previous = current + 1;
			current = line.find(';', previous);
		}
		attributs.push_back(line.substr(previous, current - previous));

		Sensor toAdd(attributs[0], stod(attributs[1]), stod(attributs[2]), attributs[3]);
		sensors.push_back(toAdd);
	}
	file.close();
	return sensors;
}

vector<MeasureType> DataManager::initMeasureTypes()
{
	vector<MeasureType> measureTypes;
	ifstream file("attributes.csv");
	while (!file.eof())
	{
		string line;
		vector<string> attributs;

		getline(file, line);
		if (file.eof())
			break;

		size_t current, previous = 0;
		current = line.find(';');
		while (current < line.size()) {
			attributs.push_back(line.substr(previous, current - previous));
			previous = current + 1;
			current = line.find(';', previous);
		}
		attributs.push_back(line.substr(previous, current - previous));

		MeasureType toAdd(attributs[0], attributs[1], attributs[2]);
		measureTypes.push_back(toAdd);
	}
	file.close();
	return measureTypes;
}

vector<Measure> DataManager::initMeasures()
{
	vector<Measure> measures;
	ifstream file("measurements.csv");
	while (!file.eof())
	{
		string line;
		vector<string> attributs;

		getline(file, line);
		if (file.eof())
			break;

		size_t current, previous = 0;
		current = line.find(';');
		while (current < line.size()) {
			attributs.push_back(line.substr(previous, current - previous));
			previous = current + 1;
			current = line.find(';', previous);
		}
		attributs.push_back(line.substr(previous, current - previous));
		struct tm time; 
		int yy, month, dd, hh, mm, ss;
		sscanf(attributs[0].c_str(), "%d-%d-%d %d:%d:%d", &yy, &month, &dd, &hh, &mm, &ss);
		time.tm_year = yy - 1900;
		time.tm_mon = month;
		time.tm_mday = dd;
		time.tm_hour = hh;
		time.tm_min = mm;
		time.tm_sec = ss;
		time.tm_isdst = 0;
		time_t timeOfMeasurement = mktime(&time);

		
		Measure toAdd(timeOfMeasurement, attributs[1], attributs[2], stod(attributs[3]));
		measures.push_back(toAdd);
	}
	file.close();
	return measures;
}

vector<CompanyOwner> DataManager::initCompanyOwners()
{
	vector<CompanyOwner> companyOwners;
	ifstream file("providers.csv");
	while (!file.eof())
	{
		string line;
		vector<string> attributs;

		getline(file, line);
		if (file.eof())
			break;

		size_t current, previous = 0;
		current = line.find(';');
		while (current < line.size()) {
			attributs.push_back(line.substr(previous, current - previous));
			previous = current + 1;
			current = line.find(';', previous);
		}
		attributs.push_back(line.substr(previous, current - previous));

		CompanyOwner toAdd(attributs[0]);
		companyOwners.push_back(toAdd);
	}
	file.close();
	return companyOwners;
}

vector<Employee> DataManager::initEmployees()
{
	vector<Employee> employees;
	ifstream file("xxxxxxx.csv");
	while (!file.eof())
	{
		string line;
		vector<string> attributs;

		getline(file, line);
		if (file.eof())
			break;

		size_t current, previous = 0;
		current = line.find(';');
		while (current < line.size()) {
			attributs.push_back(line.substr(previous, current - previous));
			previous = current + 1;
			current = line.find(';', previous);
		}
		attributs.push_back(line.substr(previous, current - previous));

		Employee toAdd(attributs[0], attributs[1], attributs[2], attributs[3], stoi(attributs[4]));
		employees.push_back(toAdd);
	}
	file.close();
	return employees;
}
