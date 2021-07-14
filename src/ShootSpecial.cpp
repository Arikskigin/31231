#include "ShootSpecial.h"
//--------------------------------------------------------------------------------------------
// c-tor
ShootSpecial::ShootSpecial(const sf::Vector2f& location, sf::Vector2f direction) :Shoots("ShootSpecial", location, direction)
{
}
//--------------------------------------------------------------------------------------------
// תזוזת יריה
void ShootSpecial::move(float deltaTime)
{
	scaleAnimation(m_directionShoot);
	m_sprite.move(m_directionShoot * SHOOT_SPEED * deltaTime);
}
