#include<fstream>
#include<ios>
#include<vector>
#include"Conversions.h"
#include"Decryption.h"
#include"KeyRetrieval.h"

Decryption::Decryption(const string& message)
{ 
	this->message = message; 
	//setupMap();
	decryptMessage();
}
Decryption::Decryption(const Password<>& py, const Key<>& ky)
{
	setupMap(ky);
	passwordPath.assign(py.passwordPath());
	decryptMessage();
}


void Decryption::setDecryptedMessage(const string& message) { this->decryptedMessage = message; }	
void Decryption::setMessage(const string& message) { this->message = message; }

void Decryption::retrieveMetaData()
{

}
void Decryption::decryptMessage()
{
	fstream ioEvent{};
	ioEvent.open(passwordPath.c_str(), std::ios::in);

	string messageToBeDecrypted{}, decryptedMessage{};

	while(ioEvent >> messageToBeDecrypted);
	//std::cout << messageToBeDecrypted << std::endl;

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


string Decryption::getDecryptedMessage() const { return decryptedMessage; }	
string Decryption::getMessage() const { return message; }

void Decryption::setupMap(const Key<>& ky)
{
	KeyRetrieval kr{ky};
	vector<string> k{kr.keyStructure()};
	vector<int> c{kr.codeCharacterStructure()};

	for (auto index = 0u; index!=c.size(); ++index)
		decryptedCharacters[k[index]] = c[index];
}
