#include"PasswordManagementWindow.h"

PasswordManagementWindow::PasswordManagementWindow(QWidget* parent) : QDialog(parent)
{
	setupWindow();
}

void PasswordManagementWindow::setupWindow()
{
	windowWidth=450;
	windowHeight=450;

	elementView=unique_ptr<QTableWidget>{new QTableWidget};

	selectionBox=unique_ptr<QComboBox>{new QComboBox};
	actionButton=unique_ptr<QPushButton>{new QPushButton{"i3"}};
	closeButton=unique_ptr<QPushButton>{new QPushButton{"close"}};
	crypticText=unique_ptr<QLineEdit>{new QLineEdit};

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

	setFixedWidth(windowWidth);
	setFixedHeight(windowHeight);
	
	connections();
}
void PasswordManagementWindow::connections()
{
	QObject::connect(closeButton.get(), SIGNAL(clicked()), this, SLOT(exitApplication()));
}
void PasswordManagementWindow::exitApplication() { this->hide(); }
