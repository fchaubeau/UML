#pragma once

#include <string>
#include <fstream>
#include <vector>
#include <sstream>

class PrivateUser
{
private:
	std::string mail;
	std::string name;
	std::string password;
	std::string tel;

	std::vector<std::string> tokenize(std::string line);

public:
	PrivateUser();
	PrivateUser(std::string mail, std::string name, std::string password, std::string tel);
	~PrivateUser();

	bool logIn(std::string mail, std::string password);
	bool logOut();
	bool modifyPassword(std::string newPassword);
};

