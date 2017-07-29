#ifndef CONVERSIONS_H_
#define CONVERSIONS_H_

#include<string>
#include<sstream>

class Conversions
{
public:
	Conversions() = default;
	~Conversions()=default;

	template<typename C=char,typename S=std::string>
	S cstringToString(const C[], const int);
	template<typename C=char,typename S=std::string>
	C stringToChar(const S&);
private:
};
template<typename C=char,typename S=std::string>
S Conversions::cstringToString(const C tmp[], const int size)
{
	std::stringstream cToS{};
	for (auto index=0; index!=size; ++index)
		cToS<<tmp[index];
	std::string tmpString{};
	cToS>>tmpString;
	return tmpString;
}
template<typename C=char,typename S=std::string>
C Conversions::stringToChar(const S& tmp)
{
	std::stringstream sToC{};
	for (auto tmpElements:tmp)
		sToC<<tmpElements;
	char tmpChar{};
	sToC>>tmpChar;
	return tmpChar;
}
#endif
