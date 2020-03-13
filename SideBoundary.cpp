#include "SideBoundary.hpp"
#include "Scroller.hpp"

SideBoundary::SideBoundary(Vector2f size, Vector2f position, Vector2f scroll) : GameObject(NULL, false, true, "SideBoundary")
{
	Shape* shape = new RectangleShape(size);
	shape->setPosition(position);
	setShape(shape);

	components.push_back(new Scroller(shape, scroll));

}

