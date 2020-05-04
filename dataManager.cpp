#include "dataManager.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

dataManager::dataManager()
{
}


dataManager::~dataManager()
{
}

vector<User> dataManager::getUsers() {
	vector<User> users;
	vector<vector<string>> userFile;
	ifstream file("users.csv");
	while (!file.eof())
	{
		string line;
		vector<string> currentlyProcessedUser;
		size_t pos = string::npos;

		getline(file, line);
		while (pos = line.find_first_of(";") != string::npos)
		{
			currentlyProcessedUser.push_back(line.substr(0, pos - 1));
			line.erase(0, pos);

		}
		User toAdd(currentlyProcessedUser[0], currentlyProcessedUser[1]);
		users.push_back(toAdd);
	}

}
