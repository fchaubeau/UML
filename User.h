#if ! defined ( USER_H )
#define USER_H

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
	User(const User & user);
	User(const string & mail, const string & name, const string & password, const string & tel);
	User& operator=(const User & source);
	virtual ~User();

	bool LogIn(const string & mail, const string & password);
	bool LogOut();
	bool ModifyPassword(const string & newPassword);
	virtual bool Menu();
	string getName(){return this->name;};
};

#endif //USER_H

