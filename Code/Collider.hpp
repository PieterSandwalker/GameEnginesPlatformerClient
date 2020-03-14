#pragma once
#include "Component.hpp"
#include "GameObject.hpp"
#include "EventManager.hpp"

class Collider :
	public Component
{

private:
	Shape* self;

public:
	Collider(Shape*);
	virtual GameEvent update(GameObject*, Vector2f*);
	void setShape(Shape*);
	Shape* getSelf();

};

