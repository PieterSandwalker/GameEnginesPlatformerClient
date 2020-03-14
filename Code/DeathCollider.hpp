#pragma once
#include "Collider.hpp"

class DeathCollider :
	public Collider
{

public:
	DeathCollider(Shape*);
	GameEvent update(GameObject*, Vector2f*);

};

