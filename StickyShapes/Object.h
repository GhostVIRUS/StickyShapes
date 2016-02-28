#ifndef OBJECT_H
#define OBJECT_H

#include "Shape.h"

#include <QGraphicsItem>
#include <QList>

class Shape;

class Object : public QGraphicsItemGroup
{
public:
	Object();
	Object(Object *obj);
	Object(Shape *shape);
	~Object();

	void uniteWith(Object *who);
	void addShape(Shape* shape); //there is QGraphicItemGroup::addToGroup()

	inline void setVelocity(qreal x, qreal y) { vx = x; vy = y; };
	inline qreal getVelocityX() { return vx; };
	inline qreal getVelocityY() { return vy; };

	void advance();
private:
	qreal vx, vy; //velocity
};

#endif // OBJECT_H
