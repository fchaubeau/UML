#include <iostream>
#include <ctime>
#include <string>

#include "Employee.h"
#include "Measure.h"
using namespace std;
void testFonctionality2Zone();
void testFonctionalityEvaluation();
time_t dateParser(const string& dayS, const string& monthS, const string& yearS);

int main(int argc, char* argv[])
{
    Employee* emp = new Employee(string("f.chaubeau@gmail.com"), string("Chaubeau"), string("1234"), string("0123456789"), 0);

	cout << "Fetching data, please wait..." << endl;
    DataManager* dataManager = new DataManager();
	vector <Measure> testMeasures = dataManager->getMeasures();
	for(int i = 0; i < 50; i++)
	{
		cout << testMeasures[i].toString() << endl;
		cout << endl;
	}

    //vector<double> meanAirQuality = emp->getMeanAirQuality(make_pair(45.0,0.0), 4.0, 1580468400, *dataManager);
    //cout << "concentration of O3 = " << meanAirQuality.at(1) << endl;
    //cout << "concentration of SO2 = " << meanAirQuality.at(2) << endl;
    //cout << "concentration of NO2 = " << meanAirQuality.at(3) << endl;
    //cout << "concentration of PM10 = " << meanAirQuality.at(4) << endl;
    //cout << endl;

    // vector<double> meanAirQualityTimeSpawn = emp->getMeanAirQualityTimeSpawn(make_pair(45.0,0.0), 1.0, 1580209200, 1580468400, *dataManager);
    // cout << "concentration of O3 = " << meanAirQualityTimeSpawn.at(1) << endl;
    // cout << "concentration of SO2 = " << meanAirQualityTimeSpawn.at(2) << endl;
    // cout << "concentration of NO2 = " << meanAirQualityTimeSpawn.at(3) << endl;
    // cout << "concentration of PM10 = " << meanAirQualityTimeSpawn.at(4) << endl;
	
	cout << "------------------------------ A I R W A T C H E R ------------------------------" << endl;
	cout << "Disclaimer : this app is under construction. Currently, there are 2 working functionalities." << endl << endl;
	cout << "1 : Fetch mean air quality over given area." << endl;
	cout << "2 : Determine if a given AirCleaner is effective." << endl << endl;
	cout << "Please enter the number of the functionality you wish to use : ";
	int choice;
	cin >> choice;
	if(choice == 1)
	{
		cout << "Enter the coordinates of the center of the area : " << endl;
		double xCoord, yCoord;
		cout << "x coordinate : ";
		cin >> xCoord;
		cout << "y coordinate : ";
		cin >> yCoord;
		pair<double,double> areaCenter (xCoord,yCoord);
		cout << "Enter the radius of the area : ";
		double areaRadius;
		cin >> areaRadius;
		cout << "1 : Get instant mean air quality" << endl << "2 : Get mean air quality over a period" << endl;
		cin >> choice;
		string day, month, year;
		switch(choice){
			case 1: 
			{		
				cout << "Enter date of measure following the dd-mm-yyyy format : ";
				getline(cin, day, '-');
				getline(cin, month, '-');
				getline(cin, year);
				if(day != "" && month != "" && year != ""){
					cout << "before dateParser" << endl;
					int iDay = stoi(day);
					int iMonth = stoi(month);
					int iYear = stoi(year);
					time_t rawtime;
					struct tm * timeinfo;

						/* get current timeinfo: */
					time ( &rawtime ); //or: rawtime = time(0);
					/* convert to struct: */
					timeinfo = localtime ( &rawtime ); 

					/* now modify the timeinfo to the given date: */
					timeinfo->tm_year   = iYear - 1900;
					timeinfo->tm_mon    = iMonth - 1;    //months since January - [0,11]
					timeinfo->tm_mday   = iDay;          //day of the month - [1,31] 
					timeinfo->tm_hour   = 12;         //hours since midnight - [0,23]
					timeinfo->tm_min    = 0;          //minutes after the hour - [0,59]
					timeinfo->tm_sec    = 0;          //seconds after the minute - [0,59]

					/* call mktime: create unix time stamp from timeinfo struct */
					time_t date = mktime ( timeinfo );

					cout << "timeStamp = " << date << endl;
					vector<double> meanAirQuality = emp->getMeanAirQuality(areaCenter, areaRadius, date, *dataManager);
					cout << "concentration of O3 = " << meanAirQuality.at(1) << endl;
					cout << "concentration of SO2 = " << meanAirQuality.at(2) << endl;
					cout << "concentration of NO2 = " << meanAirQuality.at(3) << endl;
					cout << "concentration of PM10 = " << meanAirQuality.at(4) << endl;
					cout << endl;

				}
			}
				break;
			case 2: 
			{
				cout << "Enter measure start date following the dd-mm-yyyy format : ";
				getline(cin, day, '-');
				getline(cin, month, '-');
				getline(cin, year);
				time_t startTime = 0;
				startTime = dateParser(day, month, year);
				
				cout << "Enter measure end date following the dd-mm-yyyy format : ";
				getline(cin, day, '-');
				getline(cin, month, '-');
				getline(cin, year);
				time_t endTime = 0;
				endTime = dateParser(day, month, year);
				vector<double> meanAirQualityTimeSpawn = emp->getMeanAirQualityTimeSpawn(areaCenter, areaRadius, startTime, endTime, *dataManager);
				cout << "concentration of O3 = " << meanAirQualityTimeSpawn.at(1) << endl;
				cout << "concentration of SO2 = " << meanAirQualityTimeSpawn.at(2) << endl;
				cout << "concentration of NO2 = " << meanAirQualityTimeSpawn.at(3) << endl;
				cout << "concentration of PM10 = " << meanAirQualityTimeSpawn.at(4) << endl;
				cout << endl;
			}
				break;
			default:
			{
				cout << "Please enter the number of an operational functionality : ";
			}
				break;

		}
		cout << "check 1\n";
	}
	else
	{
		cout << "Please enter the number of an operational functionality : ";		
	}	

    //delete emp;
    //delete dataManager;
	cout << "aaaa";
    return 0;
}

void testFonctionality2Zone(){
	Employee* emp = new Employee(string("f.chaubeau@gmail.com"), string("Chaubeau"), string("1234"), string("0123456789"), 0);
	DataManager* dataManager = new DataManager();
	vector<Cleaning> cleaners = dataManager->initCleanings();
	
	for(int i=0;i<cleaners.size();i++){
		cout<<"Analysing "<<cleaners[i].getCleanerId()<<"for the sensors in the range : radius = 1.0"<<endl<<endl;		
		int rate = emp->analyseImpactNiveau(cleaners[i],1.0,0.05,0.1,*dataManager);
		cout<<"The rate for "<<cleaners[i].getCleanerId()<<" is "<<rate<<" (rating from 0 to 8)"<<endl<<endl<<endl;
	}

	for(int i=0;i<cleaners.size();i++){
		cout<<"Analysing "<<cleaners[i].getCleanerId()<<"for the sensors in the range : radius = 4.0"<<endl<<endl;		
		int rate = emp->analyseImpactNiveau(cleaners[i],4.0,0.05,0.1,*dataManager);
		cout<<"The rate for "<<cleaners[i].getCleanerId()<<" is "<<rate<<" (rating from 0 to 8)"<<endl<<endl<<endl;
	}

}


void testFonctionalityEvaluation(){
	Employee* emp = new Employee(string("f.chaubeau@gmail.com"), string("Chaubeau"), string("1234"), string("0123456789"), 0);
	DataManager* dataManager = new DataManager();
	vector<Cleaning> cleaners = dataManager->initCleanings();
	cout<<"Start to analysing the impact of the cleaners by the evolution of the time"<<endl<<endl;
	for(int i=0;i<cleaners.size();i++){
		cout<<"Cleaner No."<<i<<": "<<endl;
		emp->analyseImpactEvolutionDeTemps(cleaners[i],1.0,0.02,0.05,*dataManager);
	}

}


time_t dateParser(const string& dayS, const string& monthS, const string& yearS)
{
	int day, month, year;
	day = stoi(dayS);
	month = stoi(monthS);
	year = stoi(yearS);
	struct tm* parsedDate;
	parsedDate->tm_year = year - 1900;
	parsedDate->tm_mon = month - 1;
	parsedDate->tm_mday = day;
	parsedDate->tm_hour = 12;
	parsedDate->tm_min = 0;
	parsedDate->tm_sec = 0;
	time_t date = timegm(parsedDate);
	char* testDate;
	
	strftime(testDate,20,"%F %T",parsedDate);   //Affichage test
	cout << testDate << endl;
	cout << date << endl;
	
	time_t test = 1580468400;  //Affichage test
	cout << ctime(&test);
	
	return date;
}
