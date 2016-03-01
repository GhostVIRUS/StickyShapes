#include "Shape.h"

#include <QPainter>

Shape::Shape(QPointF pos, QGraphicsItem *parent /*= 0*/)
	:QGraphicsItem(parent), color(qrand() % 256, qrand() % 256, qrand() % 256)
{
	setRotation(qrand()%90); //When Shape will be set this will prolly not be needed anymore
	setPos(pos);

	brush.setColor(color);
	int shapeRand = qrand() % 3;
	switch (shapeRand)
	{
	case 0:
		shapePath.addRect(0, 0, 10 + qrand() % 50, 10 + qrand() % 50);
		break;
	case 1:
		shapePath.addEllipse(0, 0, 10 + qrand() % 50, 10 + qrand() % 50);
		break;
	case 2:
		shapePath.addRoundRect(0, 0, 10 + qrand() % 50, 10 + qrand() % 50, qrand() % 10);
		break;

	}
}

Shape::~Shape()
{

}

QRectF Shape::boundingRect() const
{
	return shapePath.boundingRect();
}


QPainterPath Shape::shape() const
{
	return shapePath;
}

void Shape::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
	//painter->setPen(Qt::transparent);
	painter->setBrush(color);
	painter->drawPath(shapePath);

	/*QPen pen;
	pen.setWidth(5);
	pen.setColor(Qt::green);

	painter->setPen(pen);
	painter->drawPoint(0,0);*/
}

