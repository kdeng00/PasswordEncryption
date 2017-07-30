#ifndef PASSWORDMANAGEMENTWINDOW_H_
#define PASSWORDMANAGEMENTWINDOW_H_

#include<QDialog>
#include"CommonWindow.h"
#include"ViewingWindow.h"

class PasswordManagementWindow : public QDialog, public CommonWindow, public ViewingWindow
{
	Q_OBJECT
public:
	PasswordManagementWindow(QWidget* parent=0);
	~PasswordManagementWindow()=default;

private:
	void setupWindow();
	void connections();

	unique_ptr<QLineEdit> passwordField;
private slots:
	void exitApplication();
};
#endif
