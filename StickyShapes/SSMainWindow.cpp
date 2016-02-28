#include "SSMainWindow.h"
#include "Shape.h"

SSMainWindow::SSMainWindow(QWidget *parent)
	: QMainWindow(parent), scene(0)
{
	ui.setupUi(this);
}

SSMainWindow::~SSMainWindow()
{

}

bool SSMainWindow::setScene(Scene *scn)
{
	if (!scn)
		return false;
	ui.graphicsView->setScene(scn);
	return true;
}
