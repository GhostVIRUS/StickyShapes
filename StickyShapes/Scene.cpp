#include "Scene.h"

#include <QGLWidget>

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

	startTimer(33);
}

Scene::~Scene()
{
	delete view;
	delete field;
}

void Scene::addObject()
{
	Object *obj = new Object(new Shape(QPointF(qrand() % (width() - 54), qrand() % (height() - 54))));
	addObject(obj);
}

void Scene::addObject(Object* obj)
{
	field->addItem(obj);
	objects.push_back(obj);
}

bool Scene::deleteObject(Object* obj)
{
	if (!obj)
		return false;
	field->removeItem(obj);

	return true;
}


void Scene::timerEvent(QTimerEvent *)
{
	for (auto iObject = objects.begin(); iObject != objects.end(); ++iObject)
	{
		(*iObject)->advance(0);
		for (auto jObject = iObject+1; jObject != objects.end(); ++jObject)
		{
			if ((*iObject)->collidesWithItem((*jObject)))
			{
				//(*iObject)->moveBy(-(*iObject)->getVelocityX(), -(*iObject)->getVelocityX());
				(*iObject)->advance(1);
				for each (auto pShape in (*iObject)->childItems())
				{
					(*jObject)->addToGroup(pShape);
				}
				(*jObject)->setVelocity((*jObject)->getVX() + (*iObject)->getVX(), (*jObject)->getVY() + (*iObject)->getVY());
				field->removeItem((*iObject));
				delete (*iObject);
				iObject = objects.erase(iObject);
				--iObject;
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
}