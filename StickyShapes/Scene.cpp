#include "Scene.h"

Scene::Scene(QObject *parent)
	: QGraphicsScene(parent)
{
	setSceneRect(0, 0, 300, 300);
	setItemIndexMethod(QGraphicsScene::NoIndex);
}

Scene::~Scene()
{
	for each (Object *pObject in objects)
	{
		delete pObject;
	}
}

Object* Scene::AddObject(Object* obj)
{
	objects.push_back(obj);
	for each (auto pShape in obj->getShapes())
	{
		addItem(pShape);
	}
	return obj;
}

Object* Scene::AddObject(Shape* shape)
{
	Object *obj = new Object(shape);
	return AddObject(obj);
}

bool Scene::DeleteObject(Object* obj)
{
	int shift = objects.indexOf(obj);
	if (!shift)
		return false;

	objects.erase(objects.begin() + shift);
	delete obj;

	return true;
}
