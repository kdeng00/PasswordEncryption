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
	int numberOfNewLines{0};
	GenerateKeys* gk = new GenerateKeys;	
	ioEvent.open("encryptedFile.txt", std::ios::out);

	std::cout << "String to encrypt: " << message << std::endl;
	//while (numberOfNewLines != message.size())
	for (unsigned int index = 0; index != message.size(); ++index)
	{
		char stringIndex = message.at(index);
		//if (message.at(index) == "\n")
		//if (message.at(index).compare("\n") == 0)	
		if (stringIndex == '\n')
		{
			++numberOfNewLines;
		}
	}
	std::cout << "The message has " << numberOfNewLines << " new lines" << std::endl;
	for (unsigned short indexOfString = 0; indexOfString < message.size(); indexOfString++)
	{
		ioEvent << gk->encryptedCharacters[message.at(indexOfString)];
		//std::cout << gk->encryptedCharacters[message.at(indexOfString)] << std::endl;
		encryptedMessage += std::to_string(gk->encryptedCharacters[message.at(indexOfString)]);
		//std::cout << encryptedMessage << std::endl;
	}

	setEncryptedMessage(encryptedMessage);
	ioEvent.close();

	delete gk;
}


std::string Encryption::getEncryptedMessage() const
{
	return encryptedMessage;
}
