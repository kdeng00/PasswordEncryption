#ifndef KEYMANAGEMENTWINDOW_H
#define KEYMANAGEMENTWINDOW_H

#include<QDialog>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QComboBox>
#include<QLineEdit>

class QHBoxLayout;
class QVBoxLayout;
class QComboBox;
class QLineEdit;
class QPushButton;

class KeyManagementWindow : public QDialog
{
	Q_OBJECT
public:
	KeyManagementWindow(QWidget* parent = 0);
	~KeyManagementWindow();

	void setContentsOfComboBox();
private slots:	
	void test();
	void generation();
private:	
	QHBoxLayout* hBox{};
	QVBoxLayout* vBox{};
	QComboBox* comboBoxOfKeys{};
	QLineEdit* valueOfKey{};
	QPushButton* generateNewDefaultKeys;
};

#endif
