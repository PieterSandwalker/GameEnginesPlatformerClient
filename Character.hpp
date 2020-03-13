#pragma once
#include "GameObject.hpp"

class Character :
	public GameObject
{

private:
	Texture texture;
	Vector2f checkpoint;

public:
	Character(Vector2f, Vector2f, string);
	void setCheckpoint(Vector2f);
	Vector2f getCheckpoint();

};

