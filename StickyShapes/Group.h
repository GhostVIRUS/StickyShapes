#ifndef GROUP_H
#define GROUP_H

#include <QGraphicsItem>

class Shape;

class Group : public QGraphicsItemGroup
{
public:
	Group(QGraphicsItem *shape);
	~Group();

	inline void setVelocity(qreal x, qreal y);
	inline qreal getVX() { return vx; };
	inline qreal getVY() { return vy; };

	QRectF boundingRect() const;
	QPainterPath shape() const;
	void addToGroup(QGraphicsItem *shape);

	void advance(int phase);
private:
	qreal vx, vy; //velocity

	QPainterPath shapePath;

	const qreal maxSpeed = 3;
};

#endif // GROUP_H
