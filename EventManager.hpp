#pragma once
#include <SFML/Graphics.hpp>
#include <queue>
#include <list>
#include "Component.hpp"
#include <zmq.hpp>
#include "GameObject.hpp"
#include <variant>

using namespace std;
using namespace sf;

enum EventType {
	Death,
	Spawn,
	Input,
	Collision
};

struct GameEvent {
	GameEvent(EventType newType, int newID, int newTime, Vector2f newData) : type(newType), objID(newID), time(newTime), data(newData) {}

	EventType type;
	int objID;
	int time;
	Vector2f data;
};

class Compare {
public:
	bool operator() (GameEvent a , GameEvent b)
	{
		return a.time > b.time;
	}
};

