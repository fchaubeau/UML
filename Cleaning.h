#if ! defined ( CLEANING_H )
#define CLEANING_H

#include <string>
#include <ctime>

class Cleaning{

    public:
        Cleaning(const Cleaning & cleaning);
        Cleaning(const string & cleanerId, const double & latitude, const double & longitude, const string & description, const time_t & startTime, const time_t & stopTime);
        virtual ~Cleaning();

		string Cleaning::getCleanerId() const
		{
			return cleanerId;
		}

		double Cleaning::getLatitude() const
		{
			return latitude;
		}

		double Cleaning::getLongitude() const
		{
			return longitude;
		}

		string Cleaning::getDescription() const
		{
			return description;
		}

		time_t Cleaning::getStartTime() const
		{
			return startTime;
		}

		time_t Cleaning::getStopTime() const
		{
			return stopTime;
		}

		void Cleaning::setCleanerId(const string& newCleanerId)
		{
			cleanerId = newCleanerId;
		}
		
		void Cleaning::setLatitude(const double& newLatitude)
		{
			latitude = newLatitude;
		}
		
		void Cleaning::setLongitude(const double& newLongitude)
		{
			longitude = newLongitude;
		}
		
		void Cleaning::setDescription(const string& newDescription)
		{
			description = newDescription;
		}
		
		void Cleaning::setStartTime(const time_t& newStartTime)
		{
			startTime = newStartTime;
		}
		
		void Cleaning::setStopTime(const time_t& newStopTime)
		{
			stopTime = newStopTime;
		}

    protected:
        string cleanerId;
        double latitude;
        double longitude;
        string description;
        time_t startTime;
        time_t stopTime;



};

#endif //CLEANING_H