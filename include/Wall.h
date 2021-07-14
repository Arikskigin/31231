#pragma once
#include"StaticObject.h"
#include "Object.h"
#include <iostream>
#include "Factory.h"
class Wall : public StaticObject
{
public:
	Wall(const sf::Vector2f& location);
	virtual ~Wall()=default;

	
protected:
	static bool m_registerit;
};

inline bool Wall::m_registerit = Factory::registerit("wall",
	[](const sf::Vector2f& location) -> std::unique_ptr<StaticObject> { return std::make_unique<Wall>(location); });
