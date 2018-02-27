#include<iostream>
#include<string>
#include<QString>
#include<QTableWidgetItem>
#include"Encryption.h"
#include"Decryption.h"
#include"Demo.h"
#include"FileNameRetrieval.h"
#include"Key.h"
#include"PasswordManagementWindow.h"

PasswordManagementWindow::PasswordManagementWindow(QWidget* parent) : QDialog(parent)
{
	setupWindow();
	populatePass();
}

void PasswordManagementWindow::setupWindow()
{
	windowWidth=450;
	windowHeight=450;

	elementView=unique_ptr<QTableWidget>{new QTableWidget};
	elementView.get()->setRowCount(30);
	elementView.get()->setColumnCount(2);
	tableHeader<<"password"<<"date";
	elementView.get()->setHorizontalHeaderLabels(tableHeader);

	selectionBox=unique_ptr<QComboBox>{new QComboBox};
	actionButton=unique_ptr<QPushButton>{new QPushButton{"i3"}};
	closeButton=unique_ptr<QPushButton>{new QPushButton{"close"}};
	crypticText=unique_ptr<QLineEdit>{new QLineEdit};
	crypticText.get()->insert(QString{"test"});
	crypticText.get()->setReadOnly(true);

	setupLayouts();
	setupContentOfComboBox();

	setFixedWidth(windowWidth);
	setFixedHeight(windowHeight);
	
	connections();
}
void PasswordManagementWindow::setupLayouts()
{
	mainLayout=unique_ptr<QHBoxLayout>{new QHBoxLayout};
	subLayoutOne=unique_ptr<QVBoxLayout>{new QVBoxLayout};
	subLayoutTwo=unique_ptr<QVBoxLayout>{new QVBoxLayout};

	subLayoutGoonOne=unique_ptr<QVBoxLayout>{new QVBoxLayout};
	subLayoutGoonTwo=unique_ptr<QVBoxLayout>{new QVBoxLayout};

	subLayoutGoonOne.get()->addWidget(selectionBox.get());
	subLayoutGoonOne.get()->addWidget(actionButton.get());
	subLayoutGoonTwo.get()->addWidget(crypticText.get());
	subLayoutGoonTwo.get()->addWidget(closeButton.get());

	subLayoutOne.get()->addWidget(elementView.get());
	subLayoutTwo.get()->addLayout(subLayoutGoonOne.get());
	subLayoutTwo.get()->addLayout(subLayoutGoonTwo.get());

	mainLayout.get()->addLayout(subLayoutOne.get());
	mainLayout.get()->addLayout(subLayoutTwo.get());

	setLayout(mainLayout.get());
}
void PasswordManagementWindow::setupContentOfComboBox()
{
	selectionBox.get()->clear();
	FileNameRetrieval fnr;
	fnr.retrieveFileNames();
	std::vector<std::string> fn{fnr.fileNameContainer()};

	for (auto fle: fn)
	{
		QString bl{QString::fromStdString(fle)};
		selectionBox.get()->addItem(bl);
	}
}
void PasswordManagementWindow::connections()
{
	QObject::connect(closeButton.get(), SIGNAL(clicked()), this, SLOT(exitApplication()));
	QObject::connect(actionButton.get(), SIGNAL(clicked()), this, SLOT(testTableView()));
}

void PasswordManagementWindow::populatePass()
{
	z = unique_ptr<vector<QTableWidgetItem*>>{new vector<QTableWidgetItem*>{}};
	Demo<> dm{};

	auto passwordList = dm.retrievePasswordFilenames();
	auto passwordListAmount = passwordList.size();
	auto grassStuff = dm.retrieveGrass();

	auto itPasswordList = passwordList.begin();

	for (auto index = 0; index!=passwordListAmount; ++index)
	{
		for (auto innerIndex = 0; innerIndex!=2; ++innerIndex)
		{
			if (innerIndex==0)
			{
				auto name = *itPasswordList++;
				QTableWidgetItem* it = new QTableWidgetItem{passwordList.at(index).c_str()};
				it->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);	
				z.get()->push_back(it);
			}
			else
			{
				auto year = grassStuff.at(index)[0];
				auto month = grassStuff.at(index)[1];
				auto day = grassStuff.at(index)[2];

				auto g1 = std::to_string(year);
				g1.append("-" + std::to_string(month));
				g1.append("-" + std::to_string(day));
				QTableWidgetItem* it = new QTableWidgetItem{g1.c_str()};
				it->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
				z.get()->push_back(it);
			}
		}
	}
	constexpr auto column = 2;
	auto y = z.get()->begin();
	for (auto index = 0; index!=passwordListAmount; ++index)
	{
		for (auto innerIndex = 0; innerIndex!=column; ++innerIndex)
		{
			elementView.get()->setItem(index, innerIndex, *y++);	
		}
	}
}

void PasswordManagementWindow::exitApplication() { this->hide(); }
void PasswordManagementWindow::testTableView()
{
	auto currentRow = elementView.get()->currentRow();
	crypticText.get()->clear();

	Demo<> dm{};

	auto names = dm.retrievePasswordFilenames();
	auto selectedFile = names.at(currentRow);
	auto selectedKey = selectionBox.get()->currentText();
	auto selectedKeyString = selectedKey.toStdString();
	

	Password<> ps{selectedFile};
	Key<> ky{selectedKeyString};

	Decryption dc{ps, ky};

	auto decrypted = dc.getDecryptedMessage();
	QString de = QString{decrypted.c_str()};

	crypticText.get()->setText(de);
}
