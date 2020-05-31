using namespace std;

#include <iostream>
#include <ctime>

#include "Measure.h"


Measure::Measure(const time_t & time = 0, const string & sensorId = 0, const string & attributeId = 0, const double & value = 0.0)
{
	this->sensorId = sensorId;
	this->attributeId = attributeId;
	this->value = value;
	this->time = time;
}

Measure::Measure(const Measure & measure)
{
	this->sensorId = measure.sensorId;
	this->attributeId = measure.attributeId;
	this->value = measure.value;
	this->time = measure.time;
}

Measure::~Measure(){}

Measure &Measure::operator=(const Measure & source)
{
	if(&source != this)
	{
		*this = Measure(source);
	}
	return *this;
} 
