#include<iostream>
#include"boost/filesystem.hpp"
#include"FileNameRetrieval.h"
#include"FolderStructure.h"

FileNameRetrieval::FileNameRetrieval() { }

vector<string> FileNameRetrieval::fileNameContainer() const { return fileNames; }
vector<string> FileNameRetrieval::passwordNameContainer() const { return passwordNames; }
void FileNameRetrieval::retrieveFileNames() 
{ 
	boost::filesystem::path directory(FolderStructure::keyDirectory);
	boost::filesystem::directory_iterator beg(directory), end;

	for (; beg!=end; ++beg)
		if (beg->path().extension()==".txt")
			fileNames.push_back(beg->path().filename().string());
}
void FileNameRetrieval::retrievePasswordNames()
{
	boost::filesystem::path directory(FolderStructure::passwordDirectory);
	boost::filesystem::directory_iterator beg(directory), end;

	for (; beg!=end; ++beg)
		if (beg->path().extension()==".txt")
		{
			std::string passwordFilename = beg->path().filename().string();
			passwordNames.push_back(passwordFilename);
		}
}
