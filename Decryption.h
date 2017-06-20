#ifndef DECRYPTION_H
#define DECRYPTION_H

#include<fstream>
#include<string>

#include"Cryption.h"

class Decryption : public Cryption
{
public:
	Decryption() = default;
	~Decryption() = default;
	Decryption(const std::string&);

	void setDecryptedMessage(const std::string&);
	void decryptMessage();

	std::string getDecryptedMessage() const;

private:
	std::string cstringToString(char[], const int&);
	std::string decryptedMessage;
};

#endif
