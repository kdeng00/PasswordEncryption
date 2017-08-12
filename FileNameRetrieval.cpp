#include<iostream>
#include"boost/filesystem.hpp"
#include"FileNameRetrieval.h"
#include"FolderStructure.h"

FileNameRetrieval::FileNameRetrieval() { }

std::vector<std::string> FileNameRetrieval::fileNameContainer() const { return fileNames; }
void FileNameRetrieval::retrieveFileNames() 
{ 
	boost::filesystem::path directory(FolderStructure::keyDirectory);
	boost::filesystem::directory_iterator beg(directory), end;

	for (; beg!=end; ++beg)
		if (beg->path().extension()==".txt")
			fileNames.push_back(beg->path().filename().string());
	for (auto fl: fileNames)
		std::cout<< fl<<std::endl;
}
