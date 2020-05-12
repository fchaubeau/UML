using namespace std;
#include <iostream>
#include "Measure.h"
#include <ctime>

Measure::Measure(){
	value = 0.O;
	sensorId = 0;
	attributeId = 0;
	time = 0;
}

Measure::Measure(time_t time, long sensorId, long attributeId, double value){
	this->sensorId=sensorId;
	this->attributeId=attributeId;
	this->value=value;
	this->time=time;
}
