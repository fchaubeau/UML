#if ! defined ( CLEANING_H )
#define CLEANING_H

#include <string>
#include <ctime>

class Cleaning{

    public:
        Cleaning(const Cleaning & cleaning);
        Cleaning(const long & cleanerId, const double & latitude, const double & longitude, const string & description, const time_t & startTime, const time_t & stopTime);
        virtual ~Cleaning();



    protected:
        long cleanerId;
        double latitude;
        double longitude;
        string description;
        time_t startTime;
        time_t stopTime;



};

#endif //CLEANING_H