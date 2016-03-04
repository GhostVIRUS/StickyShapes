#include "Scene.h"
#include "Shape.h"

#include <QGLWidget>
#include <QMouseEvent>

Scene::Scene(QWidget *parent)
	: QWidget(parent), field(new QGraphicsScene(0, 0, 300, 300)), view(new QGraphicsView(field, this)),
	layout(new QHBoxLayout(this))
{
	layout->setSpacing(0);
	layout->setContentsMargins(0, 0, 0, 0);
	layout->addWidget(view);

	field->setItemIndexMethod(QGraphicsScene::NoIndex);

	view->setScene(field);
	view->setViewport(new QGLWidget(QGLFormat(QGL::SampleBuffers | QGL::DirectRendering)));
	view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate/*QGraphicsView::SmartViewportUpdate*/);
	view->setAlignment(Qt::AlignTop | Qt::AlignLeft);
	view->setRenderHints(QPainter::Antialiasing);

	startTimer(33);
}

Scene::~Scene()
{
	delete view;
	delete field; //Qt deletes Objects automatically during this
	delete layout;
}

void Scene::addToScene()
{
	Group *group = new Group(new Shape(QPointF(qrand() % (width() - 54), qrand() % (height() - 54))));
	addToScene(group);
}

void Scene::addToScene(Group* group)
{
	field->addItem(group);
	groups.push_back(group);
}

void Scene::timerEvent(QTimerEvent *)
{
	for (auto iGroup = groups.begin(); iGroup != groups.end(); ++iGroup)
	{
		(*iGroup)->advance(0);
		for (auto jGroup = iGroup+1; jGroup != groups.end(); ++jGroup)
		{
			if ((*iGroup)->collidesWithItem((*jGroup)))
			{
				(*iGroup)->advance(1);
				for each (auto pShape in (*iGroup)->childItems())
				{
					(*jGroup)->addToGroup(pShape);
				}
				(*jGroup)->setVelocity((*jGroup)->getVX() + (*iGroup)->getVX(), (*jGroup)->getVY() + (*iGroup)->getVY());
				field->removeItem((*iGroup));
				delete (*iGroup);
				iGroup = groups.erase(iGroup);
				--iGroup;
				break;
			}
		}
	}
}


void Scene::resizeEvent(QResizeEvent *event)
{
	QWidget::resizeEvent(event);
	field->setSceneRect(0, 0, width() - 3, height() - 3);
	view->resize(width(), height());
}

void Scene::clearScene()
{
	field->clear();
	groups.clear();
}

void Scene::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		Group *group = new Group(new Shape(event->pos()));
		addToScene(group);
	}
}
