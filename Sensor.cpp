using namespace std;
#include <iostream>
#include "Sensor.h"

Sensor::Sensor(){
	sensorId=NULL;
	description="";
	latitude=NULL;
	longitude=NULL;
}

Sensor::Sensor(long sensorId, double latitude, double longitude, string description){
	this->sensorId=sensorId;
	this->latitude=latitude;
	this->description=description;
	this->longitude=longitude;
}
