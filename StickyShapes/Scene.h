#ifndef SCENE_H
#define SCENE_H

#include "Object.h"
#include "Shape.h"

#include <QGraphicsScene>
#include <QList>

class Scene : public QGraphicsScene
{
	Q_OBJECT

public:
	Scene(QObject *parent);
	~Scene();

	Object* AddObject(Object* obj);
	Object* AddObject(Shape* obj);

	bool DeleteObject(Object* obj);

private:
	QList<Object *> objects;
};

#endif // SCENE_H
