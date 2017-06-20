#ifndef CRYPTION_H
#define CRYPTION_H

#include<string>

class Cryption
{
public:
	Cryption() = default;
	~Cryption() = default;
	Cryption(const std::string&);

	std::string getMessage() const;
protected:
	void setMessage(const std::string&);

	std::string message;
};

#endif
