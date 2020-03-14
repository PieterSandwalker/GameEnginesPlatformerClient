#pragma once
#include "Component.hpp"
#include "GameObject.hpp"
#include "EventManager.hpp"

class CharacterMovement :
	public Component
{

private:
	Shape* self;
	bool jump;

public:
	CharacterMovement(Shape *);
	GameEvent movement(int, bool);
	void update(Vector2f);
	void setSelf(Shape*);
	Shape* getSelf();
	void toggleJump();
	bool getJump();

};

