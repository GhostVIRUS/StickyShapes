#include "Object.h"

#include <QGraphicsScene>

Object::Object(Shape *shape)
	: vx(qrand() % 3 - 1), vy(qrand() % 3 - 1)
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
			setVelocity(qAbs(getVelocityX()), getVelocityY());
		}
		else if (right >= scene()->width())
		{
			moveBy(scene()->width() - right, 0);
			setVelocity(-qAbs(getVelocityX()), getVelocityY());
		}
		if (top <= 0)
		{
			moveBy(0, -top);
			setVelocity(getVelocityX(), qAbs(getVelocityY()));
		}
		else if (bottom >= scene()->height())
		{
			moveBy(0, scene()->height()-bottom);
			setVelocity(getVelocityX(), -qAbs(getVelocityY()));
		}

		auto lObjects = collidingItems(Qt::IntersectsItemBoundingRect);
		moveBy(-vx, -vy);

		for each (auto pItem in lObjects)
		{
			for each (auto pShape in pItem->childItems())
			{
				addToGroup(pShape);
			}
		}
	}
	else
	{
		moveBy(vx, vy);
		if (childItems().empty())
		{
			scene()->removeItem(this);
			delete this;
		}
	}
}

void Object::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
	painter->setBrush(Qt::CrossPattern);
	painter->drawRect(boundingRect());

	/*QPen pen;
	pen.setWidth(10);
	pen.setColor(Qt::blue);

	painter->setPen(pen);
	painter->drawPoint(boundingRect().x(), boundingRect().y());*/
}


QPainterPath Object::shape() const
{
	QPainterPath path;
	for each (auto pItem in childItems())
	{
		path = path + (pItem->mapToParent(pItem->shape()));
	}
	return path;
}

QList<QGraphicsItem *> Object::collidingItems(Qt::ItemSelectionMode mode /*= Qt::IntersectsItemShape*/)
{
	QList<QGraphicsItem *> objects;
	for each (auto pItem in scene()->items()/*QGraphicsItem::collidingItems(mode)*/)
	{
		if (!pItem->childItems().empty())
			if (collidesWithItem(pItem) && pItem != this)
				objects.push_back(pItem);
	}
	return objects;
}