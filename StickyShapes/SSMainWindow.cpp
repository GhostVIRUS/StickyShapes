#include "SSMainWindow.h"

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
}

void SSMainWindow::slotAddShape()
{
	for (int i = 0; i < 10; ++i)
		ui.scene->addGroup();
}
