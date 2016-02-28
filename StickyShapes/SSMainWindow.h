#ifndef SSMAINWINDOW_H
#define SSMAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_SSMainWindow.h"
#include "Scene.h"

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

	Scene *scene; //Do I really need a pointer on my Scene in this class?
};

#endif // SSMAINWINDOW_H
