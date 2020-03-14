#pragma once
#include "GameObject.hpp"

class MovingPlatform :
	public GameObject
{

private:
	Texture texture;

public:
	explicit MovingPlatform(Vector2f, Vector2f, Vector2f, string);

};

