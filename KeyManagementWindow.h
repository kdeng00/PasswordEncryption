#ifndef KEYMANAGEMENTWINDOW_H
#define KEYMANAGEMENTWINDOW_H

#include<QDialog>
#include<QString>
#include<memory>
#include"CommonWindow.h"
#include"ViewingWindow.h"

class KeyManagementWindow : public QDialog, public CommonWindow, public ViewingWindow
{
	Q_OBJECT
public:
	KeyManagementWindow(QWidget* parent = 0);
	~KeyManagementWindow() = default;
private slots:	
	//void test();
	void generation();
	void exitApplication();
	void setContentOfKeyView();
private:	
	void setContentsOfComboBox();
	void setupWindow();
	void connections();
	unique_ptr<QString> qSB;
};
#endif
