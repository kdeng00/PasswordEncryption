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
	friend class KeyManagementWindow;

private:
	std::map<unsignedShort, char> decryptedCharacters;
	std::map<char, unsignedShort> encryptedCharacters;
	unsigned short startingCharacter = 97;
	unsigned short endingCharacter = 122;
	unsigned short whiteSpaceCharacter = 32;
};

#endif
