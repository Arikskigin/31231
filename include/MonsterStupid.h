#pragma once
#include "Monster.h"
#include "Factory.h"
#include "MoveRandom.h"
#include "ShootStupid.h"
class Level;
class MonsterStupid :public Monster
{
public:
	MonsterStupid(const sf::Vector2f& location, std::unique_ptr<Player>& player);
	virtual ~MonsterStupid() = default;
	virtual void shootCollideWithPlayer(Level& level)override;
	virtual void removeShoot();

private:

	static bool m_registerit;
};

inline bool MonsterStupid::m_registerit = Factory::registeritMonsters(
	[](const sf::Vector2f& location, std::unique_ptr<Player>& player) ->std::unique_ptr<Monster> { return  std::make_unique<MonsterStupid>(location, player); });
