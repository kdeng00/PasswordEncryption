#ifndef CONVERSIONS_H_
#define CONVERSIONS_H_

#include<string>
#include<sstream>

using std::string;
using std::stringstream;

class Conversions
{
public:
	Conversions() = default;
	~Conversions()=default;

	template<typename C=char,typename S=string>
	S cstringToString(const C* tmp, const int size)
	{
	stringstream cToS{};
	for (auto index=0; index!=size; ++index)
		cToS<<tmp[index];
	S tmpString{};
	cToS>>tmpString;
	return tmpString;

	}
	template<typename C=char,typename S=string>
	C stringToChar(const S& tmp)
	{

	stringstream sToC{};
	for (auto tmpElements:tmp)
		sToC<<tmpElements;
	char tmpChar{};
	sToC>>tmpChar;
	return tmpChar;
	}
private:
};
#endif
