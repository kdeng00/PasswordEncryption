#ifndef FILENAMERETRIEVAL_H_
#define FILENAMERETRIEVAL_H_

#include<vector>
#include<string>

class FileNameRetrieval
{
public:
	FileNameRetrieval();

	void retrieveFileNames();
	std::vector<std::string> fileNameContainer() const;
private:
	std::vector<std::string> fileNames;
};
#endif
