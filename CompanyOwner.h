#if ! defined ( COMPANY_OWNER_H )
#define COMPANY_OWNER_H

using namespace std;

class CompanyOwner
{

public : 
	CompanyOwner(string companyName = "");
	virtual ~CompanyOwner();
	string getCompanyName();
	void setCompanyName(string companyName);
	void addCleaning(Cleaning cleaning);
	list getEvolution(time_t tdebut, time_t tfin, long sensorId);
	void signUp(CompanyOwner companyOwner);
	bool uploadData(list<Measure> data);
	
private : 
	string companyName;
	
};

#endif