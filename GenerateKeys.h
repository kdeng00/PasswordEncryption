#ifndef GENERATEKEYS_H
#define GENERATEKEYS_H

#include <map>

class GenerateKeys
{
public:
	typedef unsigned short unsignedShort;

	GenerateKeys();

	void populateDecryptedValues();
	void populateEncryptedValues();

	friend class Encryption;
	friend class Decryption;

private:
	std::map<unsignedShort, char> decryptedCharacters;
	std::map<char, unsignedShort> encryptedCharacters;
};

#endif
