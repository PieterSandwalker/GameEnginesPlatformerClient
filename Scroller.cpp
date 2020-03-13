#include "Scroller.hpp"
#include "CharacterMovement.hpp"

Scroller::Scroller(Shape* shape, Vector2f scroll) : Component("Scroller")
{
	setSelf(shape);
	setScroll(scroll);
}

void Scroller::update(int id, vector<GameObject*>* scene)
{
	Vector2f movement = getScroll() * (float)shifts;
	for (int i = 0; i < scene->size(); i++) {
		if (i != id) {
			scene->at(i)->getShape()->move(movement);
		}
	}
}

void Scroller::collision(GameObject* character, Vector2f* velocity)
{
	bool collision = false;

	float x = velocity->x;
	float y = velocity->y;

	sf::FloatRect charBox = character->getShape()->getGlobalBounds();
	sf::FloatRect objBox = getSelf()->getGlobalBounds();

	charBox.left += x;

	// Horizontal check
	if (charBox.intersects(objBox))
	{
		collision = true;
	}

	charBox.left -= x;

	// Vertical check
	charBox.top += y;

	if (charBox.intersects(objBox))
	{
		collision = true;
	}

	charBox.top -= y;

	if (collision) {
		shifts++;
		character->getShape()->move(getScroll());
	}
}

void Scroller::setSelf(Shape* newSelf)
{
	self = newSelf;
}

Shape* Scroller::getSelf()
{
	return self;
}

void Scroller::setScroll(Vector2f newScroll)
{
	scroll = newScroll;
}

Vector2f Scroller::getScroll()
{
	return scroll;
}
