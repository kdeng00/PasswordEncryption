#ifndef GENERATEDATE_H_
#define GENERATEDATE_H_

#include<ctime>
#include<cstdlib>
#include<string>

using std::string;

template<typename S = string, typename I = int>
class GenerateDate
{
public:
	GenerateDate();
	~GenerateDate() = default;

	void initializeData();
	void generation();

	S retrieveDateString() const { return dateString; }
private:	
	S dateString;
	I year, month, day;
	time_t unixEpoch;
	tm* currentTime;
};
template<typename S, typename I>
GenerateDate<S,I>::GenerateDate()
{
	initializeData();
	generation();
}
template<typename S, typename I>
void GenerateDate<S,I>::initializeData()
{
	unixEpoch = time(0);
	currentTime = localtime(&unixEpoch);

	year = 1900 + currentTime->tm_year;
	month = 1 + currentTime->tm_mon;
	day = currentTime->tm_mday;

}
template<typename S, typename I>
void GenerateDate<S,I>::generation()
{
	if (month<10 && day<10)
	{
		dateString.assign(std::to_string(year));
		dateString.append("0"+std::to_string(month));
		dateString.append("0"+std::to_string(day));
	}	
	else if (month<10 && day>=10)
	{
		dateString.assign(std::to_string(year));
		dateString.append("0"+std::to_string(month));
		dateString.append(std::to_string(day));
	}
	else if (month>=10 && day<10)
	{
		dateString.assign(std::to_string(year));
		dateString.append(std::to_string(month));
		dateString.append("0"+std::to_string(day));
	}
	else
	{
		dateString.assign(std::to_string(year));
		dateString.append(std::to_string(month));
		dateString.append(std::to_string(day));
	}
}
#endif
