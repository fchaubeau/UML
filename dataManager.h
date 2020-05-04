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
};

