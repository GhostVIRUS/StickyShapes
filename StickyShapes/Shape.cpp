#include "Shape.h"

#include <QPainter>

Shape::Shape(QPointF pos, int shapeIndex /*= 1*/, QGraphicsItem *parent /*= 0*/)
	:QGraphicsItem(parent), color(qrand() % 256, qrand() % 256, qrand() % 256)
{
	setRotation(qrand()%90);
	setPos(pos);

	//brush.setColor(color);
	int shapeRand = qrand() % 6;
	int w = 10 + qrand() % 20; //w = w / 2;
	int h = 10 + qrand() % 20; //h = h / 2;
	QPolygon polygon;
	switch (shapeRand)
	{
	case 0:
		shapePath.addRect(0, 0, w, h);
		break;
	case 1:
		shapePath.addEllipse(0, 0, w, h);
		break;
	case 2:
		shapePath.addRoundRect(0, 0, w, h, qrand() % 10);
		break;
	case 3:
		w = w * 2;
		polygon << QPoint(0, 0)
			<< QPoint(w, w / 5)
			<< QPoint(w * 4 / 5, w)
			<< QPoint(w / 6, w * 5 / 4)
			<< QPoint(w * 3 / 4, w * 3 / 4)
			<< QPoint(w * 3 / 4, w / 4);
		shapePath.addPolygon(polygon);
		break;
	case 4:
		w = w / 2;
		polygon << QPoint(2 * w, 0)
			<< QPoint(w, -w * 173 / 100)
			<< QPoint(-w, -w * 173 / 100)
			<< QPoint(-2 * w, 0)
			<< QPoint(-w, w * 173 / 100)
			<< QPoint(w, w * 173 / 100);
		shapePath.addPolygon(polygon);
		break;
	case 5:
		polygon << QPoint(0, 0)
			<< QPoint(w / 2, 0)
			<< QPoint(w, w / 2)
			<< QPoint(w, w)
			<< QPoint(w, w * 3 / 2)
			<< QPoint(w / 2, w * 2)
			<< QPoint(0, w * 2)
			<< QPoint(-w / 2, w * 2)
			<< QPoint(w / 4, w * 3 / 2)
			<< QPoint(0, w)
			<< QPoint(-w / 4, w / 2)
			<< QPoint(-w / 2, 0);
		shapePath.moveTo(polygon[0]);
		for (int i = 1; i < polygon.size(); i += 3)
			shapePath.cubicTo(polygon[i], polygon[(i + 1) % polygon.size()], polygon[(i + 2) % polygon.size()]);
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
	//painter->setPen(Qt::NoPen);
	painter->setBrush(color);
	painter->drawPath(shapePath);
}

