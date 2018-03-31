#include<QString>
#include"SaveFile.h"

string SaveFile::filenameStr = "default.txt";

SaveFile::SaveFile(QWidget* parent) : QDialog(parent) { setupWindow();	}	
SaveFile::SaveFile(QWidget* parent, MainWindow* mw) : QDialog(parent), mw(mw) { setupWindow(); }
	

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
	QString fs = filename.get()->text();
	filenameStr.assign(fs.toUtf8().constData());
	filenameStr.append(".txt");

	mw.get()->processEncryption();

	this->hide();
}
