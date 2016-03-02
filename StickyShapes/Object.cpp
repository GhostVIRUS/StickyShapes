#include "Object.h"

#include <QGraphicsScene>

Object::Object(QGraphicsItem *shape)
	: vx(qrand() % 5 - 2), vy(qrand() % 5 - 2)
{
	addToGroup(shape);
}


Object::~Object()
{
	//Qt has to delete children automatically
}


void Object::advance(int phase)
{
	if (phase == 0)
	{
		moveBy(vx, vy);

		int top = mapRectToScene(boundingRect()).top();
		int bottom = mapRectToScene(boundingRect()).bottom();
		int left = mapRectToScene(boundingRect()).left();
		int right = mapRectToScene(boundingRect()).right();

		if (left <= 0)
		{
			moveBy(-left, 0);
			setVelocity(qAbs(getVX()), getVY());
		}
		else if (right >= scene()->width())
		{
			moveBy(scene()->width() - right, 0);
			setVelocity(-qAbs(getVX()), getVY());
		}
		if (top <= 0)
		{
			moveBy(0, -top);
			setVelocity(getVX(), qAbs(getVY()));
		}
		else if (bottom >= scene()->height())
		{
			moveBy(0, scene()->height()-bottom);
			setVelocity(getVX(), -qAbs(getVY()));
		}
	}
	else
	{
		moveBy(-vx, -vy);
	}
}

void Object::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
	//painter->setBrush(Qt::CrossPattern);
	//painter->drawRect(boundingRect());

	/*painter->setBrush(Qt::red);
	painter->drawPath(shape());*/
	/*QPen pen;
	pen.setWidth(10);
	pen.setColor(Qt::blue);

	painter->setPen(pen);
	painter->drawPoint(boundingRect().x(), boundingRect().y());*/
}



QPainterPath Object::shape() const
{
	return shapePath;
}

void Object::addToGroup(QGraphicsItem *shape)
{	
	shapePath = shapePath + mapFromItem(shape, shape->shape());
	QGraphicsItemGroup::addToGroup(shape);
}

QRectF Object::boundingRect() const
{
	return shapePath.boundingRect();
}

