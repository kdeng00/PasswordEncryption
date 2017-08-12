#include<iostream>
#include<ctime>
#include<cstdlib>
#include"GeneratePasswordFileName.h"

GeneratePasswordFileName::GeneratePasswordFileName()
{
	srand(time(0));
	generatedFileName();
}
void GeneratePasswordFileName::generatedFileName()
{
	time_t epochTime = time(0);
	tm* currentTime = localtime(&epochTime);

	auto year = 1900 + currentTime->tm_year;
	auto month = 1 + currentTime->tm_mon;
	auto dayOfMonth = currentTime->tm_mday;

	if (month<10 && dayOfMonth<10)
	{
		filename.assign(std::to_string(year));
		filename.append("0"+std::to_string(month));
		filename.append("0"+std::to_string(dayOfMonth));
	}
	else if (month<10 && dayOfMonth>=10)
	{
		filename.assign(std::to_string(year));
		filename.append("0"+std::to_string(month));
		filename.append(std::to_string(dayOfMonth));
	}
	else if (month>=10 && dayOfMonth<10)
	{
		filename.assign(std::to_string(year));
		filename.append(std::to_string(month));
		filename.append("0"+std::to_string(dayOfMonth));
	}
	else
	{	
		filename.assign(std::to_string(year));
		filename.append(std::to_string(month));
		filename.append(std::to_string(dayOfMonth));
	}
	for (auto index = 0; index!=8; ++index)
	{
		if (index==0) filename.append("_");
		else
		{
			auto randomInteger = rand() % 10;	
			filename.append(std::to_string(randomInteger));
		}
	}
}

std::string GeneratePasswordFileName::passwordFileNameString() const { return filename; }
