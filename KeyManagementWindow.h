#ifndef KEYMANAGEMENTWINDOW_H
#define KEYMANAGEMENTWINDOW_H

#include<QDialog>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QComboBox>
#include<QLineEdit>
#include<QPushButton>
#include<memory>
#include"CommonWindow.h"
#include"ViewingWindow.h"

class KeyManagementWindow : public QDialog, public CommonWindow, public ViewingWindow
{
	Q_OBJECT
public:
	KeyManagementWindow(QWidget* parent = 0);
	~KeyManagementWindow() = default;

	void setContentsOfComboBox();
private slots:	
	void test();
	void generation();
	void exitApplication();
private:	
};

#endif
