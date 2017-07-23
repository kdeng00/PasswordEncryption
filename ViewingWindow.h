#ifndef VIEWINGWINDOW_H_
#define VIEWINGWINDOW_H_

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
	unique_ptr<QLineEdit> crypticText;
};
#endif
