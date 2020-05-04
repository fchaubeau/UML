#include "User.h"

User::User()
{
}

User::User(string mail, string name, string password, string tel)
{
	this->mail = mail;
	this->name = name;
	this->password = password;
	this->tel = tel;
}


User::~User()
{
}

bool User::logIn(string mail, string password)
{
	vector<string> tokenizedLine; //TODO
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

bool User::modifyPassword(string newPassword)
{
	this->password = password;
	return true;
}
