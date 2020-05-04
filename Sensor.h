#if ! defined ( Sensor_H )
#define Sensor_H
class Sensor{

public:
	Sensor();
	Sensor(long sensorId, double latitude, double longitude, string description);
	~Sensor();
	double getLatitude(){
		return latitude;
	}

	long getSensorId(){
		return sensorId;
	}

	double getLongitude(){
		return longitude;
	}
	
	string getDescription(){
		return description;
	}
	
	void setLatitude(double latitude){
		this->latitude=latitude;
	}

	void setSensorId(long attributeId){
		this->sensorId=sensorId;
	}

	void setLongitude(double longitude){
		this->longitude=longitude;
	}
	
	void setDescription(string description){
		this->description=description;
	}
	
protected:
	long sensorId;
	double latitude;
	double longitude;
	string description;
};

#endif
