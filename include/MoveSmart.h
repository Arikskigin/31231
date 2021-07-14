#pragma once
#include "MoveStrategy.h"
#include "Player.h"
class MoveSmart:public MoveStrategy
{
public:
	MoveSmart();
	~MoveSmart()=default;
	virtual void move(float deltaTime, sf::Sprite& sprite, std::unique_ptr<Player>& player)override ;
	virtual void setDirection(sf::Sprite& sprite);
private:

};
