#include "SSMainWindow.h"
#include "Shape.h"

SSMainWindow::SSMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

SSMainWindow::~SSMainWindow()
{

}

void SSMainWindow::slotClearScene()
{
	ui.scene->clearScene();
	//ui.scene->timeStep();
}

void SSMainWindow::slotAddShape()
{
	ui.scene->addObject();
}
