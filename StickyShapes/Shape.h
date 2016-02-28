#ifndef SHAPE_H
#define SHAPE_H

#include "Object.h"

#include <QGraphicsItem>
#include <QPoint>

//this class implements the simplest shapes
class Shape : public QGraphicsItem
{

public:
	Shape(QGraphicsItem *parent = 0);
	~Shape();

	QRectF boundingRect() const;
	QPainterPath shape() const; //It's awesomeSqare only for now
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);

private:
	QColor color;
	//qreal rotation; //use position methods from base class
	//QPointF position; 

	const QRectF awesomeSquare = QRectF(0, 0, 50, 50); //for the first launch and for lulz
};

#endif // SHAPE_H
