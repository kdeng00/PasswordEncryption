#include<iostream>
#include<fstream>
#include<sstream>
#include<ios>
#include<vector>
#include"Conversions.h"
#include"Decryption.h"
#include"KeyRetrieval.h"

Decryption::Decryption(const std::string& message)
{ 
	this->message = message; 
	setupMap();
	decryptMessage();
}


void Decryption::setDecryptedMessage(const std::string& message) { this->decryptedMessage = message; }	
void Decryption::setMessage(const std::string& message) { this->message = message; }

void Decryption::decryptMessage()
{
	std::fstream ioEvent{};
	ioEvent.open("encryptedFile.txt", std::ios::in);

	std::string messageToBeDecrypted{}, decryptedMessage{};

	while(ioEvent >> messageToBeDecrypted);

	ioEvent.close();

	for (auto indexOfChar = 0u; indexOfChar<messageToBeDecrypted.size(); indexOfChar+=5)
	{
		char cryptedKey[5]{};
		for (auto index = 0; index!=keyLength; ++index)
			cryptedKey[index] = (messageToBeDecrypted.at(indexOfChar + index));	
		Conversions cnvert;			
		decryptedMessage += decryptedCharacters[cnvert.cstringToString(cryptedKey, 5)];
	}
	setDecryptedMessage(decryptedMessage);
}


std::string Decryption::getDecryptedMessage() const { return decryptedMessage; }	
std::string Decryption::getMessage() const { return message; }

void Decryption::setupMap()
{
	KeyRetrieval kr{};
	std::vector<std::string> k{kr.keyStructure()};
	std::vector<int> c{kr.codeCharacterStructure()};

	for (auto index = 0u; index!=c.size(); ++index)
		decryptedCharacters[k[index]] = c[index];
}
