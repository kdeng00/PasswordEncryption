#ifndef KEYMANAGEMENTWINDOW_H
#define KEYMANAGEMENTWINDOW_H

#include<QDialog>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QComboBox>
#include<QLineEdit>
#include<QPushButton>
#include<memory>

class QHBoxLayout;
class QVBoxLayout;
class QComboBox;
class QLineEdit;
class QPushButton;

using std::unique_ptr;

class KeyManagementWindow : public QDialog
{
	Q_OBJECT
public:
	KeyManagementWindow(QWidget* parent = 0);
	~KeyManagementWindow() = default;

	void setContentsOfComboBox();
private slots:	
	void test();
	void generation();
private:	
	unique_ptr<QHBoxLayout> hBox;
	unique_ptr<QHBoxLayout> hBox2;
	unique_ptr<QVBoxLayout> vBox;
	unique_ptr<QComboBox> comboBoxOfKeys;
	unique_ptr<QLineEdit> valueOfKey;
	unique_ptr<QPushButton> generateNewDefaultKeys;
	int windowWidth{400};
	int windowHeight{400};
};

#endif
