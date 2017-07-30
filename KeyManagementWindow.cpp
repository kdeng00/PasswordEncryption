#include<QString>
#include<QWidget>
#include<string>
#include<sstream>
#include<cstdlib>
#include<fstream>
#include<ios>
#include"KeyManagementWindow.h"
#include"Encryption.h"
#include"GenerateKeys.h"
#include"KeyRetrieval.h"
#include"Conversions.h"

KeyManagementWindow::KeyManagementWindow(QWidget* parent) : QDialog(parent)
{
	setupWindow();
	connections();
}


void KeyManagementWindow::setContentsOfComboBox()
{
	KeyRetrieval kr{};
	std::vector<int> c{kr.codeCharacterStructure()};

	for (auto index = 0u; index!=c.size(); ++index)
	{
		std::string ch{static_cast<char>(c[index])};
		QString bl = QString::fromStdString(ch);
		selectionBox.get()->addItem(bl);
	}
}
void KeyManagementWindow::setupWindow()
{
	windowWidth = 450;
	windowHeight = 450;

	elementView = unique_ptr<QTableView>{new QTableView};

	selectionBox = unique_ptr<QComboBox>{new QComboBox{}};

	generateNewKeys = unique_ptr<QPushButton>{new QPushButton(tr("Generate New Default Key"))};
	closeButton = unique_ptr<QPushButton>{new QPushButton(tr("close"))};
	actionButton = unique_ptr<QPushButton>{new QPushButton};

	mainLayout = unique_ptr<QHBoxLayout>{new QHBoxLayout};
	subLayoutOne = unique_ptr<QVBoxLayout>{new QVBoxLayout};
	subLayoutTwo = unique_ptr<QVBoxLayout>{new QVBoxLayout};

	subLayoutGoonOne = unique_ptr<QVBoxLayout>{new QVBoxLayout};
	subLayoutGoonTwo = unique_ptr<QVBoxLayout>{new QVBoxLayout};

	subLayoutOne.get()->addWidget(elementView.get());

	subLayoutGoonOne.get()->addWidget(selectionBox.get());
	subLayoutGoonOne.get()->addWidget(actionButton.get());
	subLayoutGoonTwo.get()->addWidget(generateNewKeys.get());
	subLayoutGoonTwo.get()->addWidget(closeButton.get());

	subLayoutTwo.get()->addLayout(subLayoutGoonOne.get());
	subLayoutTwo.get()->addLayout(subLayoutGoonTwo.get());


	mainLayout.get()->addLayout(subLayoutOne.get());
	mainLayout.get()->addLayout(subLayoutTwo.get());


	setContentsOfComboBox();

	setLayout(mainLayout.get());

	setFixedWidth(windowWidth);
	setFixedHeight(windowHeight);

	setWindowTitle("Key Management Window");
}
void KeyManagementWindow::connections()
{
	QObject::connect(selectionBox.get(), SIGNAL(currentIndexChanged(int)), SLOT(test()));
	QObject::connect(generateNewKeys.get(), SIGNAL(clicked()), this, SLOT(generation()));
	QObject::connect(closeButton.get(), SIGNAL(clicked()), this, SLOT(exitApplication()));
}
void KeyManagementWindow::test()
{
	std::string emp{"d"};
	Encryption ec{emp};	
	std::map<char, std::string> encrypted{ec.encryptedCharactersStructure()};
	QString bo{selectionBox.get()->currentText()};
	std::string k{bo.toStdString()};
	char f{};

	std::stringstream lazy{}; 
	lazy << k;
	lazy >> f;

	std::string value{encrypted[f]};	
	QString v{QString::fromStdString(value)};
	//valueOfKey.get()->setText(v);
}
void KeyManagementWindow::generation()
{
	GenerateKeys gk{};
	gk.keyMove();
	gk.keyDump();
}
void KeyManagementWindow::exitApplication() { this->hide(); }
