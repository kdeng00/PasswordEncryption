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

		if (number >= startingCharacter && number <= endingCharacter)
		{
			decryptedCharacters[number] = character;	
			//std::cout << decryptedCharacters[number] << " ";
		}
	}
	//std::cout << std::endl;
	decryptedCharacters[whiteSpaceCharacter] = ' ';
}
void GenerateKeys::populateEncryptedValues()
{
	for (unsigned short key = startingCharacter; key <= endingCharacter; key++)
	{
		encryptedCharacters[decryptedCharacters[key]] = key;
		//std::cout << encryptedCharacters[decryptedCharacters[key]] << " ";
	}
	encryptedCharacters[decryptedCharacters[startingCharacter]] = startingCharacter;
	//std::cout << std::endl;
}
