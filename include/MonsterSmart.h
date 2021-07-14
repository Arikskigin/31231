#pragma once
#include "Monster.h"
#include "Factory.h"
#include "MoveSmart.h"
#include "ShootSpecial.h"
class Level;
class MonsterSmart :public Monster
{
public:
	MonsterSmart(const sf::Vector2f& location, std::unique_ptr<Player>& player);
	virtual ~MonsterSmart() = default;
	virtual void shootCollideWithPlayer(Level& level)override;
	virtual void removeShoot();
private:
	static bool m_registerit;
	std::unique_ptr<Player>& m_player;

};
inline bool MonsterSmart::m_registerit = Factory::registeritMonsters(
	[](const sf::Vector2f& location, std::unique_ptr<Player>& player) ->std::unique_ptr<Monster> {return std::make_unique<MonsterSmart>(location, player); });
