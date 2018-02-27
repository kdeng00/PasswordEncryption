#ifndef KEYRETRIEVAL_H
#define KEYRETRIEVAL_H

#include<fstream>
#include<vector>
#include<list>
#include"Key.h"

using std::fstream;

class KeyRetrieval
{
public:
	KeyRetrieval();
	KeyRetrieval(const string);
	KeyRetrieval(const Key<>&);
	~KeyRetrieval() = default;

	void retrieveKey();
	void addToList();
	void addRange(int, const int);
	void fileNameChoice(const string&);

	vector<string> keyStructure();
	vector<int> codeCharacterStructure();
private:
	string fileName{"default_keys.txt"};
	vector<string> keys;
	vector<char> characters;
	vector<int> codeCharacter;
	const int keySize{5};
};
#endif
