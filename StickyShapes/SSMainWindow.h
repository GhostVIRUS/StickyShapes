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

	bool setScene(Scene *scn);

private:
	Ui::SSMainWindowClass ui;

	Scene *scene;
};

#endif // SSMAINWINDOW_H
