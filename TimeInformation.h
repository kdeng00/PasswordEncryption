#ifndef TIMEINFORMATION_H_
#define TIMEINFORMATION_H_

#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>

using std::string;

template<typename I = int>
class TimeInformation
{
protected:
	I year, month, dayOfMonth;
	void setupTime();
public:
	TimeInformation();

	I retrieveYear() const;
	I retrieveMonth() const;
	I retrieveDayOfMonth() const;

	string dateString() const;
};

template<typename I>
TimeInformation<I>::TimeInformation()
{
	srand(time(0));
	setupTime();
}

template<typename I>
void TimeInformation<I>::setupTime()
{
	time_t epochTime = time(0);
	tm* currentTime = localtime(&epochTime);

	year = 1900 + currentTime->tm_year;
	month = 1 + currentTime->tm_mon;
	dayOfMonth = currentTime->tm_mday;
}

template<typename I>
I TimeInformation<I>::retrieveYear() const { return year; }
template<typename I>
I TimeInformation<I>::retrieveMonth() const { return month; }
template<typename I>
I TimeInformation<I>::retrieveDayOfMonth() const { return dayOfMonth; }


template<typename I>
string TimeInformation<I>::dateString() const 
{
	string dateString;
	if (month<10 && dayOfMonth<10)
	{
		dateString.assign(std::to_string(year));
		dateString.append("0"+std::to_string(month));
		dateString.append("0"+std::to_string(dayOfMonth));
	}
	else if (month<10 && dayOfMonth>=10)
	{
		dateString.assign(std::to_string(year));
		dateString.append("0"+std::to_string(month));
		dateString.append(std::to_string(dayOfMonth));
	}
	else if (month>=10 && dayOfMonth<10)
	{
		dateString.assign(std::to_string(year));
		dateString.append(std::to_string(month));
		dateString.append("0"+std::to_string(dayOfMonth));
	}
	else
	{	
		dateString.assign(std::to_string(year));
		dateString.append(std::to_string(month));
		dateString.append(std::to_string(dayOfMonth));
	}

	return dateString;
}
#endif
