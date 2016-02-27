#include "Shape.h"

#include <QPainter>

Shape::Shape()
	: velocity(0), angle(0)
{
	
}

Shape::~Shape()
{

}

QRectF Shape::boundingRect() const
{
	return awesomeSquare;
}

QPainterPath Shape::shape() const
{
	QPainterPath awesomePath;
	awesomePath.addRect(awesomeSquare);
	return awesomePath;
}

void Shape::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
	painter->setBrush(Qt::blue);
	painter->drawRect(awesomeSquare);
}

void Shape::advance(int step)
{

}
