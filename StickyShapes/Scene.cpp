#include "Scene.h"

Scene::Scene(QWidget *parent)
	: QWidget(parent), scene(new QGraphicsScene), view(0)
{
	scene->setSceneRect(0, 0, 300, 300);
	scene->setItemIndexMethod(QGraphicsScene::NoIndex);
}

Scene::~Scene()
{
	
}

Object* Scene::addObject(Object* obj)
{
	scene->addItem(obj);
	
	return obj;
}

Object* Scene::addObject(Shape* shape)
{
	Object *obj = new Object(shape);
	return addObject(obj);
}

bool Scene::deleteObject(Object* obj)
{
	if (!obj)
		return false;
	scene->removeItem(obj);

	return true;
}

void Scene::timeStep()
{
	//TODO: check for collisions and stuff
	scene->advance();
}

bool Scene::setView(QGraphicsView *v)
{
	if (!v)
		return false;
	view = v;
	view->setScene(scene);
	return true;
}
