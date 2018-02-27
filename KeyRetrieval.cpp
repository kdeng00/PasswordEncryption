#include<iostream>
#include<ios>
#include"FolderStructure.h"
#include"KeyRetrieval.h"

KeyRetrieval::KeyRetrieval()
{ 
	retrieveKey();
	addToList();
}
KeyRetrieval::KeyRetrieval(const string fileName)
{
	this->fileName.assign(fileName);
	retrieveKey();
	addToList();
}
KeyRetrieval::KeyRetrieval(const Key<>& ky)
{
	auto path = ky.path();
	fileName.assign(path);
	retrieveKey();
	addToList();
}

void KeyRetrieval::retrieveKey()
{
	fstream readKeys{};
	readKeys.open(fileName.c_str());
	char keyChar[keySize];
	while (!readKeys.eof())
	{
		readKeys.getline(keyChar, '\n');
		if (keyChar[0]!='\0')
			keys.push_back(keyChar);
	}
	readKeys.close();
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
void KeyRetrieval::fileNameChoice(const string& fileName) { this->fileName.assign(fileName); }

vector<string> KeyRetrieval::keyStructure() { return keys; }
vector<int> KeyRetrieval::codeCharacterStructure() { return codeCharacter; }
