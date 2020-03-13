#pragma once
#include "GameObject.hpp"

class StaticPlatform :
	public GameObject
{

private:
	Texture texture;

public:
	explicit StaticPlatform(Vector2f, Vector2f, string);

};

