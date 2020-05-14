#if ! defined ( MEASURE_H )
#define MEASURE_H

#include <ctime>

using namespace std;

class Measure{

public:
	Measure(const Measure & measure);
	Measure(const time_t & time, const long & sensorId, const long & attributeId, const double & value);
	~Measure();
	long getSensorId() const{
		return sensorId;
	}

	long getAttributeId() const {
		return attributeId;
	}

	double getValue() const {
		return value;
	}
	
	time_t getTime() const{
		return time;
	}
	
	void setSensorId(const long & sensorId){
		this->sensorId=sensorId;
	}

	void setAttributeId(const long & attributeId){
		this->attributeId=attributeId;
	}

	void setValue(const double & value){
		this->value=value;
	}
	
	void setTime(const time_t & time){
		this->time=time;
	}
	
protected:
	time_t time;
	long sensorId;
	long attributeId;
	double value;
};

#endif //MEASURE_H
