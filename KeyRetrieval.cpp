#include<fstream>
#include<iostream>
#include<ios>
#include"KeyRetrieval.h"

KeyRetrieval::KeyRetrieval()
{ 
	retrieveKey();
	addToList();
}

void KeyRetrieval::retrieveKey()
{
	std::fstream readKeys{};
	readKeys.open(fileName.c_str());
	char keyChar[keySize];
	while (!readKeys.eof())
	{
		readKeys.getline(keyChar, '\n');
		if (keyChar[0]!='\0')
			keys.push_back(keyChar);
	}
}
void KeyRetrieval::addToList()
{
	addRange(10, 10);
	addRange(32, 47);
	addRange(58, 64);
	addRange(91, 96);
	addRange(123, 126);

	addRange(48, 57);

	addRange(65, 90);
	addRange(97, 122);
}
void KeyRetrieval::addRange(int from, const int to)
{
	for (; from<=to; ++from)
		codeCharacter.push_back(from);
}

std::vector<std::string> KeyRetrieval::keyStructure() { return keys; }
std::vector<int> KeyRetrieval::codeCharacterStructure() { return codeCharacter; }
