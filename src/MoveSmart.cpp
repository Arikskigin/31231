#include "MoveSmart.h"

//--------------------------------------------------------------------------------------------
// c-tor
MoveSmart::MoveSmart()
{
}

//--------------------------------------------------------------------------------------------
// תזוזה חכמה לפ אלגוריתם
void MoveSmart::move(float deltaTime, sf::Sprite& sprite, std::unique_ptr<Player>& player)
{
	m_prevPosition = sprite.getPosition();
	sf::Vector2f  destination, moveOption;
	Direction direction;
	float distanceFromPlayer1 = std::abs(player->getPosition().x - sprite.getPosition().x) + std::abs(player->getPosition().y - sprite.getPosition().y);

	for (int index = 0; index < 4; index++)
	{
		direction = (Direction(index));
		destination = player->dirToVector(direction) * deltaTime * 60.f + sprite.getPosition();
		auto distanceFromPlayer2 = (std::abs(player->getPosition().x - destination.x) + std::abs(player->getPosition().y - destination.y));
		if ((distanceFromPlayer2 < distanceFromPlayer1))
		{
			m_dir = direction;
			moveOption = player->dirToVector(m_dir) * deltaTime * MONSTER_SPEED;
		}
	}
	scaleAnimation(sprite, m_dir);
	moveAnimation(sprite);
	sprite.move(moveOption);
}

//--------------------------------------------------------------------------------------------
// קביעת כיון
void MoveSmart::setDirection(sf::Sprite& sprite)
{
	sprite.setPosition(m_prevPosition);
	m_dir = STAY;
}
