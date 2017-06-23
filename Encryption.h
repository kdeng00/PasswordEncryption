#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include<fstream>
#include<string>
#include<map>
#include"Cryption.h"

class Encryption : public Cryption
{
public:
	Encryption() = default;
	~Encryption() = default;
	Encryption(const std::string&);

	void setEncryptedMessage(const std::string&);
	void setMessage(const std::string&) override;
	void encryptMessage();

	std::string getEncryptedMessage() const;
	std::string getMessage() const override;
	std::map<char, std::string> encryptedCharactersStructure();
private:
	void setupMap();
	std::string encryptedMessage;
	std::map<char, std::string> encryptedCharacters;
};

#endif
