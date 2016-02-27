#ifndef SHAPE_H
#define SHAPE_H

#include <QGraphicsItem>

class Shape : public QGraphicsItem
{
	//Q_OBJECT

public:
	//Shape(QObject *parent = 0);
	Shape();
	~Shape();

	QRectF boundingRect() const;
	QPainterPath shape() const; //Prolly requires interface classes for different forms, duuh.
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);

protected:
	void advance(int step);

private:
	qreal velocity;
	qreal angle;

	const QRectF awesomeSquare = QRectF(0, 0, 50, 50); //for the first launch and for lulz
};

#endif // SHAPE_H
