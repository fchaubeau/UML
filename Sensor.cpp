using namespace std;
#include "Sensor.h"

Sensor::Sensor(const long sensorID, const double longitude, const double latitude, const string description)
{
	this->sensorID = sensorID;
	this->longitude = longitude;
	this->latitude = latitude;
	this->description = description;
}
	
Sensor::~Sensor(){}
