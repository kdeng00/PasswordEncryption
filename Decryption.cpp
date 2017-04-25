#include <iostream>
#include<sstream>
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
	GenerateKeys gk{};	

	ioEvent.open("encryptedFile.txt", std::ios::in);

	std::string messageToBeDecrypted{}, decryptedMessage{};

	while(ioEvent >> messageToBeDecrypted)

	ioEvent.close();

	for (auto indexOfChar = 0; indexOfChar<messageToBeDecrypted.size(); indexOfChar+=5)
	{
		char cryptedKey[5]{};
		for (auto index = 0; index!=5; ++index)
		{
			cryptedKey[index] = (messageToBeDecrypted.at(indexOfChar + index));	
			
		}
		decryptedMessage += gk.decryptedCharacters[cstringToString(cryptedKey, 5)];
	}
	//std::cout << "Decrypted Message: " << decryptedMessage << std::endl;
	setDecryptedMessage(decryptedMessage);
}


std::string Decryption::getDecryptedMessage() const
{
	return decryptedMessage;
}	
std::string Decryption::cstringToString(char tmp[], const int& SIZE)
{
	std::string tmpString{};
	std::stringstream cToS{};	
	for (auto index = 0; index!=5; ++index)
	{
		cToS << tmp[index];	
	}
	cToS >> tmpString;
	return tmpString;
}


unsigned short getTwoNumberedKey(unsigned short& number)
{
	std::string wholeNumber{std::to_string(number)};
	char hundred[] = {wholeNumber.at(0)};
	char ten[] = {wholeNumber.at(1)};
	char one[] {wholeNumber.at(2)};


	unsigned short hundread, tenN, oneN;
	hundread = number;
}
