#ifndef SAVEFILE_H_
#define SAVEFILE_H_

#include<iostream>
#include<string>
#include"CommonWindow.h"
#include"MainWindow.h"
#include"ViewingWindow.h"

class MainWindow;

using namespace std;

class SaveFile : public QDialog, public CommonWindow, public ViewingWindow
{
	Q_OBJECT
public:		
	SaveFile(QWidget* parent = 0);
	explicit SaveFile(QWidget* parent = 0, MainWindow* mw = 0);
	static string filenameStr;
private:
	void setupWindow();
	void connections();

	unique_ptr<QLineEdit> filename;
	unique_ptr<QPushButton> saveIt;
	unique_ptr<MainWindow> mw;

private slots:		
	void saveFileAs();
};

#endif
