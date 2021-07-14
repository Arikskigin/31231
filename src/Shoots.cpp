#include "Shoots.h"

//--------------------------------------------------------------------------------------------
// c-tor
Shoots::Shoots(const std::string& name, const sf::Vector2f& location,sf::Vector2f direction):DynamicObject(name,location), m_directionShoot(direction)
{
}

//--------------------------------------------------------------------------------------------
// משנה אנימציה
void Shoots::scaleAnimation(sf::Vector2f dir)
{

	if (dir == sf::Vector2f(1, 0))
		m_sprite.setScale(1, 1);
	else if (dir == sf::Vector2f(-1, 0))
		m_sprite.setScale(-1, 1);
	else if (dir == sf::Vector2f(0, 1))
		m_sprite.setRotation(90.f);
    else if (dir == sf::Vector2f(0, -1))
        m_sprite.setRotation(-90.f);
}