#include"KeyManagementWindow.h"
#include"GenerateKeys.h"

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
	GenerateKeys gk{};

	comboBoxOfKeys = new QComboBox{};
	valueOfKey = new QLineEdit{};
	generateNewDefaultKeys = new QPushButton(tr("Generate New Default Key"));

	vBox = new QVBoxLayout;
	hBox = new QHBoxLayout;
	QHBoxLayout* hBox2 = new QHBoxLayout;

	setContentsOfComboBox();
	hBox->addWidget(comboBoxOfKeys);
	hBox->addWidget(valueOfKey);

	hBox2->addWidget(generateNewDefaultKeys);

	vBox->addLayout(hBox);
	vBox->addLayout(hBox2);

	setLayout(vBox);

	setFixedWidth(400);
	setFixedHeight(400);

	setWindowTitle("Key Management Window");

	QObject::connect(comboBoxOfKeys, SIGNAL(currentIndexChanged(int)), SLOT(test()));
	QObject::connect(generateNewDefaultKeys, SIGNAL(clicked()), this, SLOT(generation()));
}
KeyManagementWindow::~KeyManagementWindow()
{ 
	delete comboBoxOfKeys;
	delete valueOfKey;
	delete generateNewDefaultKeys;
	delete hBox;
	delete vBox;
}


void KeyManagementWindow::setContentsOfComboBox()
{
	GenerateKeys gk;

	for (auto index = 0u; index!=gk.allCharacters.size(); ++index)
	{
		std::string ch{static_cast<char>(gk.allCharacters[index])};
		QString bl = QString::fromStdString(ch);
		comboBoxOfKeys->addItem(bl);
	}
}
void KeyManagementWindow::test()
{
	GenerateKeys gk{};
	QString bo{comboBoxOfKeys->currentText()};
	std::string k{bo.toStdString()};
	char f{};

	std::stringstream lazy{}; 
	lazy << k;
	lazy >> f;

	std::string value{gk.encryptedCharacters[f]};	
	QString v{QString::fromStdString(value)};
	valueOfKey->setText(v);
}
void KeyManagementWindow::generation()
{
	GenerateKeys gk{};
	gk.keyMove();
	gk.keyDump();
}
