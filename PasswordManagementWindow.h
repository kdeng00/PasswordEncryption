#ifndef PASSWORDMANAGEMENTWINDOW_H_
#define PASSWORDMANAGEMENTWINDOW_H_

#include<vector>
#include"CommonWindow.h"
#include"ViewingWindow.h"

using std::vector;

class PasswordManagementWindow : public QDialog, public CommonWindow, public ViewingWindow
{
	Q_OBJECT
public:
	PasswordManagementWindow(QWidget* parent=0);
	~PasswordManagementWindow()=default;

	void setupContentOfComboBox();
	void populatePass();
private:
	void setupWindow();
	void setupLayouts();
	void connections();


	unique_ptr<QLineEdit> passwordField;
	unique_ptr<vector<QTableWidgetItem*>> z;
private slots:
	void exitApplication();
	void testTableView();
};
#endif
