#include"FolderStructure.h"

std::string FolderStructure::rootDirectory{};
std::string FolderStructure::keyDirectory{};
std::string FolderStructure::passwordDirectory{};
std::string FolderStructure::settingDirectory{};

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
