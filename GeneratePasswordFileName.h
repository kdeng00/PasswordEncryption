#ifndef GENERATEPASSWORDFILENAME_H_
#define GENERATEPASSWORDFILENAME_H_

#include<string>

class GeneratePasswordFileName
{
public:
	GeneratePasswordFileName();
	std::string passwordFileNameString() const;
private:	
	void generatedFileName();
	std::string filename;
};
#endif
