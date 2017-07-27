#ifndef CONVERSIONS_H_
#define CONVERSIONS_H_

#include<string>
#include<sstream>

class Conversions
{
public:
	Conversions() = default;
	~Conversions()=default;

	std::string cstringToString(char[], const int);
	//char stringToChar(const string&);
private:
};

std::string Conversions::cstringToString(char tmp[], const int size)
{
	std::string tmpString{};
	std::stringstream cToS{};
	for (auto index =0; index!=size; ++ index)
		cToS << tmp[index];
	cToS >> tmpString;
	return tmpString;
}
/**
char Conversions::stringToChar(const string& tmp)
{
	char tmpChar{};
	stringstream sToC{};
	for (auto index=0; index!=tmp.size(); ++index)
		sToC << tmpChar;
	sToC >> tmpChar;
	return tmpChar;
}
*/
#endif
