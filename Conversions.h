#ifndef CONVERSIONS_H_
#define CONVERSIONS_H_

#include<string>
#include<sstream>

class Conversions
{
public:
	Conversions() = default;

	std::string cstringToString(char[], const int);
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
#endif
