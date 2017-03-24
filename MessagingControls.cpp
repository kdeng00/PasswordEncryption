#include <QtGui>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDockWidget>

#include "MessagingControls.h"

MessagingControls::MessagingControls(QWidget* parent) : QDialog(parent) 
{
	/**
	 * Initialize controls
	 */
	QVBoxLayout* everything = new QVBoxLayout;

	//menuStuff = new QMenuBar;
	mainWindow = new QMainWindow;

	lblOfEncryptedBox = new QLabel(tr("Message: "));

	textToEncrypt = new QTextEdit;
	//encryptedBox = new QLineEdit;

	encryptionButon = new QPushButton;

	//Adding lbl and line edit
	QHBoxLayout* lblAndLineEdit = new QHBoxLayout;
	lblAndLineEdit->addWidget(lblOfEncryptedBox);
	lblAndLineEdit->addWidget(textToEncrypt);

	//Adding button
	QHBoxLayout* button = new QHBoxLayout;
	button->addWidget(encryptionButon);

	//Add everything
	//everything->addLayout(menuStuff);
	everything->addLayout(lblAndLineEdit);
	everything->addLayout(button);

	QDockWidget* lblAndArea = new QDockWidget(tr("Dock Widget"));
	lblAndArea->setWidget(textToEncrypt);

	mainWindow->addDockWidget(Qt::LeftDockWidgetArea, lblAndArea);
	//mainWindow->addDockWidget(lblAndArea);
	//mainWindow->addDockWidget(textToEncrypt);
	//mainWindow->addDockWidget(encryptionButon);

	//setLayout(mainWindow);
	setWindowTitle("Encryption Messaging");
	setFixedHeight(300);
	setFixedWidth(400);
}
MessagingControls::~MessagingControls()
{
	 /**
	 * Delete pointer types
	 */
	delete lblOfEncryptedBox;
	delete encryptionButon;
	delete textToEncrypt;
	//delete encryptedBox;

}
