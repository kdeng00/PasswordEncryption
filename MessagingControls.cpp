#include <QtGui>
#include <QString>
#include <QIcon>
#include <iostream>

#include "MessagingControls.h"
#include "KeyManagementWindow.h"
#include "Encryption.h"
#include"Decryption.h"

MessagingControls::MessagingControls()
{
	textForCryption = new QTextEdit;
	cryptionChoice = true;

	setupMainWindow();
}
MessagingControls::~MessagingControls()
{
	delete lblOfEncryptedBox;
	delete cryptionButon;
	delete textForCryption;

}


void MessagingControls::setupMainWindow()
{
	cryptionButon = new QPushButton(tr("XO"));
	cryptionSwitch = new QPushButton(tr("encrypt chosen"));

	buttonLayout = new QVBoxLayout;
	buttonWidget = new QWidget;
	buttonDockWidget = new QDockWidget;
	buttonDockWidget->setWindowTitle(tr("Cryption Controls"));
	buttonLayout->addWidget(cryptionButon);
	buttonLayout->addWidget(cryptionSwitch);
	buttonWidget->setLayout(buttonLayout);
	buttonDockWidget->setWidget(buttonWidget);
	buttonDockWidget->setFeatures(QDockWidget::NoDockWidgetFeatures);
	setCentralWidget(buttonDockWidget);

	QDockWidget* cryptionArea = new QDockWidget(tr("Cryption"));
	cryptionArea->setWidget(textForCryption);
	cryptionArea->setFeatures(QDockWidget::NoDockWidgetFeatures);
	addDockWidget(Qt::LeftDockWidgetArea, cryptionArea);

	createMenus();

	QObject::connect(closeApplication, SIGNAL(triggered()), this, SLOT(close()));
	QObject::connect(cryptionSwitch, SIGNAL(clicked()), this, SLOT(changeCryptionType()));
	QObject::connect(cryptionButon, SIGNAL(clicked()), this, SLOT(determineCryption()));
	QObject::connect(keyEdit, SIGNAL(triggered()), this, SLOT(keyManagementWindow()));

	setWindowTitle("Encryption Decryption Messaging");
	setFixedHeight(mainWindowHeight);
	setFixedWidth(mainWindowWidth);
}
void MessagingControls::createMenus()
{
	fileMenu = menuBar()->addMenu(tr("File"));
	editMenu = menuBar()->addMenu(tr("Edit"));

	closeApplication = new QAction(new QObject(nullptr));
	closeApplication->setText("Exit Application");

	keyEdit = new QAction(new QObject(nullptr)); 
	keyEdit->setText("Key Management");

	fileMenu->addAction(closeApplication);

	editMenu->addAction(keyEdit);
}


void MessagingControls::changeCryptionType()
{
	if (cryptionChoice)
	{
		cryptionSwitch->setText("decrypt chosen");
		cryptionChoice = false;
	}
	else
	{
		cryptionSwitch->setText("encrypt chosen");
		cryptionChoice = true;
	}
}
void MessagingControls::determineCryption()
{
	if (cryptionChoice)
	{
		Encryption ec{grabCryptionText()};
		ec.encryptMessage();

		textForCryption->clear();
		textForCryption->setText(QString::fromStdString(ec.getEncryptedMessage()));

		cryptionSwitch->setText("decrypt chosen");
		cryptionChoice = false;
	}
	else
	{
		Decryption dc{grabCryptionText()};
		dc.decryptMessage();

		textForCryption->clear();
		textForCryption->setText(QString::fromStdString(dc.getDecryptedMessage()));

		cryptionSwitch->setText("encrypt chosen");
		cryptionChoice = true;
	}
}
void MessagingControls::keyManagementWindow()
{
	KeyManagementWindow* kh = new KeyManagementWindow;
	kh->show();
}


std::string MessagingControls::grabCryptionText()
{
	QString placeHolder = textForCryption->toPlainText();
	std::string message = placeHolder.toStdString();
	
	return message;
}	
