#ifndef SCENE_H
#define SCENE_H

#include "Group.h"

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QHBoxLayout>
#include <QLinkedList>

class Scene : public QWidget
{
	Q_OBJECT

public:
	Scene(QWidget *parent);
	~Scene();

	void addGroup();
	void addGroup(Group* group);
	void clearScene();

private:
	void resizeEvent(QResizeEvent *event);
	void timerEvent(QTimerEvent *);
	void mousePressEvent(QMouseEvent *event);

private:
	QGraphicsScene *field;
	QGraphicsView *view;

	QHBoxLayout *layout;

	QLinkedList<Group *> groups;
};

#endif // SCENE_H
