#include <iostream>
using namespace std;

#include "Cleaning.h"

Cleaning::Cleaning(const Cleaning & cleaning)
{
    cleanerId = cleaning.cleanerId;
    latitude = cleaning.latitude;
    longitude = cleaning.longitude;
    description = cleaning.description;
    startTime = cleaning.startTime;
    stopTime = cleaning.stopTime;
}

Cleaning::Cleaning(const string & cleanerId = 0, const double & latitude = 0.0, const double & longitude = 0.0, const string & description = "", const time_t & startTime = 0, const time_t & stopTime = 0)
{
    this->cleanerId = cleanerId;
    this->latitude = latitude;
    this->longitude = longitude;
    this->description = description;
    this->startTime = startTime;
    this->stopTime = stopTime;
}

Cleaning &Cleaning::operator=(const Cleaning & source)
{
	if(&source != this)
	{
		*this = Cleaning(source);
	}
	return *this;
} 

Cleaning::~Cleaning(){}