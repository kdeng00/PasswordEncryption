#ifndef GENERATEPASSWORDFILENAME_H_
#define GENERATEPASSWORDFILENAME_H_

#include"TimeInformation.h"

using std::string;

class GeneratePasswordFileName : public TimeInformation<int>
{
public:
	GeneratePasswordFileName();
	string passwordFileNameString() const;
	int retrieveYear() const;
	int retrieveMonth() const;
	int retrieveDayOfMonth() const;
private:	
	void generatedFileName();
	string filename;
};
#endif
