#ifndef SHAPE_H
#define SHAPE_H

#include <QGraphicsItem>
#include <QPoint>

//this class implements the simplest shapes
class Shape : public QGraphicsItem
{
	//Q_OBJECT

public:
	//Shape(QObject *parent = 0);
	Shape();
	~Shape();

	QRectF boundingRect() const;
	QPainterPath shape() const; //It's awesomeSqare only for now
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);

protected:
	void advance(int step);

private:
	qreal rotation;
	QColor color;
	QPoint pos; 

	const QRectF awesomeSquare = QRectF(0, 0, 50, 50); //for the first launch and for lulz
};

#endif // SHAPE_H
