#include "User.h"

#include <string>

using namespace std;

User::User(const User & user)
{
	this->mail = user.mail;
	this->name = user.name;
	this->password = user.password;
	this->tel = user.tel;
}


User::User(const string & mail = "", const string & name = "", const string & password = "", const string & tel = "")
{
	this->mail = mail;
	this->name = name;
	this->password = password;
	this->tel = tel;
}

User &User::operator=(const User & source)
{
	if(&source != this)
	{
		*this = User(source);
	}
	return *this;
} 


User::~User() {}

bool User::LogIn(const string & mail, const string & password)
{
	vector<string> tokenizedLine; //TODO
	bool userFound = false;
	for (unsigned int i = 0; i < tokenizedLine.size(); i++)
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

bool User::ModifyPassword(const string & newPassword)
{	
	if(this->password!=newPassword){
		this->password = password;
		return true;
	}else{
		printf("Error: Password Identique");
		return false; 
	}
}

bool User::Menu()
{
	return true;
}
