#include <ios>
#include <iostream>
#include <string>

#include "Encryption.h"
#include "GenerateKeys.h"

Encryption::Encryption()
{
		
}
Encryption::Encryption(const std::string& message)
{
	this->message = message;
}


void Encryption::setEncryptedMessage(const std::string& encryptedMessage)
{
	this->encryptedMessage = encryptedMessage;
}
void Encryption::encryptMessage()
{
	GenerateKeys* gk = new GenerateKeys;	
	ioEvent.open("encryptedFile.txt", std::ios::out);

	for (unsigned short indexOfString = 0; indexOfString < message.size(); indexOfString++)
	{
		ioEvent << gk->encryptedCharacters[message.at(indexOfString)];
		encryptedMessage += std::to_string(gk->encryptedCharacters[message.at(indexOfString)]);
		std::cout << encryptedMessage << std::endl;
	}

	setEncryptedMessage(encryptedMessage);
	ioEvent.close();

	delete gk;
}


std::string Encryption::getEncryptedMessage() const
{
	return encryptedMessage;
}
