#ifndef OBJECT_H
#define OBJECT_H

#include "Shape.h"

#include <QGraphicsItem>
#include <QPainter>

class Shape;

class Object : public QGraphicsItemGroup
{
public:
	Object(Shape *shape);
	~Object();

	//void uniteWith(Object *obj);

	inline void setVelocity(qreal x, qreal y) { vx = x; vy = y; };
	inline qreal getVelocityX() { return vx; };
	inline qreal getVelocityY() { return vy; };

	QPainterPath shape() const;
	QList<QGraphicsItem *> collidingItems(Qt::ItemSelectionMode mode = Qt::IntersectsItemShape);

	void advance(int phase);
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
private:
	qreal vx, vy; //velocity
};

#endif // OBJECT_H
