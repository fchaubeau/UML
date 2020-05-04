class CompanyOwner
{

public : 
	CompanyOwner(string companyName);
	~ComapnyOwner();
	string getCompanyName();
	void setCompanyName(string companyName);
	void addCleaning(Cleaning cleaning);
	list getEvolution(time_t tdebut, time_t tfin, long sensorId);
	void signUp(CompanyOwner companyOwner);
	bool uploadData(list<Measure> data);
	
private : 
	string companyName;
	
};