#ifndef SSMAINWINDOW_H
#define SSMAINWINDOW_H

#include "ui_SSMainWindow.h"

#include <QMainWindow>

class SSMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	SSMainWindow(QWidget *parent = 0);
	~SSMainWindow();

private slots:
	void slotClearScene(); //this slot is now used for all kind of tests, but clearing scene
	void slotAddShape();

private:
	Ui::SSMainWindowClass ui;
};

#endif // SSMAINWINDOW_H
