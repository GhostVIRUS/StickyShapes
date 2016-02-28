#include "Shape.h"

#include <QPainter>

Shape::Shape()
	: rotation(qrand() % 180), color(qrand() % 256, qrand() % 256, qrand() % 256)
{
	pos = QPoint(qrand() % 300, qrand() % 300);
	setRotation(rotation);
	setPos(pos);

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
	painter->setBrush(color);
	painter->drawRect(awesomeSquare);
}

void Shape::advance(int step)
{

}
