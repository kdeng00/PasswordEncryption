#include<ios>
#include<iostream>
#include<fstream>
#include<string>
#include"Encryption.h"
#include"GenerateKeys.h"
#include"GeneratePasswordFileName.h"
#include"KeyRetrieval.h"
#include"FileNameRetrieval.h"
#include"FolderStructure.h"

/**
Encryption::Encryption(const std::string& message)
{ 
	this->message = message; 
	setupMap();

	encryptMessage();
}
*/
Encryption::Encryption(const std::string& message, const std::string& keyPath)
{
	this->message = message;
	setupMap(keyPath);
	configurePasswordFileName();
	encryptMessage();
}

void Encryption::setEncryptedMessage(const std::string& encryptedMessage) { this->encryptedMessage = encryptedMessage; }
void Encryption::setMessage(const std::string& message) { this->message = message; }
void Encryption::encryptMessage()
{
	std::fstream ioEvent{};
	ioEvent.open(passwordFileName, std::ios::out);

	for (auto indexOfString = 0u; indexOfString!=message.size(); ++indexOfString)
	{
		ioEvent << encryptedCharacters[message.at(indexOfString)];
		encryptedMessage += encryptedCharacters[message.at(indexOfString)];
	}
	this->encryptedMessage = encryptedMessage;	
	ioEvent.close();
}


void Encryption::setupMap(const std::string& keyPath)
{
	KeyRetrieval kr{keyPath};
	std::vector<std::string> k{kr.keyStructure()};
	std::vector<int> c{kr.codeCharacterStructure()};

	for (auto index = 0u; index!=k.size(); ++index)
		encryptedCharacters[c[index]] = k[index];
}
void Encryption::configurePasswordFileName()
{
	for (auto passwordNameDoesNotExist = true; passwordNameDoesNotExist; passwordNameDoesNotExist = repetitive())
	{
		GeneratePasswordFileName gp{};
		passwordFileName.assign(gp.passwordFileNameString());
	}
	std::string tmpString{passwordFileName};
	passwordFileName.assign(FolderStructure::passwordDirectory);
	passwordFileName.append(tmpString);
}
bool Encryption::repetitive()
{
	passwordFileName.append(".txt");
	FileNameRetrieval fnr;
	fnr.retrievePasswordNames();
	std::vector<std::string> createdPasswordNames{fnr.passwordNameContainer()};
	auto count = 0;
	for (auto cPNBegin = createdPasswordNames.begin(); cPNBegin!=createdPasswordNames.end(); ++cPNBegin)
	{
		if (passwordFileName.compare(*cPNBegin)==0) ++count;
		if (count>0) return true;
	}
	return false;
}
std::string Encryption::getEncryptedMessage() const { return encryptedMessage; }
std::string Encryption::getMessage() const { return message; }
std::map<char, std::string> Encryption::encryptedCharactersStructure() { return encryptedCharacters; }
