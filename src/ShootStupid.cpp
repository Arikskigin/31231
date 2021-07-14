#include "..\include\ShootStupid.h"
//--------------------------------------------------------------------------------------------
// c-tor
ShootStupid::ShootStupid( const sf::Vector2f& location, sf::Vector2f direction):Shoots("ShootStupid",location,direction)
{
}

//--------------------------------------------------------------------------------------------
//תזוזת יריה
void ShootStupid::move(float deltaTime)
{
	scaleAnimation(m_directionShoot);
	m_sprite.move(m_directionShoot * SHOOT_SPEED * deltaTime);
}
