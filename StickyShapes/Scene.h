#ifndef SCENE_H
#define SCENE_H

#include "Object.h"
#include "Shape.h"

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QHBoxLayout>
#include <QTimer>
#include <QList>

class Scene : public QWidget
{
	Q_OBJECT

public:
	Scene(QWidget *parent);
	~Scene();

	void addObject();
	void addObject(Object* obj);
	bool deleteObject(Object* obj);
	void clearScene();

	//inline QList<Object *> &getObjects() { return objects; };

private:
	void resizeEvent(QResizeEvent *event);


public slots: //so public tho?
	void timeStep();

private:
	QGraphicsScene *field;
	QGraphicsView *view;

	QHBoxLayout *layout;

	QTimer *timer;
};

#endif // SCENE_H
