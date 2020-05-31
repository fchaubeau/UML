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

string PrivateUser::getMail() { return this.mail; }

string PrivateUser::getSensorID() { return this.sensor.getID; }

int PrivateUser::checkPoint()
{
	return point;
}

bool PrivateUser::uploadData(list<Measure> measures)
{
	// write measures into csv and return true if succeed
	dataManager dm();
	for (int i = 0; i < measures.size(); i++)
	{
		dm.addMeasure(measures[i]);
	}
	return true;
}

bool PrivateUser::addSensor(Sensor unSensor) {
	dataManager dm();
	return dm.addSensor(unSensor);
}

bool PrivateUser::signUp(PrivateUser unPrivateUser)
{
	// write unPrivateUser into csv and return true if succeed
	dataManager dm();
	vector<User> userList = dm.getUsers();
	bool  exist = false;
	for (int i = 0; i < userList.size(); i++)
	{
		if (userList[i].equals(unPrivateUser)) {
			exist = true;
			break;
		}
	}
	if (!exist) {
		ofstream file;
		file.open("user.csv", ios::app);
		file << unPrivateUser.getMail() << ";Sensor" << unPrivateUser.getSensorID();
		file.close();
	}
}

bool PrivateUser::Menu() {

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
