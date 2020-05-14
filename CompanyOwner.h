#if ! defined ( COMPANY_OWNER_H )
#define COMPANY_OWNER_H

using namespace std;

#include<string>

#include "Cleaning.h"

class CompanyOwner
{

public : 
	CompanyOwner(const CompanyOwner & companyOwner);
	CompanyOwner(const string & companyName);
	virtual ~CompanyOwner();

	string getCompanyName() const;
	void setCompanyName(const string & companyName);
	void addCleaning(const Cleaning & cleaning);
	list getEvolution(const time_t & tdebut, const time_t & tfin, const long & sensorId) const;
	void signUp(const CompanyOwner & companyOwner);
	bool uploadData(list<Measure> data);
	
protected : 
	string companyName;
	
};

#endif //COMPANY_OWNER_H