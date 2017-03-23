#include <iostream>
#include <QApplication>

#include "messagingcontrols.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	messagingcontrols* stuff = new messagingcontrols;;

	stuff->show();

	return app.exec();
}
