#include <QtGui>
#include <QString>
#include <iostream>

#include "MessagingControls.h"

MessagingControls::MessagingControls()
{
	/**
	 * Initialize controls
	 */
	cryptionChoice = true;

	setupMainWindow();
}
MessagingControls::~MessagingControls()
{
	 /**
	 * Delete pointer types
	 */
	delete lblOfEncryptedBox;
	delete cryptionButon;
	delete textForCryption;

}


void MessagingControls::setupMainWindow()
{
	textForCryption = new QTextEdit;


	cryptionButon = new QPushButton(tr("XO"));
	cryptionSwitch = new QPushButton(tr("encrypt"));


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

	setWindowTitle("Encryption Decryption Messaging");
	setFixedHeight(mainWindowHeight);
	setFixedWidth(mainWindowWidth);
}
void MessagingControls::createMenus()
{
	fileMenu = menuBar()->addMenu(tr("File"));
	editMenu = menuBar()->addMenu(tr("Edit"));

	closeApplication = new QAction(tr("Quit Application"));
	keyEdit = new QAction(tr("Key Edit"));

	fileMenu->addAction(closeApplication);

	editMenu->addAction(keyEdit);
}


void MessagingControls::changeCryptionType()
{
	if (cryptionChoice)
	{
		cryptionSwitch->setText("decrypt");
		cryptionChoice = false;
	}
	else
	{
		cryptionSwitch->setText("encrypt");
		cryptionChoice = true;
	}
}
void MessagingControls::determineCryption()
{
	if (cryptionChoice)
	{
		/**
		 * Decrypt Message
		 */
	}
	else
	{
		/**
		 * Encrypt Message
		 */
	}
	//std::string s;
	//s = textForCryption->toPlainText().toStdString();
	//std::cout << s << std::endl;
	//QString* str = textForCryption->toPlainText();
	//s = str->toStdString();
	//s = static_cast<std::string>(textForCryption->toPlainText());
	//std::cout << textForCryption->toPlainText() << std::endl;

}
