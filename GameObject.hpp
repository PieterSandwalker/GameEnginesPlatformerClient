#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "Component.hpp"

using namespace sf;
using namespace std;

class GameObject
{

private:	
	Shape* shape;
	bool rendered;
	bool collidable;
	string type;

protected:
	vector<Component*> components;

public:
	GameObject(Shape*, bool, bool, string);
	void setShape(Shape*);
	Shape* getShape();
	void setType(string);
	string getType();
	void toggleRender();
	bool isRendered();
	int hasComponent(string);
	Component* getComponent(int);

};

