
#if ! defined ( PRIVATEUSER_H )
#define PRIVATEUSER_H
#define MAP
#include "User.h"
#include "Measure.h"
#include "Sensor.h"
#include "dataManager.h"
#include <random>

class PrivateUser : public User
{
public:

    PrivateUser (const User & unUser, const int point);

    PrivateUser (const string mail, const string name, const string password, const string tel, const int point);

    virtual ~Traj ( );

    virtual bool logIn();

    virtual bool logOut();

    int checkPoint() const;

    bool uploadData(list<Measure> measures) const;

    bool signUp(PrivateUser unPrivateUser) const;

    Measure createMeasure(Sensor sensor, long attributeID);

	bool Menu();

	string getMail();

	string getSensorID();

	bool addSensor(Sensor unSensor);



protected:

	int point;
	Sensor sensor;
};

#endif 
