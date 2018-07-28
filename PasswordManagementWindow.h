#ifndef PASSWORDMANAGEMENTWINDOW_H_
#define PASSWORDMANAGEMENTWINDOW_H_

#include<vector>
#include"CommonWindow.h"
#include"ViewingWindow.h"

#include"SaveFile.h"

using std::vector;

class PasswordManagementWindow : public QDialog, public CommonWindow, public ViewingWindow
{
	Q_OBJECT
public:
	PasswordManagementWindow(QWidget* parent=0);
	~PasswordManagementWindow()=default;

	void setupContentOfComboBox();
	void populatePass();
	void updateElementView();
private:
	void setupWindow();
	void setupLayouts();
	void connections();
	void determineAmountOfPasswords();

	unique_ptr<QLineEdit> passwordField;
	unique_ptr<vector<QTableWidgetItem*>> z;
	int amountOfPasswords;
private slots:
	void exitApplication();
	void testTableView();
};
#endif
