#ifndef CRYPTION_H
#define CRYPTION_H

#include<string>

using std::string;

class Cryption
{
public:
	Cryption() = default;
	~Cryption() = default;
	Cryption(const string&);

	virtual void setMessage(const string&) = 0;
	virtual string getMessage() const = 0;

	string message;
};

#endif
