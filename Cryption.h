#ifndef CRYPTION_H
#define CRYPTION_H

#include <fstream>
#include <string>

class Cryption
{
public:
	Cryption();
	Cryption(const std::string&);
	//void setMessage(const std::string&);

	std::string getMessage() const;
protected:
	void setMessage(const std::string&);

	std::string message{};
	std::fstream ioEvent{};
};

#endif
