#include "StaticPlatform.hpp"
#include "Collider.hpp"
#include <iostream>

StaticPlatform::StaticPlatform(Vector2f size, Vector2f position, string texturePath) : texture(), GameObject(NULL, true, true, "StaticPlatform") {

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

	components.push_back(new Collider(shape));

}
