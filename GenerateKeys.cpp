#include<iostream>
#include<sstream>
#include<fstream>
#include<ios>

#include"GenerateKeys.h"

GenerateKeys::GenerateKeys()
{
	populateSymbols();
	populateNumbers();
	populateLetters();

	addToCentralContainer(symbols);
	addToCentralContainer(numbers);
	addToCentralContainer(letters);

	populateDecryptedValues();
	populateEncryptedValues();
}

void GenerateKeys::populateDecryptedValues()
{
	std::fstream readKeys{};
	readKeys.open(defaultKeyFileName, std::ios::in);
	std::string tmpKey{};
	for (auto index = 0u; index!=allCharacters.size(); ++index)
	{
		readKeys >> tmpKey;
		decryptedCharacters[tmpKey] = static_cast<char>(allCharacters[index]);
		tmpKey.assign("");
	}
	readKeys.close();
}
void GenerateKeys::populateEncryptedValues()
{
	std::fstream readKeys{};
	readKeys.open(defaultKeyFileName, std::ios::in);
	std::string tmpKey{};
	for (auto index = 0u; index!=allCharacters.size(); ++index)
	{	
		readKeys >> tmpKey;
		encryptedCharacters[decryptedCharacters[tmpKey]] = tmpKey;
		tmpKey.assign("");
	}
	readKeys.close();
}

void GenerateKeys::populateSymbols()
{
	addRange(symbols, 10, 10);
	addRange(symbols, 32, 47);
	addRange(symbols, 58, 64);
	addRange(symbols, 91, 96);
	addRange(symbols, 123, 126);
}
void GenerateKeys::populateNumbers()
{
	addRange(numbers, 48, 57);
}
void GenerateKeys::populateLetters()
{
	addRange(letters, 65, 90);
	addRange(letters, 97, 122);
}
void GenerateKeys::addRange(std::vector<int>& ch, int from, const int to)
{
	auto range = to - from;
	for (auto index = 0; index<=range; ++index, ++from)
		ch.push_back(from);
}
void GenerateKeys::addToCentralContainer(std::vector<int>& con)
{
	for (auto index = 0u; index!=con.size(); ++index)
		allCharacters.push_back(con[index]);
}
void GenerateKeys::generateKey(std::string& key, const int& SIZE)
{
	char ky[SIZE]{};
	for (auto index = 0; index!=SIZE; ++index)
	{
		if (index < 2)
			ky[index] = getChar(letters);
		else if (index < 3 && index > 1)
			ky[index] = getChar(symbols);
		else
			ky[index] = getChar(numbers);
	}
	std::stringstream charToString;
	for (auto index = 0; index!=SIZE; ++index)
		charToString << ky[index];
	while (charToString>>key);
}
void GenerateKeys::keyMove()
{
	for (auto index = 0; index!=allCharacters.size(); ++index)
	{
		std::string tmpKey{};	
		generateKey(tmpKey, keySize);
		std::cout << "Generated Key: " << tmpKey << std::endl;
		keys.push_back(tmpKey);
	}
	if (isThereRepetition())
	{
		keys.clear();
		keyMove();
	}
	std::cout << "No repetitions in keys" << std::endl;
}
void GenerateKeys::print(const std::vector<int>& ch)
{
	for (auto index = 0u; index!=ch.size(); ++index)
		std::cout << ch[index] << " ";
	std::cout << std::endl;
}
bool GenerateKeys::isThereRepetition()
{
	for (auto index = 0; index!=allCharacters.size(); ++index)
	{
		std::string chosenOne{keys[index]};
		auto repetition{0};
		for (auto innerIndex = 0; innerIndex!=allCharacters.size(); ++innerIndex)
			if (chosenOne == keys[innerIndex])
				++repetition;
		if (repetition > 1)
		{	
			std::cout << "Too much repetitive stuff" << std::endl;
			return true;
		}	
	}
	return false;
}
void GenerateKeys::keyDump()
{
	std::fstream dump{};
	dump.open(defaultKeyFileName, std::ios::out);
	for (auto index = 0u; index!=keys.size(); ++index)
		dump << keys[index] << '\n';
	dump.close();
}


char GenerateKeys::getChar(std::vector<int>& ch)
{
	char hc = ch[rand() % ch.size()];
	while (hc==32 || hc==10)
		hc = getChar(ch);

	return hc;
}
