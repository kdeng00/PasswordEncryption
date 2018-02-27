#include<iostream>
#include<string>
#include<QApplication>
#include"MainWindow.h"
#include"FolderStructure.h"

int main(int argc, char* argv[])
{
	FolderStructure fs;
	fs.setupPaths(*(argv+1));
	QApplication app(argc, argv);
	MainWindow stuff{};

	stuff.show();

	return app.exec();
}
