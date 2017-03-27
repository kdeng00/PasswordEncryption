#include <ios>

#include "Encryption.h"
#include "GenerateKeys.h"

Encryption::Encryption()
{
		
}
Encryption::Encryption(const std::string& message)
{
	this->message = message;
}


void Encryption::encryptMessage()
{
	GenerateKeys* gk = new GenerateKeys;	
	ioEvent.open("encryptedFile.txt", std::ios::out);

	for (unsigned short indexOfString = 0; indexOfString < message.size(); indexOfString++)
	{
		ioEvent << gk->encryptedCharacters[message.at(indexOfString)];
	}

	ioEvent.close();

	delete gk;
}
