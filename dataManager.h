#pragma once
#include <vector>

#include "User.h"

using namespace std;

class dataManager
{
public:
	dataManager();
	~dataManager();

	vector<User> getUsers();
};

