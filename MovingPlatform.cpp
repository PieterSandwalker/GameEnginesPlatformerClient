#include "MovingPlatform.hpp"
#include "Path.hpp"
#include "PathCollider.hpp"
#include <iostream>

MovingPlatform::MovingPlatform(Vector2f size, Vector2f position, Vector2f destination, string texturePath) : GameObject(NULL, true, true, "MovingPlatform") {

	Shape* shape = new RectangleShape(size);
	shape->setPosition(position);
	setShape(shape);

	if (!texture.loadFromFile(texturePath))
	{
		std::cout << "Texture not found\n";
		shape->setFillColor(sf::Color(100, 200, 200));  //To be replaced by texture
	}
	else {
		shape->setTexture(&texture);
	}

	Path* path = new Path(shape, position, destination, .05f);

	components.push_back(path);
	components.push_back(new PathCollider(shape, path));

}
