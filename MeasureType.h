#if ! defined ( MEASURE_TYPE_H )
#define MEASURE_TYPE_H

#include <string>

using namespace std;

class MeasureType{

public:
	MeasureType(const MeasureType & measureType);
	MeasureType(const string & attributeId, const string & unit, const string & description);
	~MeasureType();
	string GetAttributeId() const {
		return attributeId;
	}

	string GetDescription() const {
		return description;
	}
	
	string GetUnit() const {
		return unit;
	}

	void SetAttributeId(const string & attributeId){
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
	string attributeId;
	string description;
};

#endif //MEASURE_TYPE_H
