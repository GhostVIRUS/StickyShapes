#ifndef SSMAINWINDOW_H
#define SSMAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_SSMainWindow.h"

class SSMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	SSMainWindow(QWidget *parent = 0);
	~SSMainWindow();

private:
	Ui::SSMainWindowClass ui;

	QGraphicsScene scene; //remove this to separate class
};

#endif // SSMAINWINDOW_H
