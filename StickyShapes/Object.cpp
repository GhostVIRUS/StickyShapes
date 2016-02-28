#include "Object.h"


Object::Object()
	: vx(0), vy(0)
{

}

Object::Object(Object *obj)
	: vx(obj->vx), vy(obj->vy)
{
	addToGroup(obj); //probably it is better to use the following implementation
	/*for each (auto pShape in childItems())
	{
		addToGroup(pShape);
	}*/
}

Object::Object(Shape *shape)
	: vx(0), vy(0)
{
	addToGroup(shape);
}


Object::~Object()
{
	
}

void Object::uniteWith(Object *who)
{

}

void Object::addShape(Shape* shape)
{
	addToGroup(shape);
}


void Object::advance()
{
	this->moveBy(vx, vy);
}
