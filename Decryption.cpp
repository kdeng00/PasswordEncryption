#include <iostream>
#include <ios>
#include <string>

#include "Decryption.h"
#include "GenerateKeys.h"

Decryption::Decryption()
{
		
}


void Decryption::setMessage(const std::string message)
{
	this->message = message;
}
void Decryption::decryptMessage()
{
	GenerateKeys gk;	

	readFromFile.open("encryptedFile.txt", std::ios::in);

	std::string messageToBeDecrypted, decryptedMessage;

	while(!readFromFile.eof())
	{
		char whiteSpace = static_cast<char>(32);
		//std::cout << "Am I stuck?" << std::endl;
		getline(readFromFile, messageToBeDecrypted, whiteSpace);
	}

	readFromFile.close();

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
				//decryptedMessage.append(gk.decryptedCharacters[number]);
				//newWord += characters[number];
				index += 1;
					
			}
			else
			{
				decryptedMessage += gk.decryptedCharacters[number];
				//decryptedMessage.append(gk.decryptedCharacters[number]);
				//newWord += characters[number];
				index += 2;
			
			}
		}
	}
	setMessage(decryptedMessage);
}


std::string Decryption::getMessage() const
{
	return message;
}
