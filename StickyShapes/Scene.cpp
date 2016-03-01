#include "Scene.h"

Scene::Scene(QWidget *parent)
	: QWidget(parent), field(new QGraphicsScene(0, 0, 300, 300)), view(new QGraphicsView(field, this)),
	layout(new QHBoxLayout(this))
{
	layout->setSpacing(0);
	layout->setContentsMargins(0, 0, 0, 0);
	layout->addWidget(view);

	field->setItemIndexMethod(QGraphicsScene::NoIndex);

	view->setScene(field);
	view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
	view->setAlignment(Qt::AlignTop | Qt::AlignLeft);

	timer = new QTimer;
	QObject::connect(timer, SIGNAL(timeout()), field, SLOT(advance()));
	timer->start(10);

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
}

bool Scene::deleteObject(Object* obj)
{
	if (!obj)
		return false;
	field->removeItem(obj);

	return true;
}

void Scene::timeStep()
{
	
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
