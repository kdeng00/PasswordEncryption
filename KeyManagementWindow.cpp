#include"KeyManagementWindow.h"
#include"Encryption.h"
#include"GenerateKeys.h"
#include"KeyRetrieval.h"

#include<QtWidgets>
#include<QString>
#include<QWidget>
#include<string>
#include<sstream>
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<ios>

KeyManagementWindow::KeyManagementWindow(QWidget* parent) : QDialog(parent)
{
	comboBoxOfKeys = unique_ptr<QComboBox>{new QComboBox{}};
	valueOfKey = unique_ptr<QLineEdit>{new QLineEdit{}};
	generateNewDefaultKeys = unique_ptr<QPushButton>{new QPushButton(tr("Generate New Default Key"))};

	vBox = unique_ptr<QVBoxLayout>{new QVBoxLayout};
	hBox = unique_ptr<QHBoxLayout>{new QHBoxLayout};
	hBox2 = unique_ptr<QHBoxLayout>{new QHBoxLayout};

	setContentsOfComboBox();
	hBox.get()->addWidget(comboBoxOfKeys.get());
	hBox.get()->addWidget(valueOfKey.get());

	hBox2.get()->addWidget(generateNewDefaultKeys.get());

	vBox.get()->addLayout(hBox.get());
	vBox.get()->addLayout(hBox2.get());

	setLayout(vBox.get());

	setFixedWidth(windowWidth);
	setFixedHeight(windowHeight);

	setWindowTitle("Key Management Window");

	QObject::connect(comboBoxOfKeys.get(), SIGNAL(currentIndexChanged(int)), SLOT(test()));
	QObject::connect(generateNewDefaultKeys.get(), SIGNAL(clicked()), this, SLOT(generation()));
}


void KeyManagementWindow::setContentsOfComboBox()
{
	KeyRetrieval kr{};
	std::vector<int> c{kr.codeCharacterStructure()};

	for (auto index = 0u; index!=c.size(); ++index)
	{
		std::string ch{static_cast<char>(c[index])};
		QString bl = QString::fromStdString(ch);
		comboBoxOfKeys.get()->addItem(bl);
	}
}
void KeyManagementWindow::test()
{
	std::string emp{"d"};
	Encryption ec{emp};	
	std::map<char, std::string> encrypted{ec.encryptedCharactersStructure()};
	QString bo{comboBoxOfKeys.get()->currentText()};
	std::string k{bo.toStdString()};
	char f{};

	std::stringstream lazy{}; 
	lazy << k;
	lazy >> f;

	std::string value{encrypted[f]};	
	QString v{QString::fromStdString(value)};
	valueOfKey.get()->setText(v);
}
void KeyManagementWindow::generation()
{
	GenerateKeys gk{};
	gk.keyMove();
	gk.keyDump();
}
