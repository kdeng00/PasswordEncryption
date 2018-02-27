#include"FolderStructure.h"

string FolderStructure::rootDirectory{};
string FolderStructure::keyDirectory{};
string FolderStructure::passwordDirectory{};
string FolderStructure::settingDirectory{};

void FolderStructure::setupPaths(const char* rootPath)
{
	rootDirectory.assign(rootPath);
	keyDirectory.assign(rootPath);
	passwordDirectory.assign(rootPath);
	settingDirectory.assign(rootPath);
	keyDirectory.append("/keys/");
	passwordDirectory.append("/passwords/");
	settingDirectory.append("/settings/");
}
