#include "User.h"



std::vector<std::string> User::tokenize(std::string line)
{
	std::vector<std::string> toReturn = std::vector<std::string>();
	std::string buffer = "";
	std::stringstream lineStream(line);
	while (std::getline(lineStream, buffer, ';'))
	{
		toReturn.push_back(buffer);
	}

	return toReturn;

}

User::User()
{
}

User::User(std::string mail, std::string name, std::string password, std::string tel)
{
	this->mail = mail;
	this->name = name;
	this->password = password;
	this->tel = tel;
}


User::~User()
{
}

bool User::logIn(std::string mail, std::string password)
{
	std::vector<std::string> tokenizedLine;
	bool userFound = false;
	for (int i = 0; i < tokenizedLine.size(); i++)
	{
		if (tokenizedLine[0].compare(mail) && tokenizedLine[1].compare(password))
		{
			userFound = true;
			this->mail = mail;
			this->password = password;
		}
	}

	return userFound;
}

bool User::modifyPassword(std::string newPassword)
{
	this->password = password;
	return true;
}
