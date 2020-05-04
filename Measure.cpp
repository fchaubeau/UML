using namespace std;
#include <iostream>
#include "Measure.h"
#include <ctime>

Measure::Measure(){
	value=NULL;
	sensorId=NULL;
	attributeId=NULL;
	time=NULL;
}

Measure::Measure(time_t time, long sensorId, long attributeId, double value){
	this->sensorId=sensorId;
	this->attributeId=attributeId;
	this->value=value;
	this->time=time;
}
