#include<fstream>
#include"Encryption.h"
#include"GeneratePasswordFileName.h"
#include"KeyRetrieval.h"
#include"FileNameRetrieval.h"
#include"FolderStructure.h"

Encryption::Encryption(const string& message, const string& keyPath)
{
	this->message = message;
	setupMap(keyPath);
	configurePasswordFileName();
	//encryptMessage();
}
Encryption::Encryption(const Password<>& pass, const Key<>& ky)
{
	message.assign(pass.retrieveDecryptedMessage());
	setupMap(ky.path());
	encryptMessage(pass);
}

void Encryption::setEncryptedMessage(const string& encryptedMessage) { this->encryptedMessage = encryptedMessage; }
void Encryption::setMessage(const string& message) { this->message = message; }
void Encryption::encryptMessage(const Password<>& pass)
{
	fstream ioEvent{};
	ioEvent.open(pass.passwordPath(), std::ios::out);
	auto p = pass.passwordPath();

	addMetadata(pass, ioEvent);

	for (auto indexOfString = 0u; indexOfString!=message.size(); ++indexOfString)
	{
		ioEvent << encryptedCharacters[message.at(indexOfString)];
		encryptedMessage += encryptedCharacters[message.at(indexOfString)];
	}
	this->encryptedMessage = encryptedMessage;	
	ioEvent.close();
}
void Encryption::addMetadata(const Password<>& pass, fstream& ioEvent)
{
	auto yearLocal = pass.year;
	auto monthLocal = pass.month;
	auto dayOfMonthLocal = pass.dayOfMonth;

	ioEvent << yearLocal << '\n' << monthLocal << '\n' << dayOfMonthLocal << '\n';
}


void Encryption::setupMap(const string& keyPath)
{
	KeyRetrieval kr{keyPath};
	vector<string> k{kr.keyStructure()};
	vector<int> c{kr.codeCharacterStructure()};

	for (auto index = 0u; index!=k.size(); ++index)
		encryptedCharacters[c[index]] = k[index];
}
void Encryption::configurePasswordFileName()
{
	for (auto passwordNameDoesNotExist = true; passwordNameDoesNotExist; passwordNameDoesNotExist = repetitive())
	{
		GeneratePasswordFileName gp{};
		passwordFileName.assign(gp.passwordFileNameString());
	}
	string tmpString{passwordFileName};
	passwordFileName.assign(FolderStructure::passwordDirectory);
	passwordFileName.append(tmpString);
}
bool Encryption::repetitive()
{
	passwordFileName.append(".txt");
	FileNameRetrieval fnr;
	fnr.retrievePasswordNames();
	vector<string> createdPasswordNames{fnr.passwordNameContainer()};
	auto count = 0;
	for (auto cPNBegin = createdPasswordNames.begin(); cPNBegin!=createdPasswordNames.end(); ++cPNBegin)
	{
		if (passwordFileName.compare(*cPNBegin)==0) ++count;
		if (count>0) return true;
	}
	return false;
}
string Encryption::getEncryptedMessage() const { return encryptedMessage; }
string Encryption::getMessage() const { return message; }
map<char, string> Encryption::encryptedCharactersStructure() { return encryptedCharacters; }
