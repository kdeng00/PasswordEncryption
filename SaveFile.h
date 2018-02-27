#ifndef SAVEFILE_H_
#define SAVEFILE_H_

#include"CommonWindow.h"
#include"ViewingWindow.h"

class SaveFile : public QDialog, public CommonWindow, public ViewingWindow
{
	Q_OBJECT
public:		
	SaveFile(QWidget* parent = 0);
private:
	void setupWindow();
	void connections();

	unique_ptr<QLineEdit> filename;
	unique_ptr<QPushButton> saveIt;
private slots:		
	void saveFileAs();
};

#endif
