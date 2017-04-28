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

class QLabel;
class QLineEdit;
class QTextEdit;
class QPushButton;
class QMenuBar;
class QMainWindow;
class QMenu;
class QAction;
class QString;

class MessagingControls : public QMainWindow
{
	Q_OBJECT
public:
	MessagingControls();
	~MessagingControls();

signals:


private slots:
	void changeCryptionType();
	void determineCryption();
	void keyManagementWindow();

private:	
	void setupMainWindow();
	void createMenus();
	QVBoxLayout* buttonLayout;

	QWidget* buttonWidget;

	QDockWidget* buttonDockWidget;
	QDockWidget* cryptionArea;

	QLabel* lblOfEncryptedBox;
	QLineEdit* encryptedBox;

	QTextEdit* textForCryption;
	QTextEdit* textToDecrypt;

	QPushButton* cryptionButon;
	QPushButton* cryptionSwitch;

	QMenu* fileMenu;
	QMenu* editMenu;
	QAction* closeApplication;
	QAction* keyEdit;	


	std::string grabCryptionText();

	int mainWindowHeight{450};
	int mainWindowWidth{550};

	bool cryptionChoice{};
};

#endif
