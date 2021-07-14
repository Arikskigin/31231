#pragma once
#include "Utilities.h"
#include <SFML/Graphics.hpp>
#include"Player.h"
class MoveStrategy
{
public:
	MoveStrategy();
	~MoveStrategy() = default;
	virtual void move(float deltaTime,sf::Sprite& sprite, std::unique_ptr<Player>& player ) = 0;
	virtual void setDirection(sf::Sprite& sprite)=0;
	void moveAnimation(sf::Sprite& sprite);
	void scaleAnimation( sf::Sprite& sprite,Direction& dir);
	sf::Vector2f getPosition(sf::Sprite& sprite);
	sf::Vector2f getDirection();
	sf::Vector2f dirToVector(Direction dir);

protected:
	sf::Vector2f m_prevPosition;
	Direction m_dir = Direction::STAY;
};