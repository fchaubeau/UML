using namespace std;
#include <iostream>
#include "PrivateUser.h"
PrivateUser::PrivateUser (const User & unUser, const int point) : User(unUser)

{
	this->point = point;
}

PrivateUser::(const string mail, const string name, const string password, const string tel, const int point)
	: User(mail, name, password, tel)
{
	this->point = point;
}

PrivateUser::~PrivateUser()
{
}

int PrivateUser::checkPoint()
{
	return point;
}

bool PrivateUser::uploadData(list<Measure> measures)
{
	
}

bool PrivateUser::signUp(PrivateUser unPrivateUser)
{
	
}

Measure PrivateUser::createMeasure()
{
	
}
