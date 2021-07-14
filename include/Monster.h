#pragma once
#include "DynamicObject.h"
#include"ResourcesManage.h"
#include "Utilities.h"
#include <iostream>
#include "MoveStrategy.h"
#include "Shoots.h"
class Factory;



class Monster : public DynamicObject
{
public:
	Monster(const std::string& name,const sf::Vector2f& location, std::unique_ptr<Player>& player,
		std::unique_ptr<MoveStrategy> move); 
	virtual ~Monster() = 0 {}
	virtual void move(float deltaTime);
	virtual void shoots(float deltaTime);
	void setDirection();
	void subShootCollition();
	bool checkRemoveMonster();
	void drawShoot(sf::RenderWindow& window);
	void moveShoot(float deltaTime);
	virtual void shootCollideWithPlayer(Level& level) = 0;
	virtual void removeShoot() = 0;
	void removeThisMonster();

protected:
	std::unique_ptr<Player>& m_player;
	std::unique_ptr<MoveStrategy> m_move;
	int m_numOfShoot;
	std::vector<std::unique_ptr<Shoots>>m_shootVec;
	int m_time;
	sf::Clock m_clock;
	int m_indexShoot;
	bool m_removeMonster;
	sf::Sound m_sound;
};

