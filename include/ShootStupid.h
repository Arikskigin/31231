#pragma once
#include "Shoots.h"
#include <SFML/Graphics.hpp>
#include "Factory.h"
class ShootStupid:public Shoots
{
public:
	ShootStupid( const sf::Vector2f& location, sf::Vector2f direction);
	~ShootStupid()=default;
	virtual void move(float deltaTime)override;
protected:
	static bool m_registerit;
};
inline bool ShootStupid::m_registerit = Factory::registeritShoot("ShootStupid",
	[](const sf::Vector2f& location, sf::Vector2f direction) -> std::unique_ptr<Shoots> { return std::make_unique<ShootStupid>(location,direction); });

