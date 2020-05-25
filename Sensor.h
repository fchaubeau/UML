#if ! defined ( SENSOR_H )
#define SENSOR_H

#include <string>

using namespace std;

class Sensor{

public:
	Sensor(const Sensor & sensor);
	Sensor(const long & sensorId, const double & latitude, const double & longitude, const string & description);
	~Sensor();
	double GetLatitude() const {
		return latitude;
	}

	long GetSensorId() const{
		return sensorId;
	}

	double GetLongitude() const {
		return longitude;
	}
	
	string GetDescription() const {
		return description;
	}
	
	void SetLatitude(const double & latitude){
		this->latitude=latitude;
	}

	void SetSensorId(const long & attributeId){
		this->sensorId=sensorId;
	}

	void SetLongitude(const double & longitude){
		this->longitude=longitude;
	}
	
	void SetDescription(const string & description){
		this->description=description;
	}
	
protected:
	long sensorId;
	double latitude;
	double longitude;
	string description;
};

#endif //SENSOR_H
