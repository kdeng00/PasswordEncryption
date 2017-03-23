#ifndef MESSAGINGCONTROLS_H
#define MESSAGINGCONTROLS_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

class QLabel;
class QLineEdit;
class QPushButton;

class messagingcontrols : public QDialog
{
	Q_OBJECT
public:
	messagingcontrols(QWidget* parent = 0);
	~messagingcontrols();

	/**
signals:


private slots:

*/
private:	
	QLineEdit* encryptedBox;
	QLabel* lblOfEncryptedBox;
	QPushButton* encryptionButon;
};

#endif
