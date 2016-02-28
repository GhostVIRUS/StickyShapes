#ifndef OBJECT_H
#define OBJECT_H

#include <QGraphicsItem>
#include <QList>
#include <Shape.h>

//should it inherit QGraphicsItem?
class Object
{
public:
	Object();
	Object(Object *obj);
	Object(Shape *shape);
	~Object();

	void uniteWith(Object *who);
	void AddShape(Shape* shape);

	const QList<Shape *> &getShapes() const;

private:
	qreal velocity;
	qreal angle;

	QList<Shape *> shapes;
};

#endif // OBJECT_H
