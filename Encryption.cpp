#include<ios>
#include<iostream>
#include<string>

#include"Encryption.h"
#include"GenerateKeys.h"

Encryption::Encryption()
{ }

Encryption::~Encryption()
{ }

Encryption::Encryption(const std::string& message)
{ this->message = message; }


void Encryption::setEncryptedMessage(const std::string& encryptedMessage)
{ this->encryptedMessage = encryptedMessage; }
void Encryption::encryptMessage()
{
	auto numberOfNewLines = 0;
	GenerateKeys gk{};	
	ioEvent.open("encryptedFile.txt", std::ios::out);

	for (auto index = 0; index != message.size(); ++index)
	{
		char stringIndex = message.at(index);
		if (stringIndex == '\n')
			++numberOfNewLines;
	}
	for (auto indexOfString = 0; indexOfString!=message.size(); ++indexOfString)
	{
		ioEvent << gk.encryptedCharacters[message.at(indexOfString)];
		encryptedMessage += (gk.encryptedCharacters[message.at(indexOfString)]);
	}
	setEncryptedMessage(encryptedMessage);
	ioEvent.close();
}


std::string Encryption::getEncryptedMessage() const
{ return encryptedMessage; }
