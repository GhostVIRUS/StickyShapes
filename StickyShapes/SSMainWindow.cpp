#include "SSMainWindow.h"
#include "Shape.h"

SSMainWindow::SSMainWindow(QWidget *parent)
	: QMainWindow(parent), scene(new Scene(this))
{
	ui.setupUi(this);

	scene->setView(ui.graphicsView);
}

SSMainWindow::~SSMainWindow()
{

}

void SSMainWindow::slotClearScene()
{
	
}

void SSMainWindow::slotAddShape()
{
	scene->addObject(new Shape());
}
