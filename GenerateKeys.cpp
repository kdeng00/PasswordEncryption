#include <iostream>
#include<sstream>
#include<fstream>
#include<ios>

#include "GenerateKeys.h"

GenerateKeys::GenerateKeys()
{
	populateSymbols();
	populateNumbers();
	populateLetters();

	for (auto index = 0; index!=symbols.size(); ++index)
		allCharacters.push_back(symbols[index]);
	for (auto index = 0; index!=numbers.size(); ++index)
		allCharacters.push_back(numbers[index]);
	for (auto index = 0; index!=letters.size(); ++index)
		allCharacters.push_back(letters[index]);

	populateDecryptedValues();
	populateEncryptedValues();
}

void GenerateKeys::populateDecryptedValues()
{
	std::fstream readKeys{};
	readKeys.open("default_keys.txt", std::ios::in);
	std::string tmpKey{};
	for (auto index = 0; index!=allCharacters.size(); ++index)
	{
		readKeys >> tmpKey;
		decryptedCharacters[tmpKey] = static_cast<char>(allCharacters[index]);
		tmpKey = "";
	}
	readKeys.close();
	decryptedCharacters["#2a9u"] = (char) 32;
	decryptedCharacters["6*dw4"] = (char) 10;
}
void GenerateKeys::populateEncryptedValues()
{
	std::fstream readKeys{};
	readKeys.open("default_keys.txt", std::ios::in);
	std::string tmpKey{};
	for (auto index = 0; index!=allCharacters.size(); ++index)
	{	
		readKeys >> tmpKey;
		encryptedCharacters[decryptedCharacters[tmpKey]] = tmpKey;
		tmpKey = "";
	}
	readKeys.close();
	encryptedCharacters[(char) 32] = "#2a9u";
	encryptedCharacters[(char) 10] = "6*dw4";
}

void GenerateKeys::populateSymbols()
{
	symbols.push_back(33);
	addRange(symbols, 35, 38);
	addRange(symbols, 40, 46);
	addRange(symbols, 58, 64);
	addRange(symbols, 93, 96);
	addRange(symbols, 123, 126);
}
void GenerateKeys::populateNumbers()
{
	addRange(numbers, 48, 57);
}
void GenerateKeys::populateLetters()
{
	addRange(letters, 97, 122);
}
void GenerateKeys::addRange(std::vector<int>& ch, int from, const int to)
{
	auto range = to - from;
	for (auto index = 0; index<=range; ++index)
	{
		ch.push_back(from);
		++from;
	}
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
	while (charToString>>key)
		charToString >> key;
}
void GenerateKeys::keyMove()
{
	std::string tmpKey{};
	for (auto index = 0; index!=totalCharacters; ++index)
	{
		generateKey(tmpKey, keySize);
		keys.push_back(tmpKey);
		tmpKey = "";
	}
}
void GenerateKeys::print(const std::vector<int>& ch)
{
	for (auto index = 0; index!=ch.size(); ++index)
		std::cout << ch[index] << " ";
	std::cout << std::endl;
}
void GenerateKeys::checkRepetition()
{
	for (auto index = 0; index!=totalCharacters; ++index)
	{
		std::string chosenOne{keys[index]};
		auto repetition{0};
		for (auto innerIndex = 0; innerIndex!=totalCharacters; ++innerIndex)
		{
			if (chosenOne == keys[innerIndex])
				++repetition;
		}
		if (repetition > 1)
			std::cout << "Too much repetitive stuff" << std::endl;
	}
}
void GenerateKeys::keyDump()
{
	std::fstream dump{};
	dump.open("default_keys.txt", std::ios::out);
	for (auto index = 0; index!=keys.size(); ++index)
		dump << keys[index] << '\n';
	dump.close();
}


char GenerateKeys::getChar(std::vector<int>& ch)
{
	auto hc = ch[rand() % ch.size()];
	return hc;
}
