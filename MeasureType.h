#if ! defined ( MEASURE_TYPE_H )
#define MEASURE_TYPE_H

#include <string>

using namespace std;

class MeasureType{

public:
	MeasureType(const MeasureType & measureType);
	MeasureType(const long & attributeId, const string & unit, const string & description);
	~MeasureType();
	long GetAttributeId() const {
		return attributeId;
	}

	string GetDescription() const {
		return description;
	}
	
	string GetUnit() const {
		return unit;
	}

	void SetAttributeId(const long & attributeId){
		this->attributeId=attributeId;
	}

	void SetUnit(const string & unit){
		this->unit=unit;
	}
	
	void SetDescription(const string & description){
		this->description=description;
	}
	
protected:
	string unit;
	long attributeId;
	string description;
};

#endif //MEASURE_TYPE_H
