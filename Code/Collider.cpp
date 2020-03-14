#include "Collider.hpp"

Collider::Collider(Shape* self) : Component("Collider")
{
	setShape(self);
}

GameEvent Collider::update(GameObject* character, Vector2f* velocity)
{

	float x = velocity->x;
	float y = velocity->y;

	Vector2f newMove(x, y);

	sf::FloatRect charBox = character->getShape()->getGlobalBounds();
	sf::FloatRect objBox = self->getGlobalBounds();

	charBox.left += x;

	// Horizontal check
	if (charBox.intersects(objBox))
	{
		newMove.x = 0.f;
	}

	charBox.left -= x;

	// Vertical check
	charBox.top += y;

	if (charBox.intersects(objBox))
	{
		newMove.y = 0.f;
	}

	charBox.top -= y;

	return GameEvent{Collision, 0, 0, newMove};

}

void Collider::setShape(Shape* newSelf)
{
	self = newSelf;
}

Shape* Collider::getSelf()
{
	return self;
}
