#ifndef MESSAGINGCONTROLS_H
#define MESSAGINGCONTROLS_H

#include<QDialog>
#include<QPushButton>
#include<QLineEdit>
#include<QTextEdit>
#include<QLabel>
#include<QMenuBar>
#include<QMainWindow>
#include<QMenu>
#include<QAction>
#include<QVBoxLayout>
#include<QDockWidget>
#include<QWidget>
#include<QString>
#include<memory>
#include"KeyManagementWindow.h"

class QLabel;
class QLineEdit;
class QTextEdit;
class QPushButton;
class QMenuBar;
class QMainWindow;
class QMenu;
class QAction;
class QString;

using std::unique_ptr;

class MessagingControls : public QMainWindow
{
	Q_OBJECT
public:
	MessagingControls();
	~MessagingControls() = default;
signals:

private slots:
	void changeCryptionType();
	void determineCryption();
	void keyManagementWindow();
private:	
	void setupMainWindow();
	void createMenus();

	unique_ptr<QVBoxLayout> buttonLayout;

	unique_ptr<QWidget> buttonWidget;

	unique_ptr<QDockWidget> buttonDockWidget;
	unique_ptr<QDockWidget> cryptionArea;

	unique_ptr<QLabel> lblOfEncryptedBox;
	unique_ptr<QLineEdit> encryptedBox;

	unique_ptr<QTextEdit> textForCryption;
	unique_ptr<QTextEdit> textToDecrypt;

	unique_ptr<QPushButton> cryptionButon;
	unique_ptr<QPushButton> cryptionSwitch;

	unique_ptr<QMenu> fileMenu;
	unique_ptr<QMenu> editMenu;
	unique_ptr<QAction> closeApplication;
	unique_ptr<QAction> keyEdit;	

	unique_ptr<KeyManagementWindow> kh;

	std::string grabCryptionText();

	int mainWindowHeight{450};
	int mainWindowWidth{550};

	bool cryptionChoice{true};
};
#endif
