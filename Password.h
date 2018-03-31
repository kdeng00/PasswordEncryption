#ifndef PASSWORD_H_
#define PASSWORD_H_

#include<iostream>
#include<string>
#include"Encryption.h"
#include"FileNameRetrieval.h"
#include"GeneratePasswordFileName.h"
#include"TimeInformation.h"

template<typename S = string>
class Password : public TimeInformation<int>
{
	S filename;
	const S passwordDirectory{FolderStructure::passwordDirectory};
	S encryptedMessage;
	S decryptedMessage;
	int year, month, day;
public:	
	Password();
	Password(const S&);

	friend class Encryption;

	void setupEncryptedMessage(const S&);
	void setupDecryptedMessage(const S&);
	void setupPasswordFilename();
	void setupPasswordFilename(const S&);
	void setupDate();
	S retrieveEncryptedMessage() const;
	S retrieveDecryptedMessage() const;
	S passwordFilename() const;
	S passwordPath() const;
	bool repetitive();
};


template<typename S>
Password<S>::Password()
{
	setupPasswordFilename();
}
template<typename S>
Password<S>::Password(const S& filename) : filename(filename) { }

template<typename S>
void Password<S>::setupEncryptedMessage(const S& pass) { encryptedMessage.assign(pass); }
template<typename S>
void Password<S>::setupDecryptedMessage(const S& pass) { decryptedMessage.assign(pass); }
template<typename S>
void Password<S>::setupPasswordFilename()
{
	for (auto passwordNameDoesNotExist = true; passwordNameDoesNotExist; passwordNameDoesNotExist = repetitive())
	{
		GeneratePasswordFileName gp{};
		year = gp.retrieveYear();
		month = gp.retrieveMonth();
		dayOfMonth = gp.retrieveDayOfMonth();
		filename.assign(gp.passwordFileNameString());
	}
}
template<typename S>
void Password<S>::setupPasswordFilename(const S& fin)
{
	for (auto passwordNameDoesNotExist = true; passwordNameDoesNotExist; passwordNameDoesNotExist = repetitive())
	{
		filename.assign(fin);
	}	
}
template<typename S>
S Password<S>::retrieveEncryptedMessage() const { return encryptedMessage; }
template<typename S>
S Password<S>::retrieveDecryptedMessage() const { return decryptedMessage; }
template<typename S>
S Password<S>::passwordFilename() const { return filename; }
template<typename S>
S Password<S>::passwordPath() const { return passwordDirectory + filename; }


template<typename S>
bool Password<S>::repetitive()
{
	filename.append(".txt");
	FileNameRetrieval fnr;
	fnr.retrievePasswordNames();
	vector<string> createdPasswordNames{fnr.passwordNameContainer()};
	auto count = 0;
	for (auto cPNBegin = createdPasswordNames.begin(); cPNBegin!=createdPasswordNames.end(); ++cPNBegin)
	{
		if (filename.compare(*cPNBegin)==0) ++count;
		if (count>0) return true;
	}
	return false;
}
#endif
