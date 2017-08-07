#ifndef FOLDERSTRUCTURE_H_
#define FOLDERSTRUCTURE_H_

#include<string>

struct FolderStructure
{
	static std::string rootDirectory;
	static std::string keyDirectory;
	static std::string passwordDirectory;
	static std::string settingDirectory;

	void setupPaths(const char*);
};

#endif
