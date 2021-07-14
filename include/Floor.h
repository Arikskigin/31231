#pragma once
#include"StaticObject.h"
#include "Object.h"
#include <iostream>
#include "Factory.h"
class Floor : public StaticObject
{
public:
	Floor(const sf::Vector2f& location);
	virtual ~Floor() = default;


protected:
	static bool m_registerit;
};

inline bool Floor::m_registerit = Factory::registerit("floor",
	[](const sf::Vector2f& location) -> std::unique_ptr<StaticObject> { return std::make_unique<Floor>(location); });
