#include<QString>
#include<QIcon>
#include"MessagingControls.h"
#include"Encryption.h"
#include"Decryption.h"
#include"KeyRetrieval.h"

MessagingControls::MessagingControls()
{
	mainWindowWidth = 450;
	mainWindowHeight = 450;
	setupMainWindow();
}


void MessagingControls::setupMainWindow()
{
	kh = unique_ptr<KeyManagementWindow>{new KeyManagementWindow};
	textForCryption = unique_ptr<QTextEdit>{new QTextEdit{}};
	cryptionButon = unique_ptr<QPushButton>{new QPushButton(tr("XO"))};
	cryptionSwitch = unique_ptr<QPushButton>{new QPushButton(tr("encrypt chosen"))};

	buttonLayout = unique_ptr<QVBoxLayout>{new QVBoxLayout};
	buttonWidget = unique_ptr<QWidget>{new QWidget};
	buttonDockWidget = unique_ptr<QDockWidget>{new QDockWidget};
	buttonDockWidget.get()->setWindowTitle(tr("Cryption Controls"));
	buttonLayout.get()->addWidget(cryptionButon.get());
	buttonLayout.get()->addWidget(cryptionSwitch.get());
	buttonWidget.get()->setLayout(buttonLayout.get());
	buttonDockWidget.get()->setWidget(buttonWidget.get());
	buttonDockWidget.get()->setFeatures(QDockWidget::NoDockWidgetFeatures);
	setCentralWidget(buttonDockWidget.get());

	cryptionArea = unique_ptr<QDockWidget>{new QDockWidget(tr("Cryption"))};
	cryptionArea.get()->setWidget(textForCryption.get());
	cryptionArea.get()->setFeatures(QDockWidget::NoDockWidgetFeatures);
	addDockWidget(Qt::LeftDockWidgetArea, cryptionArea.get());

	addDockWidget(Qt::LeftDockWidgetArea, cryptionArea.get());

	createMenus();

	QObject::connect(closeApplication.get(), SIGNAL(triggered()), this, SLOT(exitApplication()));
	QObject::connect(cryptionSwitch.get(), SIGNAL(clicked()), this, SLOT(changeCryptionType()));
	QObject::connect(cryptionButon.get(), SIGNAL(clicked()), this, SLOT(determineCryption()));
	QObject::connect(keyEdit.get(), SIGNAL(triggered()), this, SLOT(keyManagementWindow()));

	setWindowTitle("Encryption Decryption Messaging");
	setFixedHeight(mainWindowHeight);
	setFixedWidth(mainWindowWidth);
}
void MessagingControls::createMenus()
{
	fileMenu = unique_ptr<QMenu>{menuBar()->addMenu(tr("File"))};
	editMenu = unique_ptr<QMenu>{menuBar()->addMenu(tr("Edit"))};

	closeApplication = unique_ptr<QAction>{new QAction(new QObject(nullptr))};
	closeApplication.get()->setText("Exit Application");

	keyEdit = unique_ptr<QAction>{new QAction(new QObject(nullptr))};
	keyEdit.get()->setText("Key Management");

	fileMenu.get()->addAction(closeApplication.get());
	editMenu.get()->addAction(keyEdit.get());
}


void MessagingControls::changeCryptionType()
{
	(cryptionChoice) ? cryptionSwitch->setText("decrypt chosen") : cryptionSwitch->setText("encrypt chosen");
	cryptionChoice = (cryptionChoice) ? false : true;
}
void MessagingControls::determineCryption()
{
	if (cryptionChoice)
	{
		Encryption ec{grabCryptionText()};

		textForCryption.get()->clear();
		textForCryption.get()->setText(QString::fromStdString(ec.getEncryptedMessage()));

		cryptionSwitch.get()->setText("decrypt chosen");
		cryptionChoice = false;
	}
	else
	{
		Decryption dc{grabCryptionText()};

		textForCryption.get()->clear();
		textForCryption.get()->setText(QString::fromStdString(dc.getDecryptedMessage()));

		cryptionSwitch.get()->setText("encrypt chosen");
		cryptionChoice = true;
	}
}
void MessagingControls::keyManagementWindow() { kh.get()->show(); }
void MessagingControls::exitApplication() { exit(0); }


std::string MessagingControls::grabCryptionText()
{
	auto placeHolder = textForCryption.get()->toPlainText();
	
	return placeHolder.toStdString();
}	
