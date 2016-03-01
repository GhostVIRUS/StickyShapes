#ifndef SHAPE_H
#define SHAPE_H

#include "Object.h"

#include <QGraphicsItem>
#include <QPoint>
#include <QTransform>
#include <QBrush>

//this class implements the simplest shapes
class Shape : public QGraphicsItem
{

public:
	Shape(QPointF pos, QGraphicsItem *parent = 0);
	~Shape();

	QRectF boundingRect() const;
	virtual QPainterPath shape() const; //It's awesomeSqare only for now
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);

private:
	QColor color;
	QBrush brush;
	QPainterPath shapePath;
	QRectF boundingRectangle;
};

#endif // SHAPE_H
