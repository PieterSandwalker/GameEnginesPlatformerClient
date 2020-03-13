#include "Character.hpp"
#include "CharacterMovement.hpp"
#include <iostream>

Character::Character(Vector2f size, Vector2f position, string texturePath) : GameObject(NULL, true, true, "Character")
{

	Shape* shape = new RectangleShape(size);
	shape->setPosition(position);
	setCheckpoint(position);
	setShape(shape);

	if (!texture.loadFromFile(texturePath))
	{
		std::cout << "Texture not found\n";
		shape->setFillColor(sf::Color(100, 200, 200));  //To be replaced by texture
	} else {
		shape->setTexture(&texture);
	}

	components.push_back(new CharacterMovement(shape));

}

void Character::setCheckpoint(Vector2f newCheckpoint)
{
	checkpoint = newCheckpoint;
}

Vector2f Character::getCheckpoint()
{
	return checkpoint;
}
