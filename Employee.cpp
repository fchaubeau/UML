#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

#include "DataManager.h"
#include "Employee.h"
#include "Measure.h"
#include "Sensor.h"


static vector<string> getSensorIdInAnArea(const pair<double,double> & center, const double & radius, const DataManager & dataManager) //Center = <latitude,longitude>
{
    vector<string> toReturn;
    vector<Sensor> sensors = dataManager.getSensors();
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

Employee &Employee::operator=(const Employee & source)
{
	if(&source != this)
	{
		*this = Employee(source);
	}
	return *this;
} 

Employee::~Employee() {}

vector<double> Employee::getMeanAirQuality(const pair<double, double> & center, const double & radius, const time_t & t, const DataManager & dataManager) const
{
    vector<Measure> measures = dataManager.getMeasures();
    vector<MeasureType> measuresType = dataManager.getMeasureTypes();
    vector<string> measuresTypeId;
    vector<double> dataSum;
    vector<int> sizeOfData;
    //cout << "initialisations OK" << endl;

    for(unsigned int i = 0; i < measuresType.size(); i++)
    {
        measuresTypeId.push_back(measuresType[i].GetAttributeId());
        dataSum.push_back(0.0);
        sizeOfData.push_back(0);
    }

    // Début test initialisation données
    /*for(unsigned int i = 0; i < measuresType.size(); i++)
    {
        cout << "measureTypeById = " << measuresTypeId[i] << endl;
        cout << "dataSum = " << dataSum[i] << endl;
        cout << "sizeOfData = " << sizeOfData[i] << endl;
        cout << endl;
    }*/
    // Fin test intialisations données
    cout << endl;

    vector<string> sensorsId = getSensorIdInAnArea(center,radius, dataManager);
    // Début test récupérations des détecteurs
    /*for(unsigned int i = 0; i < sensorsId.size(); i++)
    {
        cout << "Id n°" << i << " = " << sensorsId[i] << endl;

    }*/
    // Fin test récupérations des détecteurs
    

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
		if(sizeOfData[i]>0)
			dataSum[i] = dataSum[i]/sizeOfData[i];
    }
    return dataSum;
}


int Employee::analyseImpactNiveau(const Cleaning & cleaning, const double & radiusAnalyse, const double & rateAmeliorationP1, const double & rateAmeliorationP2, const DataManager & dataManager){        //Exemple P1=0.3 et P2=0.5
	int longitude = cleaning.getLongitude();
	int latitude = cleaning.getLatitude();
	time_t startTime = cleaning.getStartTime();
	time_t stopTime = cleaning.getStopTime() - 12*3600;
	
  	pair<double,double> coordinate = make_pair(latitude,longitude);

	vector<double>startQuality = getMeanAirQuality(coordinate, radiusAnalyse, startTime, dataManager);   //Change to call the fonction getMeanAirQualityTimeSpawn(...) as you like
	
	vector<double>stopQuality = getMeanAirQuality(coordinate, radiusAnalyse, stopTime, dataManager);   //Change to call the fonction getMeanAirQualityTimeSpawn(...) as you like
	
	int rate = 0;
	
	for(int i = 1 ; i<startQuality.size() ; i++){
		if(stopQuality[i]<=(1-rateAmeliorationP2)*startQuality[i]){
			cout<<"Attribute No."<<i<<": A strong amelioration detected."<<endl;
			rate+=2;
		}else if(stopQuality[i]<=(1-rateAmeliorationP1)*startQuality[i]){
			cout<<"Attribute No."<<i<<": A weak amelioration detected."<<endl;
			rate++;		
		}else{
			cout<<"Attribute No."<<i<<":The amelioration is negligible or no amelioration at all"<<endl;
		}
	
			cout<<"Value before the cleaning: "<<startQuality[i]<<endl;
			cout<<"Value after the cleaning: "<<stopQuality[i]<<endl;
	}
	return rate;
	
	
}

double Employee::calculRayonEffet(const Cleaning & cleaning, const double & rateAmeliorationP1, const double & rateAmeliorationP2, const DataManager & dataManager)
{
	double rayon = 1.0;
	bool effect = true;
	int grade = 0;
	while (effect)
	{
		grade = analyseImpactNiveau(cleaning, rayon, rateAmeliorationP1, rateAmeliorationP2, dataManager);
		cout << "grade = " << grade << endl;
		if (grade > 0)
		{
			rayon += 3.0;
		}
		else
		{
			effect = false;
		}

	}

	return rayon;
}

void Employee::analyseImpactEvolutionDeTemps(const Cleaning & cleaning, const double & radiusAnalyse, const double & rateAmeliorationP1, const double & rateAmeliorationP2, const DataManager & dataManager){
	int longitude = cleaning.getLongitude();
	int latitude = cleaning.getLatitude();
	time_t startTime = cleaning.getStartTime();
	time_t stopTime = cleaning.getStopTime() - 12*3600;
	int i=0;
  	pair<double,double> coordinate = make_pair(latitude,longitude);

	 //Change to call the fonction getMeanAirQualityTimeSpawn(...) as you like
	for(;startTime<stopTime;startTime+=864000){ //10 days
		int rate = 0;
		vector<double>startQuality = getMeanAirQuality(coordinate, radiusAnalyse, startTime, dataManager);   //Change to call the fonction getMeanAirQualityTimeSpawn(...) as you like
	
		vector<double>stopQuality = getMeanAirQuality(coordinate, radiusAnalyse, startTime+=864000, dataManager);  
		for(int j = 1 ; j<startQuality.size() ; j++){
			if(stopQuality[j]>=(1+rateAmeliorationP2)*startQuality[j]){
				cout<<"Attribute No."<<j<<": A strong amelioration detected."<<endl;
				rate+=2;
			}else if(stopQuality[j]>=(1-rateAmeliorationP1)*startQuality[j]){
				cout<<"Attribute No."<<j<<": A weak amelioration detected."<<endl;
				rate++;		
			}else{
				cout<<"Attribute No."<<j<<":The amelioration is negligible or no amelioration at all"<<endl;
			}
	
			cout<<"Value before the cleaning: "<<startQuality[j]<<endl;
			cout<<"Value after the cleaning: "<<stopQuality[j]<<endl;
			
			
		}
		i++;
		cout<<"The rate for the amelioration of the No."<<i<<" ten days: "<<rate<<endl<<endl<<endl;
	}


}


vector<double> Employee::getMeanAirQualityTimeSpawn(const pair<double, double> & center, const double & radius, const time_t & tdebut, const time_t & tFin, const DataManager & dataManager) const
{
    time_t increment = tdebut;
	vector<vector<double>> timeSpanData;
	vector<double> meanAirQuality;
	while(difftime(tFin,increment)>0)
	{
        //cout << increment << endl;
		meanAirQuality = getMeanAirQuality(center, radius, increment, dataManager);
		timeSpanData.push_back(meanAirQuality);
		increment += 86400;
	}
    // Début test récupération données
    /*for(unsigned int i = 0; i < timeSpanData.size(); i++)
    {
        for(unsigned int j = 0; j < timeSpanData[i].size(); j++)
        {
            cout << "time span data [" << i <<"][" << j << "] = " << timeSpanData[i][j] << endl;
        }

    }*/
    // Fin test récupération données
	vector<double> meanAirQualityTimeSpan(meanAirQuality.size());
	for(int i=0; i<timeSpanData.size(); i++)
	{
		for(int j=0; j<timeSpanData[i].size(); j++)
		{
			meanAirQualityTimeSpan[j] += timeSpanData[i][j];
		}
	}
	for(int i=0; i < meanAirQualityTimeSpan.size(); i++)
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
