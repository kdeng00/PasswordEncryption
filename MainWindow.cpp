#include<QString>
#include"MainWindow.h"
#include"Encryption.h"
#include"Decryption.h"
#include"KeyRetrieval.h"

MainWindow::MainWindow()
{
	windowHeight = 450;
	windowWidth = 450;
	setupMainWindow();
}


void MainWindow::setupMainWindow()
{
	kh = unique_ptr<KeyManagementWindow>{new KeyManagementWindow};
	textForCryption = unique_ptr<QTextEdit>{new QTextEdit{}};
	actionButton = unique_ptr<QPushButton>{new QPushButton(tr("encrypt"))};
	selectionBox = unique_ptr<QComboBox>{new QComboBox{}};

	buttonLayout = unique_ptr<QVBoxLayout>{new QVBoxLayout};
	buttonWidget = unique_ptr<QWidget>{new QWidget};
	buttonDockWidget = unique_ptr<QDockWidget>{new QDockWidget};
	buttonDockWidget.get()->setWindowTitle(tr("Cryption Controls"));
	buttonLayout.get()->addWidget(selectionBox.get());
	buttonLayout.get()->addWidget(actionButton.get());
	buttonWidget.get()->setLayout(buttonLayout.get());
	buttonDockWidget.get()->setWidget(buttonWidget.get());
	buttonDockWidget.get()->setFeatures(QDockWidget::NoDockWidgetFeatures);
	setCentralWidget(buttonDockWidget.get());

	cryptionArea = unique_ptr<QDockWidget>{new QDockWidget(tr("Cryption"))};
	cryptionArea.get()->setWidget(textForCryption.get());
	cryptionArea.get()->setFeatures(QDockWidget::NoDockWidgetFeatures);
	addDockWidget(Qt::LeftDockWidgetArea, cryptionArea.get());

	createMenus();

	QObject::connect(closeApplication.get(), SIGNAL(triggered()), this, SLOT(exitApplication()));
	QObject::connect(keyEdit.get(), SIGNAL(triggered()), this, SLOT(keyManagementWindow()));

	setWindowTitle("Encryption Decryption Messaging");
	setFixedHeight(windowHeight);
	setFixedWidth(windowWidth);
}
void MainWindow::createMenus()
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


void MainWindow::changeCryptionType()
{
	(cryptionChoice) ? cryptionSwitch->setText("decrypt chosen") : cryptionSwitch->setText("encrypt chosen");
	cryptionChoice = (cryptionChoice) ? false : true;
}
void MainWindow::determineCryption()
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
void MainWindow::keyManagementWindow() { kh.get()->show(); }
void MainWindow::exitApplication() { exit(0); }


std::string MainWindow::grabCryptionText()
{
	auto placeHolder = textForCryption.get()->toPlainText();
	
	return placeHolder.toStdString();
}	
