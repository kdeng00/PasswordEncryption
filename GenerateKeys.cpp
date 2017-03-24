#include <iostream>

#include "GenerateKeys.h"

GenerateKeys::GenerateKeys()
{

	populateDecryptedValues();
	populateEncryptedValues();
}

void GenerateKeys::populateDecryptedValues()
{
	for (unsigned short number = 0; number < 300; number++)
	{
		char character;
		character = static_cast<char>(number);

		if (number >= 97 && number <= 122)
		{
			decryptedCharacters[number] = character;	
			//std::cout << decryptedCharacters[number] << " ";
		}
	}
	//std::cout << std::endl;
	decryptedCharacters[32] = ' ';
}
void GenerateKeys::populateEncryptedValues()
{
	for (unsigned short key = 97; key <= 122; key++)
	{
		encryptedCharacters[decryptedCharacters[key]] = key;
		//std::cout << encryptedCharacters[decryptedCharacters[key]] << " ";
	}
	encryptedCharacters[decryptedCharacters[32]] = 32;
	//std::cout << std::endl;
}
