#pragma once
#include "Collider.hpp"

class CheckpointCollider :
	public Collider
{

public:
	CheckpointCollider(Shape*);
	GameEvent update(GameObject*, Vector2f*);

};

