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

	void encryptMessage();

private:
};

#endif
