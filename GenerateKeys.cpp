#include<iostream>
#include<cstdlib>
#include<ctime>
#include<sstream>
#include<fstream>
#include<ios>
#include<ctime>
#include"GenerateKeys.h"
#include"FolderStructure.h"

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

	//populateDecryptedValues();
	//populateEncryptedValues();
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

void GenerateKeys::generatedFileName()
{
	time_t epochTime = time(0);
	tm* currentTime = localtime(&epochTime);

	auto year = 1900+currentTime->tm_year;
	auto month = 1+currentTime->tm_mon;
	auto dayOfmonth = currentTime->tm_mday;

	if (month<10 && dayOfmonth<10)
	{
		defaultKeyFileName.assign(std::to_string(year));
		defaultKeyFileName.append("0"+std::to_string(month));
		defaultKeyFileName.append("0"+std::to_string(dayOfmonth));
	}	
	else if (month<10 && dayOfmonth>=10)
	{
		defaultKeyFileName.assign(std::to_string(year));
		defaultKeyFileName.append("0"+std::to_string(month));
		defaultKeyFileName.append(std::to_string(dayOfmonth));
	}
	else if (month>=10 && dayOfmonth<10)
	{
		defaultKeyFileName.assign(std::to_string(year));
		defaultKeyFileName.append(std::to_string(month));
		defaultKeyFileName.append("0"+std::to_string(dayOfmonth));
	}
	else
	{
		defaultKeyFileName.assign(std::to_string(year));
		defaultKeyFileName.append(std::to_string(month));
		defaultKeyFileName.append(std::to_string(dayOfmonth));
	}
	for (auto index=0; index!=8; ++index)
	{
		if (index==0) defaultKeyFileName.append("_");
		else 
		{
			auto randomInteger = rand()%10;
			defaultKeyFileName.append(std::to_string(randomInteger));
		}	
	}
	defaultKeyFileName.append(".txt");
	std::cout<<defaultKeyFileName<<std::endl;
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
	for (auto index = 0u; index!=allCharacters.size(); ++index)
	{
		std::string tmpKey{};	
		generateKey(tmpKey, keySize);
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
	for (auto index = 0u; index!=allCharacters.size(); ++index)
	{
		std::string chosenOne{keys[index]};
		auto repetition{0};
		for (auto innerIndex = 0u; innerIndex!=allCharacters.size(); ++innerIndex)
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
	dump.open(FolderStructure::keyDirectory+defaultKeyFileName, std::ios::out);
	for (auto index = 0u; index!=keys.size(); ++index)
		dump << keys[index] << '\n';
	dump.close();
	std::cout<<"dumped in: "<<FolderStructure::keyDirectory<<std::endl;
}


char GenerateKeys::getChar(std::vector<int>& ch)
{
	char hc = ch[rand() % ch.size()];
	while (hc==32 || hc==10)
		hc = getChar(ch);

	return hc;
}
