#ifndef SHAPE_H
#define SHAPE_H

#include <QGraphicsItem>
#include <QPoint>
#include <QBrush>

//this class implements the simplest shapes
class Shape : public QGraphicsItem
{

public:
	//Shape() {  };
	Shape(QPointF pos, QGraphicsItem *parent = 0);
	~Shape();

	QRectF boundingRect() const;
	virtual QPainterPath shape() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);

	QPainterPath getShapePath() { return shapePath; }

private:
	QColor color;
	//QBrush brush;
	QPainterPath shapePath;
	QRectF boundingRectangle;
};

#endif // SHAPE_H
