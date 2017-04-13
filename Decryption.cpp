#include <iostream>
#include <ios>
#include <string>

#include "Decryption.h"
#include "GenerateKeys.h"

Decryption::Decryption()
{
		
}
Decryption::Decryption(const std::string& message)
{
	this->message = message;
}


void Decryption::setDecryptedMessage(const std::string& message)
{
	this->decryptedMessage = message;
}	
void Decryption::decryptMessage()
{
	GenerateKeys gk;	

	ioEvent.open("encryptedFile.txt", std::ios::in);

	std::string messageToBeDecrypted, decryptedMessage;

	while(!ioEvent.eof())
	{
		ioEvent >> messageToBeDecrypted;
	}

	ioEvent.close();

	unsigned short encryptedTwoKey = 2;
	unsigned short beginningOfAlphabetLowerCase = 97;
	unsigned short endingOfAplphabetLowerCase = 122;
	unsigned short whiteSpaceASCIICode = 32;
	for (unsigned short index = 0; index < messageToBeDecrypted.size(); index++)
	{
		if ((index + encryptedTwoKey) < messageToBeDecrypted.size())
		{
			char otherElements[] = {messageToBeDecrypted.at(index), messageToBeDecrypted.at(index + 1), messageToBeDecrypted.at(index + 2)};
			unsigned short number = atoi(otherElements);

			if ((number > endingOfAplphabetLowerCase || number < beginningOfAlphabetLowerCase) && (number != whiteSpaceASCIICode))
			{
				otherElements[0] = {messageToBeDecrypted.at(index)};
				otherElements[1] = {messageToBeDecrypted.at(index + 1)};
				otherElements[2] = {' '};
				number = atoi(otherElements);
				decryptedMessage += gk.decryptedCharacters[number];
				index += 1;
			}
			else
			{
				decryptedMessage += gk.decryptedCharacters[number];
				index += 2;
			}
		}
	}
	setDecryptedMessage(decryptedMessage);
}


std::string Decryption::getDecryptedMessage() const
{

	return decryptedMessage;
}	
