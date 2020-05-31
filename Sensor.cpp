using namespace std;

#include <iostream>
#include <string>

#include "Sensor.h"

Sensor::Sensor(const Sensor & sensor)
{
	this->sensorId = sensor.sensorId;
	this->latitude = sensor.latitude;
	this->longitude = sensor.longitude;
	this->description = sensor.description;
}

Sensor::Sensor(const string & sensorId = 0, const double & latitude = 0.0, const double & longitude = 0, const string & description = "")
{
	this->sensorId = sensorId;
	this->latitude = latitude;
	this->description = description;
	this->longitude = longitude;
}

Sensor &Sensor::operator=(const Sensor & source)
{
	if(&source != this)
	{
		*this = Sensor(source);
	}
	return *this;
} 

Sensor::~Sensor() {}
