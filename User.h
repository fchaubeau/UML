#pragma once

#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

class User
{
protected:
	string mail;
	string name;
	string password;
	string tel;

public:
	User();
	User(string mail, string name, string password, string tel);
	~User();

	bool logIn(string mail, string password);
	bool logOut();
	bool modifyPassword(string newPassword);
	virtual bool menu();
};

