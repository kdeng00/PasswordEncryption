#ifndef FOLDERSTRUCTURE_H_
#define FOLDERSTRUCTURE_H_

#include<string>

using std::string;

struct FolderStructure
{
	static string rootDirectory;
	static string keyDirectory;
	static string passwordDirectory;
	static string settingDirectory;

	void setupPaths(const char*);
};

#endif
