#if ! defined ( MEASURE_H )
#define MEASURE_H

#include <ctime>

using namespace std;

class Measure{

public:
	Measure(Measure measure);
	Measure();
	Measure(time_t time, long sensorId, long attributeId, double value);
	long getSensorId(){
		return sensorId;
	}

	long getAttributeId(){
		return attributeId;
	}

	double getValue(){
		return value;
	}
	
	time_t getTime(){
		return time;
	}
	
	void setSensorId(long sensorId){
		this->sensorId=sensorId;
	}

	void setAttributeId(long attributeId){
		this->attributeId=attributeId;
	}

	void setValue(double value){
		this->value=value;
	}
	
	void setTime(time_t time){
		this->time=time;
	}
	
protected:
	time_t time;
	long sensorId;
	long attributeId;
	double value;
};

#endif //MEASURE_H
