#pragma once
#include "Shoots.h"
#include <SFML/Graphics.hpp>
#include "Factory.h"
class ShootSpecial :public Shoots
{
public:
	ShootSpecial(const sf::Vector2f& location, sf::Vector2f direction);
	~ShootSpecial() = default;
	virtual void move(float deltaTime)override;
protected:
	static bool m_registerit;
};
inline bool ShootSpecial::m_registerit = Factory::registeritShoot("ShootSpecial",
	[](const sf::Vector2f& location, sf::Vector2f direction) -> std::unique_ptr<Shoots> { return std::make_unique<ShootSpecial>(location, direction); });

