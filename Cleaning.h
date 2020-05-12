#if ! defined ( CLEANING_H )
#define CLEANING_H

#include <string>
#include <ctime>

class Cleaning{

    public:



    protected:
        long cleanerId;
        double latitude;
        double longitude;
        string description;
        time_t startTime;
        time_t stopTime;



};

#endif //CLEANING_H