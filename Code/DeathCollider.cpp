#include "DeathCollider.hpp"
#include "Character.hpp"

DeathCollider::DeathCollider(Shape* self) : Collider(self)
{

}

GameEvent DeathCollider::update(GameObject* character, Vector2f* velocity)
{

	bool collision = false;

	float x = velocity->x;
	float y = velocity->y;

	Vector2f newMove(x, y);

	sf::FloatRect charBox = character->getShape()->getGlobalBounds();
	sf::FloatRect objBox = getSelf()->getGlobalBounds();

	charBox.left += x;

	// Horizontal check
	if (charBox.intersects(objBox))
	{
		newMove.x = 0.f;
		collision = true;
	}

	charBox.left -= x;

	// Vertical check
	charBox.top += y;

	if (charBox.intersects(objBox))
	{
		newMove.y = 0.f;
		collision = true;
	}

	charBox.top -= y;

	if (collision) {
		return GameEvent{ Death, 0, 0, newMove};
	}
	else {
		return GameEvent{ Collision, 0, 0, newMove };
	}

}
