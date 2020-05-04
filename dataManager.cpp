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
	vector<vector<string>> userFile;
	ifstream file("users.csv");
	while (!file.eof())
	{
		string line;
		vector<string> attributs;
		size_t pos = string::npos;

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
