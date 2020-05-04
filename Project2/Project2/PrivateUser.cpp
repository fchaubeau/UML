using namespace std;
#include <iostream>
#include "PrivateUser.h"
#include <ctime>
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
	// write measures into csv and return true if succeed
}

bool PrivateUser::signUp(PrivateUser unPrivateUser)
{
	// write unPrivateUser into csv and return true if succeed
}

Measure PrivateUser::createMeasure(Sensor sensor, long attributeID)
{
	time_t now;
	time(&now);
	default_random_engine::default_random_engine e(1);
	int n;
	if(attributeID < 3) n = e() % 300;
	if(attributeID >=3) n = e() % 50;
	double value = e()/e.max();
	value += n;
	Measure res = Measure(now, sensor.getSensorId(), attributeID, value);
	return res;
	
}
