#pragma once
#include "Collider.hpp"
#include "Path.hpp"

class PathCollider :
	public Collider
{

private:
	Path * selfPath;

public:
	PathCollider(Shape*, Path*);
	GameEvent update(GameObject*, Vector2f*);
	void setPath(Path*);
	Path* getPath();


};

