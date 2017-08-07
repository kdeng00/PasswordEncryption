#include"Conversions.h"

using std::string;
using std::stringstream;

string Conversions::cstringToString(const char tmp[], const int size)
{
	string tmpString{};
	stringstream cToS{};
	for (auto index=0; index!=size; ++index)
		cToS<<tmp[index];
	cToS >> tmpString;
	return tmpString;
}
char Conversions::stringToChar(const string& tmp)
{
	char tmpChar{};
	stringstream sToC{};
	for (auto tmpElements:tmp)
		sToC << tmpElements;
	sToC>>tmpChar;
	return tmpChar;
}
