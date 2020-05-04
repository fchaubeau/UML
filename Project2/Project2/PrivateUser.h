
#if ! defined ( PRIVATEUSER_H )
#define PRIVATEUSER_H
#define MAP
#include "User.h"
#include "Measure.h"
#include "Sensor.h"


class PrivateUser : public User
{
public:

    PrivateUser (const User & unUser, const int point);

    PrivateUser (const string mail, const string name, const string password, const string tel, const int point);

    virtual ~Traj ( );

    virtual bool log_in();

    virtual bool log_out();

    int checkPoint() const;

    bool uploadData(list<Measure> measures) const;

    bool signUp(PrivateUser unPrivateUser) const;

    Measure createMeasure();

protected:

	int point;
	Sensor sensor;
};

#endif 
