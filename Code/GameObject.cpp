#include "GameObject.hpp"

GameObject::GameObject(Shape* shape, bool render, bool collidable, string type) : rendered(render), collidable(collidable)
{
	setShape(shape);
	setType(type);
}

void GameObject::setShape(Shape* newShape)
{
	shape = newShape;
}

Shape* GameObject::getShape()
{
	return shape;
}

void GameObject::setType(string newType) {
	type = newType;
}

string GameObject::getType()
{
	return type;
}

void GameObject::toggleRender() 
{
	rendered = !rendered;
}

bool GameObject::isRendered() 
{
	return rendered;
}

int GameObject::hasComponent(string type)
{
	if (components.empty()) {
		return -1;
	}

	for (int i = 0; i < components.size(); i++) {
		if (components[i]->isType(type)) {
			return i;
		}
	}

	return -1;
}

Component* GameObject::getComponent(int location)
{
	return components[location];
}