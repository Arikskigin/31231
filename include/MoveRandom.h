#pragma once
#include "MoveStrategy.h"
#include "Player.h"
class MoveRandom :public MoveStrategy
{
public:
	MoveRandom();
	~MoveRandom()=default;
	virtual void move(float deltaTime, sf::Sprite& sprite, std::unique_ptr<Player>& player)override;
	virtual void setDirection(sf::Sprite& sprite);
private:
	sf::Clock m_aiTime;
};
