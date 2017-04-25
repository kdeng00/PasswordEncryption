#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <fstream>
#include <string>

#include "Cryption.h"

class Encryption : public Cryption
{
public:
	Encryption();
	Encryption(const std::string&);

	void setEncryptedMessage(const std::string&);
	void encryptMessage();

	std::string getEncryptedMessage() const;

private:
	std::string encryptedMessage{};
};

#endif
