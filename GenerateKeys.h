#ifndef GENERATEKEYS_H
#define GENERATEKEYS_H

#include<map>
#include<forward_list>
#include<iostream>
#include<cstdlib>
#include<sstream>
#include<fstream>
#include<ios>
#include"Characters.h"
#include"GenerateDate.h"
#include"FolderStructure.h"
#include"Key.h"

using std::vector;
using std::string;
using std::forward_list;	
using std::array;
using std::stringstream;
using std::size_t;
using std::to_string;
using std::fstream;

class GenerateKeys : public Characters<char>
{
public:

	GenerateKeys();
	~GenerateKeys() = default;

	void keyMove(Key<>&);
	void keyDump(Key<>&);

	friend class Encryption;
	friend class Decryption;
	friend class KeyManagementWindow;
private:
	void generatedFileName();	
	void populateSymbols();
	void populateNumbers();
	void populateLetters();
	template<typename C, typename L>
	void addToDesignatedContainer(C&, const L&);	
	template<typename C, typename DT>
	void addRange(C&, DT, const DT);
	template<typename C>
	void addToCentralContainer(C&);

	template<typename S, typename DT>
	void generateKey(S&, const DT);
	bool isThereRepetition(const Key<>&);
	template<typename C>
	void print(const C&);

	template<typename C>
	char getChar(const C&);

	string defaultKeyFileName;
	//KeySize show equal the value in key
	const int keySize{5};
};

GenerateKeys::GenerateKeys()
{
	srand(time(0));
	populateSymbols();
	populateNumbers();
	populateLetters();

	addToCentralContainer(symbols);
	addToCentralContainer(numbers);
	addToCentralContainer(letters);

	generatedFileName();
}

void GenerateKeys::generatedFileName()
{
	GenerateDate<string, int> gd;
	defaultKeyFileName.assign(gd.retrieveDateString());
	for (auto index=0; index!=8; ++index)
	{
		if (index==0) defaultKeyFileName.append("_");
		else 
		{
			auto randomInteger = rand()%10;
			defaultKeyFileName.append(to_string(randomInteger));
		}	
	}
	defaultKeyFileName.append(".txt");
}
void GenerateKeys::populateSymbols()
{
	forward_list<int> symbolCodes;	
	addRange(symbolCodes, 10, 10);
	addRange(symbolCodes, 32, 47);
	addRange(symbolCodes, 58, 64);
	addRange(symbolCodes, 91, 96);
	addRange(symbolCodes, 123, 126);
	symbolCodes.sort();
	addToDesignatedContainer(symbols, symbolCodes);
}
void GenerateKeys::populateNumbers()
{
	forward_list<int> numberCodes;
	addRange(numberCodes, 48, 57);
	numberCodes.sort();
	addToDesignatedContainer(numbers, numberCodes);
}
void GenerateKeys::populateLetters()
{
	forward_list<int> letterCodes;
	addRange(letterCodes, 65, 90);
	addRange(letterCodes, 97, 122);
	letterCodes.sort();
	addToDesignatedContainer(letters, letterCodes);
}
template<typename C, typename L>
void GenerateKeys::addToDesignatedContainer(C& cont, const L& listOfValues)
{
	auto listIter = listOfValues.begin();
	for (auto index = 0; index!=cont.size() && listIter!=listOfValues.end(); ++index)
	{
		cont[index] = *listIter++;	
	}
}
template<typename C, typename DT>
void GenerateKeys::addRange(C& ch, DT from, const DT to)
{
	auto range = to - from;
	for (auto index = 0; index<=range; ++index, ++from)
		ch.push_front(from);
}
template<typename C>
void GenerateKeys::addToCentralContainer(C& con)
{
	for (auto index = 0u; index!=con.size(); ++index)
		allCharacters.push_back(*&con[index]);
}
template<typename S, typename DT>
void GenerateKeys::generateKey(S& key, const DT size)
{
	S ky;
	ky.resize(size);
	auto begKy = ky.begin();
	for (auto index = 0; index!=size; ++index, ++begKy)
	{
		if (index < 2)
			*begKy = getChar(letters);
		else if (index < 3 && index > 1)
			*begKy = getChar(symbols);
		else
			*begKy = getChar(numbers);
	}
	key.assign(ky);
}
template<typename C>
void GenerateKeys::print(const C& ch)
{
	for (auto beg = ch.begin(); beg!=ch.end(); ++beg)
		std::cout << *beg << " ";
	std::cout << std::endl;
}
void GenerateKeys::keyMove(Key<>& theKey)
{
	vector<string> iGotTheKeysDurf;
	for (auto index = 0u; index!=allCharacters.size(); ++index)
	{
		string tmpKey{};	
		generateKey(tmpKey, keySize);
		iGotTheKeysDurf.push_back(tmpKey);
	}
	theKey.keysInit(iGotTheKeysDurf);
	if (isThereRepetition(theKey))
	{
		iGotTheKeysDurf.clear();
		keyMove(theKey);
	}
	std::cout << "No repetitions in keys" << std::endl;
}
void GenerateKeys::keyDump(Key<>& theKey)
{
	fstream dump{};
	auto path = theKey.path();
	auto iGotTheKeysDurf = theKey.retrieveKeys();
	dump.open(path, std::ios::out);
	for (auto index = 0u; index!=iGotTheKeysDurf.size(); ++index)
		dump << iGotTheKeysDurf[index] << '\n';
	dump.close();
}
template<typename C>
char GenerateKeys::getChar(const C& ch)
{
	char whitespace = 32;
	char newLine = 10;
	char hc = ch[rand() % ch.size()];
	while (hc==whitespace || hc==newLine)
		hc = getChar(ch);

	return hc;
}
bool GenerateKeys::isThereRepetition(const Key<>& theKey)
{
	vector<string> iGotTheKeysDurf = theKey.retrieveKeys();
	for (auto index = 0u; index!=allCharacters.size(); ++index)
	{
		string chosenOne{iGotTheKeysDurf[index]};
		auto repetition = 0;
		for (auto innerIndex = 0u; innerIndex!=allCharacters.size(); ++innerIndex)
			if (chosenOne == iGotTheKeysDurf[innerIndex])
				++repetition;
		if (repetition > 1)
		{	
			std::cout << "Too much repetitive stuff" << std::endl;
			return true;
		}	
	}
	return false;
}
#endif
