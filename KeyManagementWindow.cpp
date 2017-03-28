#include "KeyManagementWindow.h"
#include "GenerateKeys.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>
#include <string>
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

	for (unsigned short keyIndex = gk.startingCharacter; keyIndex <= gk.endingCharacter; keyIndex++)
	{
		std::string ch = "";
		ch += gk.decryptedCharacters[keyIndex];
		QString bl = QString::fromStdString(ch); 
		comboBoxOfKeys->addItem(bl);
	}
}
void KeyManagementWindow::test()
{
	GenerateKeys gk;
	//std::cout << "bang bang!" << std::endl;
	QString bo = comboBoxOfKeys->currentText();
	std::string k = bo.toStdString();
	char f;

	std::fstream in;
	in.open("strToCh.txt", std::ios::out);

	in << k;
	in.close();

	in.open("strToCh.txt", std::ios::in);

	in >> f;
	in.close();

	in.open("strToCh.txt", std::ios::out);
	in << gk.encryptedCharacters[f];
	in.close();

	unsigned short yek;
	in.open("strToCh.txt", std::ios::in);
	in >> yek;
	in.close();

	std::string key = "";
	key += std::to_string(yek);
	//std::cout << gk.encryptedCharacters[f] << std::endl;
	QString v = QString::fromStdString(key);
	valueOfKey->setText(v);
}
