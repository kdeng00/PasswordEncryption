#ifndef FILENAMERETRIEVAL_H_
#define FILENAMERETRIEVAL_H_

#include<vector>
#include<string>

class FileNameRetrieval
{
public:
	FileNameRetrieval();

	void retrieveFileNames();
	void retrievePasswordNames();
	std::vector<std::string> fileNameContainer() const;
	std::vector<std::string> passwordNameContainer() const;
private:
	std::vector<std::string> fileNames;
	std::vector<std::string> passwordNames;
};
#endif
