#include "SSMainWindow.h"
#include "Scene.h"
#include "Object.h"
#include "Shape.h"

#include <QtWidgets/QApplication>
#include <QTimer>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SSMainWindow w;
	//QTimer timer;
	//QObject::connect(&timer, SIGNAL(timeout()), &theBestScene, SLOT(advance()));
	//timer.start(500);
	w.show();
	return a.exec();
}
