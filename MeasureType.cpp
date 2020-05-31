using namespace std;
#include <iostream>
#include "MeasureType.h"
#include <ctime>

MeasureType::MeasureType(const MeasureType & measureType){
	this->attributeId = measureType.attributeId;
	this->unit = measureType.unit;
	this->description = measureType.description;
}

MeasureType::MeasureType(const string & attributeId = 0, const string & unit = "", const string & description = ""){
	this->attributeId=attributeId;
	this->unit=unit;
	this->description=description;
}

MeasureType::~MeasureType() {}

MeasureType &MeasureType::operator=(const MeasureType & source)
{
	if(&source != this)
	{
		*this = MeasureType(source);
	}
	return *this;
} 
