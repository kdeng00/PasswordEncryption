#ifndef VIEWINGWINDOW_H_
#define VIEWINGWINDOW_H_

#include<QVBoxLayout>
#include<QTableWidget>
#include<QStringList>
#include<QLineEdit>
#include<QPushButton>
#include<memory>

using std::unique_ptr;

class ViewingWindow
{
public:
	ViewingWindow() = default;
	~ViewingWindow() = default;
protected:
	unique_ptr<QVBoxLayout> subLayoutGoonOne;
	unique_ptr<QVBoxLayout> subLayoutGoonTwo;
	unique_ptr<QLineEdit> crypticText;
	unique_ptr<QTableWidget> elementView;
	unique_ptr<QPushButton> closeButton;
	unique_ptr<QPushButton> generateNewKeys;
	QStringList tableHeader;
	int rowCount, columnCount;
};
#endif
