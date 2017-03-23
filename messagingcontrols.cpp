#include <QtGui>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "messagingcontrols.h"

messagingcontrols::messagingcontrols(QWidget* parent) : QDialog(parent) 
{
	QVBoxLayout* everything = new QVBoxLayout;

	lblOfEncryptedBox = new QLabel(tr("Message: "));

	encryptedBox = new QLineEdit;

	encryptionButon = new QPushButton;

	//Adding lbl and line edit
	QHBoxLayout* lblAndLineEdit = new QHBoxLayout;
	lblAndLineEdit->addWidget(lblOfEncryptedBox);
	lblAndLineEdit->addWidget(encryptedBox);

	//Adding button
	QHBoxLayout* button = new QHBoxLayout;
	button->addWidget(encryptionButon);

	//Add everything
	everything->addLayout(lblAndLineEdit);
	everything->addLayout(button);

	setLayout(everything);
	setWindowTitle("Encryption Messaging");
	setFixedHeight(300);
	setFixedWidth(400);
	/**
	 * Initialize controls
	 */
}
messagingcontrols::~messagingcontrols()
{
	 /**
	 * Delete pointer types
	 */
	delete lblOfEncryptedBox;
	delete encryptionButon;
	delete encryptedBox;

}
