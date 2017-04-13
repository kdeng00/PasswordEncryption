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
	decryptedCharacters[32] = (char) 32;
	decryptedCharacters[10] = (char) 10;
	//std::cout << std::endl;
	//decryptedCharacters[whiteSpaceCharacter] = ' ';
	//std::cout << "Whitespace character" << decryptedCharacters[whiteSpaceCharacter] << "d" << std::endl;
}
void GenerateKeys::populateEncryptedValues()
{
	for (unsigned short key = startingCharacter; key <= endingCharacter; key++)
	{
		encryptedCharacters[decryptedCharacters[key]] = key;
		//std::cout << encryptedCharacters[decryptedCharacters[key]] << " ";
	}
	encryptedCharacters[(char) 32] = 32;
	encryptedCharacters[(char) 10] = 10;
	//encryptedCharacters[decryptedCharacters[startingCharacter]] = startingCharacter;
	//std::cout << std::endl;
}
