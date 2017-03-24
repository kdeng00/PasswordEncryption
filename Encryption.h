#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <fstream>
#include <string>

class Encryption
{
public:

	Encryption();

	void setMessage(const std::string);
	void encryptMessage();

	std::string getMessage() const;	

private:
	std::fstream writeToFile;
	std::string message;
};

#endif
