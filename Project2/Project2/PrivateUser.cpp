#include "PrivateUser.h"



std::vector<std::string> PrivateUser::tokenize(std::string line)
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

PrivateUser::PrivateUser()
{
}


PrivateUser::~PrivateUser()
{
}

bool PrivateUser::logIn(std::string mail, std::string password)
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

bool PrivateUser::modifyPassword(std::string newPassword)
{
	this->password = password;
	return true;
}
