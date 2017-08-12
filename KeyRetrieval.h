#ifndef KEYRETRIEVAL_H
#define KEYRETRIEVAL_H

#include<vector>
#include<string>
#include<list>

class KeyRetrieval
{
public:
	KeyRetrieval();
	KeyRetrieval(const std::string);
	~KeyRetrieval() = default;

	void retrieveKey();
	void addToList();
	void addRange(int, const int);
	void fileNameChoice(const std::string&);

	std::vector<std::string> keyStructure();
	std::vector<int> codeCharacterStructure();
private:
	std::string fileName{"default_keys.txt"};
	std::vector<std::string> keys;
	std::vector<char> characters;
	std::vector<int> codeCharacter;
	const int keySize{5};
};
#endif
