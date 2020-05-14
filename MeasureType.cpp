using namespace std;
#include <iostream>
#include "MeasureType.h"
#include <ctime>

MeasureType::MeasureType(const MeasureType & measureType){
	this->attributeId = measureType.attributeId;
	this->unit = measureType.unit;
	this->description = measureType.description;
}

MeasureType::MeasureType(const long & attributeId = 0, const string & unit = "", const string & description = ""){
	this->attributeId=attributeId;
	this->unit=unit;
	this->description=description;
}

MeasureType::~MeasureType() {}
