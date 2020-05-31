#if ! defined ( CLEANING_H )
#define CLEANING_H

#include <string>
#include <ctime>

class Cleaning{

    public:
        Cleaning(const Cleaning & cleaning);
        Cleaning(const string & cleanerId, const double & latitude, const double & longitude, const string & description, const time_t & startTime, const time_t & stopTime);
		Cleaning& operator=(const Cleaning & source);
        virtual ~Cleaning();

		string getCleanerId() const
		{
			return cleanerId;
		}

		double getLatitude() const
		{
			return latitude;
		}

		double getLongitude() const
		{
			return longitude;
		}

		string getDescription() const
		{
			return description;
		}

		time_t getStartTime() const
		{
			return startTime;
		}

		time_t getStopTime() const
		{
			return stopTime;
		}

		void setCleanerId(const string& newCleanerId)
		{
			cleanerId = newCleanerId;
		}
		
		void setLatitude(const double& newLatitude)
		{
			latitude = newLatitude;
		}
		
		void setLongitude(const double& newLongitude)
		{
			longitude = newLongitude;
		}
		
		void setDescription(const string& newDescription)
		{
			description = newDescription;
		}
		
		void setStartTime(const time_t& newStartTime)
		{
			startTime = newStartTime;
		}
		
		void setStopTime(const time_t& newStopTime)
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