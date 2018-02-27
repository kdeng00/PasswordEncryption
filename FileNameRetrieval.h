#ifndef FILENAMERETRIEVAL_H_
#define FILENAMERETRIEVAL_H_

#include<vector>
#include<string>

using std::string;
using std::vector;

class FileNameRetrieval
{
public:
	FileNameRetrieval();

	void retrieveFileNames();
	void retrievePasswordNames();
	vector<string> fileNameContainer() const;
	vector<string> passwordNameContainer() const;
private:
	vector<string> fileNames;
	vector<string> passwordNames;
};
#endif
