#include "SSMainWindow.h"
#include "Scene.h"
#include "Object.h"
#include "Shape.h"

//#include <QtWidgets/QApplication>
#include <QtGui>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	Scene theBestScene(&a);
	for (int i = 0; i < 3; ++i)
	{
		theBestScene.AddObject(new Shape);
	}
	SSMainWindow w;
	w.setScene(&theBestScene);
	w.show();
	return a.exec();
}
