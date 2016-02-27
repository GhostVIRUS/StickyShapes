#include "SSMainWindow.h"
#include "Shape.h"

SSMainWindow::SSMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	scene.setSceneRect(-100, -100, 300, 300);
	scene.setItemIndexMethod(QGraphicsScene::NoIndex);

	Shape *TheSquare = new Shape;
	scene.addItem(TheSquare);

	ui.graphicsView->setScene(&scene);
}

SSMainWindow::~SSMainWindow()
{

}
