#ifndef DECRYPTION_H
#define DECRYPTION_H

#include<map>
#include"Cryption.h"
#include"Encryption.h"

using std::map;

class Decryption : public Cryption
{
public:
	Decryption() = default;
	~Decryption() = default;
	Decryption(const string&);
	explicit Decryption(const Password<>&, const Key<>&);

	void setDecryptedMessage(const string&);
	void setMessage(const string&) override;
	void retrieveMetaData();
	void decryptMessage();

	string getDecryptedMessage() const;
	string getMessage() const override;
private:
	void setupMap(const Key<>&);
	string decryptedMessage;
	string passwordPath;
	map<string, char> decryptedCharacters;
	const int keyLength{5};
};

#endif
