#include "KeyManagementWindow.h"
#include "GenerateKeys.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>
#include <string>
#include<sstream>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ios>

KeyManagementWindow::KeyManagementWindow(QWidget* parent) : QDialog(parent)
{
	GenerateKeys gk;

	comboBoxOfKeys = new QComboBox;
	valueOfKey = new QLineEdit;

	QVBoxLayout* vBox = new QVBoxLayout;
	QHBoxLayout* hBox = new QHBoxLayout;

	setContentsOfComboBox();
	hBox->addWidget(comboBoxOfKeys);
	hBox->addWidget(valueOfKey);

	vBox->addLayout(hBox);

	setLayout(vBox);

	setFixedWidth(400);
	setFixedHeight(400);

	setWindowTitle("Key Management Window");

	QObject::connect(comboBoxOfKeys, SIGNAL(currentIndexChanged(int)), SLOT(test()));
}


void KeyManagementWindow::setContentsOfComboBox()
{
	GenerateKeys gk;

	std::cout << "got here" << std::endl;
	for (auto index = 0; index!=gk.allCharacters.size(); ++index)
	{
		std::string ch{static_cast<char>(gk.allCharacters[index])};
		QString bl = QString::fromStdString(ch);
		comboBoxOfKeys->addItem(bl);
	}
}
void KeyManagementWindow::test()
{
	GenerateKeys gk;
	QString bo = comboBoxOfKeys->currentText();
	std::string k = bo.toStdString();
	char f;

	std::stringstream lazy{}; 
	lazy << k;
	lazy >> f;
	//std::cout << "character: " << f << std::endl;

	std::string value{gk.encryptedCharacters[f]};	
	QString v = QString::fromStdString(value);
	valueOfKey->setText(v);
}
