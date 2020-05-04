#pragma once

#include <string>
#include <fstream>
#include <vector>
#include <sstream>

class User
{
private:
	std::string mail;
	std::string name;
	std::string password;
	std::string tel;

	std::vector<std::string> tokenize(std::string line);

public:
	User();
	User(std::string mail, std::string name, std::string password, std::string tel);
	~User();

	bool logIn(std::string mail, std::string password);
	bool logOut();
	bool modifyPassword(std::string newPassword);
};

