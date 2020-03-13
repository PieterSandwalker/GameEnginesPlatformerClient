#pragma once
#include "Component.hpp"
#include "Character.hpp"

class Scroller :
	public Component
{

private:
	Vector2f scroll;
	Shape* self;
	int shifts;

public:
	Scroller(Shape *, Vector2f);
	void update(int, vector<GameObject*>*);
	void collision(GameObject*, Vector2f*);
	void setSelf(Shape*);
	Shape* getSelf();
	void setScroll(Vector2f);
	Vector2f getScroll();

};

