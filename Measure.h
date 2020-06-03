#if ! defined ( MEASURE_H )
#define MEASURE_H

#include <ctime>
#include <string>

using namespace std;

class Measure{

public:
	Measure(const Measure & measure);
	Measure(const time_t & time, const string & sensorId, const string & attributeId, const double & value);
	Measure& operator=(const Measure & source);
	string toString() const;
	~Measure();
	string getSensorId() const{
		return sensorId;
	}

	string getAttributeId() const {
		return attributeId;
	}

	double getValue() const {
		return value;
	}
	
	time_t getTime() const{
		return time;
	}
	
	void setSensorId(const string & sensorId){
		this->sensorId=sensorId;
	}

	void setAttributeId(const string & attributeId){
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
	string sensorId;
	string attributeId;
	double value;
};

#endif //MEASURE_H
