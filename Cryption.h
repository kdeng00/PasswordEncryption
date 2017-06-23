#ifndef CRYPTION_H
#define CRYPTION_H

#include<string>

class Cryption
{
public:
	Cryption() = default;
	~Cryption() = default;
	Cryption(const std::string&);

	virtual void setMessage(const std::string&) = 0;
	virtual std::string getMessage() const = 0;

	std::string message;
};

#endif
