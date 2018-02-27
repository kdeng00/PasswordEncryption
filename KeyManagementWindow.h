#ifndef KEYMANAGEMENTWINDOW_H
#define KEYMANAGEMENTWINDOW_H

#include<QString>
#include"CommonWindow.h"
#include"Encryption.h"
#include"MainWindow.h"
#include"PasswordManagementWindow.h"
#include"ViewingWindow.h"

class MainWindow;

class KeyManagementWindow : public QDialog, public CommonWindow, public ViewingWindow
{
	Q_OBJECT
public:
	KeyManagementWindow(QWidget* parent = 0);
	explicit KeyManagementWindow(QWidget* parent = 0, MainWindow* mw = 0, PasswordManagementWindow* pw = 0);
	~KeyManagementWindow() = default;
private slots:	
	void generation();
	void exitApplication();
	void setContentOfKeyView();
private:	
	void setContentsOfComboBox();
	void setupWindow();
	void connections();
	unique_ptr<QString> qSB;
	unique_ptr<MainWindow> mw;
	unique_ptr<PasswordManagementWindow> pw;
};
#endif
