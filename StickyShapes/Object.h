#ifndef OBJECT_H
#define OBJECT_H

#include <QGraphicsItem>
#include <QPainter>

class Shape;

class Object : public QGraphicsItemGroup
{
public:
	Object(QGraphicsItem *shape);
	~Object();

	inline void setVelocity(qreal x, qreal y) { vx = x; vy = y; };
	inline qreal getVX() { return vx; };
	inline qreal getVY() { return vy; };

	QRectF boundingRect() const;
	QPainterPath shape() const;
	void addToGroup(QGraphicsItem *shape);

	void advance(int phase);
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
private:
	qreal vx, vy; //velocity

	QPainterPath shapePath;
};

#endif // OBJECT_H
