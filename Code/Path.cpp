#include "Path.hpp"
#include <math.h>
#include <iostream>

Path::Path(Shape * self, Vector2f start, Vector2f dest, float velocity) : Component("Path")
{
	setStartLocation(start);
	setDestination(dest);
	setShape(self);

	Vector2f distance = dest - start;
	float dist = pow(distance.x,2) + pow(distance.y,2);
	dist = sqrt(dist);
	dist = dist / velocity;
	steps = (int)dist;
	current_step = 1;
	direction = true;

	setVelocity(distance / dist);

}

void Path::update(int time)
{
	
	for (int i = 0; i < time; i++) {
		if (direction) {
			getSelf()->move(final_velocity);
			current_step++;
			if (current_step == steps) {
				direction = !direction;
				setVelocity(-final_velocity);
			}
		}
		else {
			getSelf()->move(final_velocity);
			current_step--;
			if (current_step == 1) {
				direction = !direction;
				setVelocity(-final_velocity);
			}
		}
	}
}

void Path::setStartLocation(Vector2f start)
{
	start_location = start;
}

Vector2f Path::getStartLocation()
{
	return start_location;
}

void Path::setDestination(Vector2f dest)
{
	destination = dest;
}

Vector2f Path::getDestination()
{
	return destination;
}

void Path::setVelocity(Vector2f velocity)
{
	final_velocity = velocity;
}

Vector2f Path::getVelocity()
{
	return final_velocity;
}

void Path::setShape(Shape* newSelf) 
{
	self = newSelf;
}

Shape* Path::getSelf() 
{
	return self;
}
