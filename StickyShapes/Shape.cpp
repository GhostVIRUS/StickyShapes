#include "Shape.h"

#include <QPainter>

Shape::Shape(QGraphicsItem *parent /*= 0*/)
	: QGraphicsItem(parent), color(qrand() % 256, qrand() % 256, qrand() % 256)
{
	setRotation(0);
	setPos(QPointF(qrand() % 300, qrand() % 300));
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
	/*QPainterPath awesomePath;
	awesomePath.addRect(awesomeSquare);
	return awesomePath;*/
	return QGraphicsItem::shape();
}

void Shape::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
	painter->setBrush(color);
	painter->drawRect(awesomeSquare);
}

