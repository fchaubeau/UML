using namespace std;
#include <iostream>
#include "MeasureType.h"
#include <ctime>

MeasureType::MeasureType(){
	unit="";
	attributeId=NULL;
	description="";
}

MeasureType::MeasureType(long attributeId, string unit, string description){
	this->attributeId=attributeId;
	this->unit=unit;
	this->description=description;
}
