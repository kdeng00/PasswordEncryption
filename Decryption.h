#ifndef DECRYPTION_H
#define DECRYPTION_H

#include <fstream>
#include <string>

class Decryption
{
public:

	Decryption();

	void setMessage(const std::string);
	void decryptMessage();

	std::string getMessage() const;	

private:
	std::fstream readFromFile;
	std::string message;
};

#endif
