#ifndef MESSAGINGCONTROLS_H
#define MESSAGINGCONTROLS_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <QMenuBar>
#include <QMainWindow>
#include <QMenu>
#include <QAction>

class QLabel;
class QLineEdit;
class QTextEdit;
class QPushButton;
class QMenuBar;
class QMainWindow;
class QMenu;
class QAction;

class MessagingControls : public QMainWindow
{
	Q_OBJECT
public:
	MessagingControls();
	~MessagingControls();



signals:


private slots:

private:	
	void createMenus();

	QLineEdit* encryptedBox;
	QLabel* lblOfEncryptedBox;
	QTextEdit* textToEncrypt;
	QPushButton* encryptionButon;
	QMenu* fileMenu;
	QMenu* editMenu;
	QAction* closeApplication;
	QAction* keyEdit;	
};

#endif
