#include "Component.hpp"

Component::Component(string type) {
	setType(type);
}

bool Component::isType(string checkType)
{
	if (type == checkType) {
		return true;
	}
	
	return false;
}

void Component::setType(string newType) {
	type = newType;
}

string Component::getType()
{
	return type;
}

void Component::update() {}

