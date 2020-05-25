#include <string>
#include <list>
#include <iterator>
#include <ctime>

using namespace std;

#include "CompanyOwner.h"
#include "Cleaning.h"
#include "Measure.h"
#include "dataManager.h"

CompanyOwner::CompanyOwner(const CompanyOwner & companyOwner)
{
	companyName = companyOwner.companyName;
}

CompanyOwner::CompanyOwner(const string & companyName = "")
{
	this->companyName = companyName;
}

CompanyOwner::~CompanyOwner(){}
	
string CompanyOwner::getCompanyName() const
{
	return companyName;
}
	
void CompanyOwner::setCompanyName(const string & companyName)
{
	this->companyName = companyName;
}
	
void CompanyOwner::addCleaning(const Cleaning & cleaning)
{
	ofstream file("cleaners.csv");
	if(file.is_open())
	{
		file << "Cleaner" << cleaning.cleanerId << ";" << cleaning.latitude << ";" << cleaning.longitude << ";" << cleaning.description << ";" << cleaning.startTime << ";" << cleaning.stopTime << ";\n";
	}
	file.close();
}
	
list<int> CompanyOwner::getEvolution(const time_t & tdebut, const time_t & tfin, const string & sensorId) const
{
	DataManager dataManager = new DataManager();
	vector<Measure> measures = dataManager.getMeasures();
	return *new list<int>();
}
	
void CompanyOwner::signUp(const CompanyOwner & companyOwner)
{
	
}
	
bool CompanyOwner::uploadData(list<Measure> data)
{
	return true;
}

