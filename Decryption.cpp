#include<iostream>
#include<fstream>
#include<sstream>
#include<ios>
#include<string>

#include"Decryption.h"
#include"GenerateKeys.h"

Decryption::Decryption(const std::string& message)
{ 
	this->message = message; 
	decryptMessage();
}


void Decryption::setDecryptedMessage(const std::string& message)
{ this->decryptedMessage = message; }	

void Decryption::decryptMessage()
{
	GenerateKeys gk{};	
	std::fstream ioEvent{};
	ioEvent.open("encryptedFile.txt", std::ios::in);

	std::string messageToBeDecrypted{}, decryptedMessage{};

	while(ioEvent >> messageToBeDecrypted)

	ioEvent.close();

	for (auto indexOfChar = 0u; indexOfChar<messageToBeDecrypted.size(); indexOfChar+=5)
	{
		char cryptedKey[5]{};
		for (auto index = 0; index!=5; ++index)
			cryptedKey[index] = (messageToBeDecrypted.at(indexOfChar + index));	
			
		decryptedMessage += gk.decryptedCharacters[cstringToString(cryptedKey, 5)];
	}
	setDecryptedMessage(decryptedMessage);
}


std::string Decryption::getDecryptedMessage() const
{ return decryptedMessage; }	

std::string Decryption::cstringToString(char tmp[], const int& SIZE)
{
	std::string tmpString{};
	std::stringstream cToS{};	
	for (auto index = 0; index!=SIZE; ++index)
		cToS << tmp[index];	
	cToS >> tmpString;
	return tmpString;
}
