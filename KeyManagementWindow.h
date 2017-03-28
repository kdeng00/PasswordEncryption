#ifndef KEYMANAGEMENTWINDOW_H
#define KEYMANAGEMENTWINDOW_H

#include <QDialog>
#include <QComboBox>
#include <QLineEdit>

class QComboBox;
class QLineEdit;

class KeyManagementWindow : public QDialog
{
	Q_OBJECT
public:
	KeyManagementWindow(QWidget* parent = 0);

	void setContentsOfComboBox();
private slots:	
	void test();
private:	
	QComboBox* comboBoxOfKeys;
	QLineEdit* valueOfKey;
};

#endif
