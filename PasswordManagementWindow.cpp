#include"PasswordManagementWindow.h"

PasswordManagementWindow::PasswordManagementWindow(QWidget* parent) : QDialog(parent)
{
	setupWindow();
}

void PasswordManagementWindow::setupWindow()
{
	windowWidth=450;
	windowHeight=450;

	elementView=unique_ptr<QTableView>{new QTableView};

	selectionBox=unique_ptr<QComboBox>{new QComboBox};
	actionButton=unique_ptr<QPushButton>{new QPushButton{"i3"}};
	crypticText=unique_ptr<QLineEdit>{new QLineEdit};

	mainLayout=unique_ptr<QHBoxLayout>{new QHBoxLayout};
	subLayoutOne=unique_ptr<QVBoxLayout>{new QVBoxLayout};
	subLayoutTwo=unique_ptr<QVBoxLayout>{new QVBoxLayout};

	subLayoutOne.get()->addWidget(elementView.get());
	subLayoutTwo.get()->addWidget(selectionBox.get());
	subLayoutTwo.get()->addWidget(actionButton.get());
	subLayoutTwo.get()->addWidget(crypticText.get());

	mainLayout.get()->addLayout(subLayoutOne.get());
	mainLayout.get()->addLayout(subLayoutTwo.get());

	setLayout(mainLayout.get());

	setFixedWidth(windowWidth);
	setFixedHeight(windowHeight);
	
	connections();
}
void PasswordManagementWindow::connections()
{

}
