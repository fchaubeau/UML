#include "dataManager.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

DataManager::DataManager()
{
}


DataManager::~DataManager()
{
}

vector<User> DataManager::getUsers() {
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

vector<Sensor> DataManager::getSensors() {
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

		Sensor toAdd(attributs[0], attributs[1], attributs[2], attributs[3]);
		sensors.push_back(toAdd);
	}
	file.close();
	return sensors;
}

vector<MeasureType> DataManager::getMeasureTypes()
{
	vector<MeasureType> measureTypes;
	ifstream file("measureTypes.csv");
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

vector<Measure> DataManager::getMeasures()
{
	vector<Measure> measures;
	ifstream file("measures.csv");
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

		Measure toAdd(attributs[0], attributs[1], attributs[2], attributs[3]);
		measures.push_back(toAdd);
	}
	file.close();
	return measures;
}

vector<CompanyOwner> DataManager::getCompanyOwners()
{
	vector<CompanyOwner> companyOwners;
	ifstream file("companyOwners.csv");
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

vector<Employee> DataManager::getEmployees()
{
	vector<Employee> employees;
	ifstream file("employees.csv");
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

		Employee toAdd(attributs[0], attributs[1], attributs[2], attributs[3], attributs[4]);
		employees.push_back(toAdd);
	}
	file.close();
	return employees;
}
