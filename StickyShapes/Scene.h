#ifndef SCENE_H
#define SCENE_H

#include "Object.h"
#include "Shape.h"

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QList>

class Scene : public QWidget
{
	Q_OBJECT

public:
	Scene(QWidget *parent);
	~Scene();

	Object* addObject(Object* obj);
	Object* addObject(Shape* shape);
	bool deleteObject(Object* obj);

	bool setView(QGraphicsView *v);

public slots: //so public tho?
	void timeStep();

private:
	QGraphicsScene *scene;
	QGraphicsView *view;

	//QList<Object *> objects;

};

#endif // SCENE_H
