#include "DeathBoundary.hpp"
#include "DeathCollider.hpp"

DeathBoundary::DeathBoundary(Vector2f size, Vector2f position) : GameObject(NULL, false, true, "DeathBoundary")
{

	Shape* shape = new RectangleShape(size);
	shape->setPosition(position);
	setShape(shape);

	components.push_back(new DeathCollider(shape));

}
