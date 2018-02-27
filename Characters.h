#ifndef CHARACTERS_H_
#define CHARACTERS_H_

#include<array>
#include<vector>
using std::array;
using std::vector;
using std::size_t;

const size_t letterCount = 52;
const size_t numberCount = 10;
const size_t symbolCount = 34;
const size_t characterCount = letterCount + numberCount + symbolCount;

template<typename CT>
class Characters
{
protected:	
	std::array<CT,letterCount> letters;
	std::array<CT,numberCount> numbers;
	std::array<CT,symbolCount> symbols;
	std::vector<CT> allCharacters;
};
#endif
