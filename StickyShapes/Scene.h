#ifndef SCENE_H
#define SCENE_H

#include "Object.h"
#include "Shape.h"

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QHBoxLayout>
#include <QLinkedList>

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
	void timerEvent(QTimerEvent *);

private:
	QGraphicsScene *field;
	QGraphicsView *view;

	QHBoxLayout *layout;

	QLinkedList<Object *> objects; //objects with 0 parents 
};

#endif // SCENE_H
