#include "Group.h"

#include <QGraphicsScene>

Group::Group(QGraphicsItem *shape)
	: vx(qrand() % 3 - 1), vy(qrand() % 3 - 1)
{
	addToGroup(shape);
}


Group::~Group()
{
	//Qt has to delete its children automatically
}


void Group::advance(int phase)
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

QPainterPath Group::shape() const
{
	return shapePath;
}

void Group::addToGroup(QGraphicsItem *shape)
{	
	shapePath = shapePath + mapFromItem(shape, shape->shape());
	QGraphicsItemGroup::addToGroup(shape);
}

QRectF Group::boundingRect() const
{
	return shapePath.boundingRect();
}

void Group::setVelocity(qreal x, qreal y)
{
	if (x > maxSpeed)
		vx = maxSpeed;
	else if (x < -maxSpeed)
		vx = -maxSpeed;
	else
		vx = x;
	if (y > maxSpeed)
		vy = maxSpeed;
	else if (y < -maxSpeed)
		vy = -maxSpeed;
	else
		vy = y;
}

