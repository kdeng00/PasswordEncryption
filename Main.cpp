#include <QApplication>

#include "MessagingControls.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	MessagingControls* stuff = new MessagingControls;;

	stuff->show();

	return app.exec();
}
