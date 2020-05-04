class Sensor
{
public:
	Sensor(const long sensorID, const double longitude, const double latitude, const string description);
	~Sensor();
	
protected:
	long sensorID;
	double latitude;
	double longitude;
	string description;
}
