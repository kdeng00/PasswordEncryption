#include"SaveFile.h"

SaveFile::SaveFile(QWidget* parent) : QDialog(parent)
{
	setupWindow();	
}	

void SaveFile::setupWindow()
{

		windowWidth=250;
		windowHeight=250;	

		filename = unique_ptr<QLineEdit>{new QLineEdit};
		saveIt = unique_ptr<QPushButton>{new QPushButton};

		subLayoutOne = unique_ptr<QVBoxLayout>{new QVBoxLayout};
		subLayoutTwo = unique_ptr<QVBoxLayout>{new QVBoxLayout};

		subLayoutOne.get()->addWidget(filename.get());
		subLayoutOne.get()->addWidget(saveIt.get());
		subLayoutTwo.get()->addLayout(subLayoutOne.get());

		setLayout(subLayoutTwo.get());

		setFixedWidth(windowWidth);
		setFixedHeight(windowHeight);

		connections();
}
void SaveFile::connections()
{
	QObject::connect(saveIt.get(), SIGNAL(clicked()), this, SLOT(saveFileAs()));
}
void SaveFile::saveFileAs()
{
	this->hide();
}
