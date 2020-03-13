#pragma once
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
using namespace std;

class Component
{

private:
	string type;

public:
	Component(string);
	bool isType(string);
	void setType(string);
	string getType();
	virtual void update();

};

