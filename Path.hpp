#pragma once
#include "Component.hpp"

using namespace sf;

class Path :
	public Component
{

private:
	Shape* self;
	Vector2f start_location;
	Vector2f destination;
	Vector2f final_velocity;
	int steps;
	int current_step;
	bool direction;

public:
	Path(Shape*, Vector2f, Vector2f, float);
	void update(int);
	void setStartLocation(Vector2f);
	Vector2f getStartLocation();
	void setDestination(Vector2f);
	Vector2f getDestination();
	void setVelocity(Vector2f);
	Vector2f getVelocity();
	void setShape(Shape*);
	Shape* getSelf();


};

