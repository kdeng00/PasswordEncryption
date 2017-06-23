#ifndef GENERATEKEYS_H
#define GENERATEKEYS_H

#include<string>
#include<vector>
#include<map>

class GenerateKeys
{
public:
	GenerateKeys();
	~GenerateKeys() = default;

	void populateDecryptedValues();
	void populateEncryptedValues();
	void keyMove();
	void keyDump();

	friend class Encryption;
	friend class Decryption;
	friend class KeyManagementWindow;
private:
	
	void populateSymbols();
	void populateNumbers();
	void populateLetters();
	void addRange(std::vector<int>&, int, const int);
	void addToCentralContainer(std::vector<int>&);

	void generateKey(std::string&, const int&);
	bool isThereRepetition();
	void print(const std::vector<int>&);

	char getChar(std::vector<int>&);


	std::vector<std::string> keys{};
	std::vector<int> symbols;
	std::vector<int> numbers;
	std::vector<int> letters;
	std::vector<int> allCharacters;
	std::map<char, std::string> encryptedCharacters{};
	std::map<std::string, char> decryptedCharacters{};

	std::string defaultKeyFileName{"default_keys.txt"};
	//KeySize show equal the value in key
	const int keySize{5};
	char key[5]{};
};
#endif
