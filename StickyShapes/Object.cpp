#include "Object.h"


Object::Object()
	: velocity(0), angle(0)
{

}

Object::Object(Object *obj)
	: velocity(obj->velocity), angle(obj->angle), shapes(obj->shapes)
{
	
}

Object::Object(Shape *shape)
{
	Object();
	shapes.push_back(shape);
}


Object::~Object()
{
	for each (Shape* pShape in shapes)
	{
		delete pShape;
	}
}

void Object::uniteWith(Object *who)
{

}

void Object::AddShape(Shape* shape)
{
	shapes.push_back(shape);
}

const QList<Shape *> &Object::getShapes() const
{
	return shapes;
}
