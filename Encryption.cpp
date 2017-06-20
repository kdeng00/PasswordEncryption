#include<ios>
#include<iostream>
#include<fstream>
#include<string>

#include"Encryption.h"
#include"GenerateKeys.h"

Encryption::Encryption(const std::string& message)
{ 
	this->message = message; 
	encryptMessage();
}


void Encryption::setEncryptedMessage(const std::string& encryptedMessage)
{ this->encryptedMessage = encryptedMessage; }
void Encryption::encryptMessage()
{
	GenerateKeys gk{};	
	std::fstream ioEvent{};
	ioEvent.open("encryptedFile.txt", std::ios::out);

	for (auto indexOfString = 0u; indexOfString!=message.size(); ++indexOfString)
	{
		ioEvent << gk.encryptedCharacters[message.at(indexOfString)];
		encryptedMessage += (gk.encryptedCharacters[message.at(indexOfString)]);
	}
	this->encryptedMessage = encryptedMessage;	
	ioEvent.close();
}


std::string Encryption::getEncryptedMessage() const
{ return encryptedMessage; }
