#if ! defined ( MeasureType_H )
#define MeasureType_H
class MeasureType{

public:
	MeasureType();
	MeasureType(long attributeId, string unit, string description);
	long getAttributeId(){
		return attributeId;
	}

	string getDescription(){
		return description;
	}
	
	string getUnit(){
		return unit;
	}

	void setAttributeId(long attributeId){
		this->attributeId=attributeId;
	}

	void setUnit(string unit){
		this->unit=unit;
	}
	
	void setDescription(string description){
		this->description=description;
	}
	
protected:
	string unit;
	long attributeId;
	string description;
};

#endif
