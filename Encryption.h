#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include<map>
#include"Cryption.h"
#include"Key.h"
#include"Password.h"

using std::map;
using std::fstream;

class Encryption : public Cryption
{
public:
	Encryption() = default;
	~Encryption() = default;
	explicit Encryption(const string&, const string&);
	explicit Encryption(const Password<>&, const Key<>&);

	void setEncryptedMessage(const string&);
	void setMessage(const string&) override;
	void encryptMessage(const Password<>&);
	void addMetadata(const Password<>&, fstream&);

	string getEncryptedMessage() const;
	string getMessage() const override;
	map<char, string> encryptedCharactersStructure();
private:
	void setupMap(const string&);
	void configurePasswordFileName();
	bool repetitive();
	string encryptedMessage;
	string passwordFileName;
	map<char, string> encryptedCharacters;
};
#endif
