#include <string>
#include <list>
#include <iterator>
#include <ctime>

using namespace std;

#include "CompanyOwner.h"
#include "Cleaning.h"
#include "Measure.h"

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
	
}
	
list CompanyOwner::getEvolution(const time_t & tdebut, const time_t & tfin, const long & sensorId) const
{
	
}
	
void CompanyOwner::signUp(const CompanyOwner & companyOwner)
{
	
}
	
bool CompanyOwner::uploadData(list<Measure> data)
{
	
}

