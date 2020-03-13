#include "SpawnPoint.hpp"
#include "CheckpointCollider.hpp"

SpawnPoint::SpawnPoint(Vector2f size, Vector2f position) : GameObject(NULL, false, true, "SpawnPoint")
{

	Shape* shape = new RectangleShape(size);
	shape->setPosition(position);
	setShape(shape);

	components.push_back(new CheckpointCollider(shape));

}
