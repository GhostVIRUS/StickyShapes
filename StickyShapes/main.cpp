#include "SSMainWindow.h"

//#include <QtWidgets/QApplication>
#include <QtGui>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SSMainWindow w;
	w.show();
	return a.exec();
}
