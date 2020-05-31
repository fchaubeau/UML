#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

#include "Employee.h"
#include "dataManager.h"
#include "Measure.h"
#include "Sensor.h"

static vector<string> getSensorIdInAnArea(const pair<double,double> & center, const double & radius) //Center = <latitude,longitude>
{
    DataManager* dataManager = new DataManager();
    vector<string> toReturn;
    vector<Sensor> sensors = dataManager->getSensors();
    for(unsigned int i = 0; i < sensors.size(); i++)
    {
        if(sqrt(pow(abs(center.first-sensors[i].GetLatitude()),2) + pow(abs(center.second-sensors[i].GetLongitude()),2)) < radius)
        {
            toReturn.push_back(sensors[i].GetSensorId());
        } 
    }
    return toReturn;
}


Employee::Employee(const Employee& anEmployee) :
User(anEmployee.mail, anEmployee.name, anEmployee.password, anEmployee.tel)

{
    point = anEmployee.point;

}

Employee::Employee(const string & mail = "", const string & name = "", const string & password = "", const string & tel = "", const int & point = 0) :
User(mail,name, password, tel)
{
    this->point = point;
}

Employee::~Employee() {}

vector<double> Employee::getMeanAirQuality(const pair<double, double> & center, const double & radius, const time_t & t, const DataManager & dataManager) const
{
    vector<Measure> measures = dataManager->getMeasures();
    vector<MeasureType> measuresType = dataManager->getMeasureTypes();
    vector<string> measuresTypeId;
    vector<double> dataSum;
    vector<int> sizeOfData;
    for(unsigned int i = 0; i < measuresType.size(); i++)
    {
        measuresTypeId.push_back(measuresType[i].GetAttributeId());
        dataSum.push_back(0.0);
        sizeOfData.push_back(0);
    }
    vector<string> sensorsId = getSensorIdInAnArea(center,radius);
    for(unsigned int i = 0; i < measures.size(); i++)
    {
        for(unsigned int j = 0; j < sensorsId.size(); j++)
        {
            if(measures[i].getSensorId() == sensorsId[j] && measures[i].getTime() == t)
            {
                for(unsigned int k = 0; k < measuresTypeId.size(); k++)
                {
                    if(measures[i].getAttributeId() == measuresTypeId[k])
                    {
                        dataSum[k] += measures[i].getValue();
                        sizeOfData[k]++;
                    }
                }
            }
        }
    }
    for(unsigned int i = 0; i < dataSum.size(); i++)
    {
        dataSum[i] = dataSum[i]/sizeOfData[i];
    }
    return dataSum;
}

vector<double> Employee::getMeanAirQualityTimeSpawn(const pair<double, double> & center, const double & radius, const time_t & tdebut, const time_t & tFin, const DataManager & dataManager) const
{
    time_t increment = tdebut;
	struct tm* tm;
	vector<vector<double>> timeSpanData;
	vector<double> meanAirQuality;
	while(difftime(tFin,increment)>0)
	{
		meanAirQuality = getMeanAirQuality(center, radius, increment, dataManager);
		timeSpanData.push_back(meanAirQuality);
		tm = gmtime(&increment);
		tm -> tm_day++;
		increment = mktime(tm);
	}
	vector<double> meanAirQualityTimeSpan(meanAirQuality.size());
	for(int i=0; i<timeSpanData.size(); i++)
	{
		for(int j=0; j<timeSpanData[i].size(); j++)
		{
			meanAirQualityTimeSpan[j] += timeSpanData[i].[j];
		}
	}
	for(int i=0; i<meanAirQualityTimeSpan.size(); i++)
	{
		meanAirQualityTimeSpan[i] /= timeSpanData.size();
	}
    return meanAirQualityTimeSpan;
}

list<Sensor> Employee::getSimilarSensor(const Sensor & s) const
{
    list<Sensor> toReturn;
    return toReturn;
}

bool Employee::Menu()
{
    return true;
}

string Employee::toString() const
{
    string toReturn = "Employee : ";
    toReturn += "name = ";
    toReturn += this->name;
    toReturn += ", mail = ";
    toReturn += this->mail;
    toReturn += ", password = ";
    toReturn += this->password;
    toReturn += ", tel = ";
    toReturn += this->tel;
    return toReturn;
}