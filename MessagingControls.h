#ifndef MESSAGINGCONTROLS_H
#define MESSAGINGCONTROLS_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <QMenuBar>
#include <QMainWindow>

class QLabel;
class QLineEdit;
class QTextEdit;
class QPushButton;
class QMenuBar;
class QMainWindow;

class MessagingControls : public QDialog
{
	Q_OBJECT
public:
	MessagingControls(QWidget* parent = 0);
	~MessagingControls();

signals:


private slots:

private:	
	QLineEdit* encryptedBox;
	QLabel* lblOfEncryptedBox;
	QTextEdit* textToEncrypt;
	QPushButton* encryptionButon;
	QMenuBar* menuStuff;
	QMainWindow* mainWindow;
};

#endif
