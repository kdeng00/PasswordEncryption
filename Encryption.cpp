#include <ios>

#include "Encryption.h"
#include "GenerateKeys.h"

Encryption::Encryption()
{
		
}


void Encryption::setMessage(const std::string message)
{
	this->message = message;
}
void Encryption::encryptMessage()
{
	GenerateKeys* gk = new GenerateKeys;	
	writeToFile.open("encryptedFile.txt", std::ios::out);

	for (unsigned short indexOfString = 0; indexOfString < message.size(); indexOfString++)
	{
		writeToFile << gk->encryptedCharacters[message.at(indexOfString)];
	}

	writeToFile.close();

	delete gk;
}


std::string Encryption::getMessage() const
{
	return message;
}
