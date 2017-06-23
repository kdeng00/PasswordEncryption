#include<ios>
#include<iostream>
#include<fstream>
#include<string>

#include"Encryption.h"
#include"GenerateKeys.h"
#include"KeyRetrieval.h"

Encryption::Encryption(const std::string& message)
{ 
	this->message = message; 
	setupMap();

	encryptMessage();
}


void Encryption::setEncryptedMessage(const std::string& encryptedMessage)
{ this->encryptedMessage = encryptedMessage; }
void Encryption::setMessage(const std::string& message)
{ this->message = message; }
void Encryption::encryptMessage()
{
	std::fstream ioEvent{};
	ioEvent.open("encryptedFile.txt", std::ios::out);

	for (auto indexOfString = 0u; indexOfString!=message.size(); ++indexOfString)
	{
		ioEvent << encryptedCharacters[message.at(indexOfString)];
		encryptedMessage += encryptedCharacters[message.at(indexOfString)];
	}
	this->encryptedMessage = encryptedMessage;	
	ioEvent.close();
}


void Encryption::setupMap()
{
	KeyRetrieval kr{};
	std::vector<std::string> k{kr.keyStructure()};
	std::vector<int> c{kr.codeCharacterStructure()};

	for (auto index = 0; index!=k.size(); ++index)
		encryptedCharacters[c[index]] = k[index];
}
std::string Encryption::getEncryptedMessage() const
{ return encryptedMessage; }
std::string Encryption::getMessage() const
{ return message; }
std::map<char, std::string> Encryption::encryptedCharactersStructure() { return encryptedCharacters; }
