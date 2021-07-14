#include "Monster.h"
#include "Factory.h"
//--------------------------------------------------------------------------------------------
// c-tor
Monster::Monster(const std::string& name, const sf::Vector2f& location, std::unique_ptr<Player>& player, std::unique_ptr<MoveStrategy> move)
	:DynamicObject(name,location),m_player(player), m_move(std::move(move)), m_numOfShoot(COLLISION_SHOOT_PLAYER),m_time(SECOND_SHOOT_MONSTER), m_removeMonster(false)
{
	m_clock.restart();
}

//--------------------------------------------------------------------------------------------
// יוצר יריות כל מספר שניות קבוע
void Monster::shoots(float deltaTime)
{
	if (m_time - m_clock.getElapsedTime().asSeconds() <= 0)
	{
		if (m_move->getDirection() != dirToVector(STAY))
			m_shootVec.emplace_back(Factory::createShoot("ShootStupid", m_move->getPosition(m_sprite), m_move->getDirection()));
		
		m_clock.restart();
	}
}

//--------------------------------------------------------------------------------------------
// קובע כיון
void Monster::setDirection()
{
	m_move->setDirection(m_sprite);
}

//--------------------------------------------------------------------------------------------
// מפחית יריות
void Monster::subShootCollition()
{
	m_sound.setBuffer(ResourcesManage::instance().getSound("boom1"));
	m_sound.play();
	m_numOfShoot--;
}

//--------------------------------------------------------------------------------------------
// בדיקה אם צריך להרוג מפלצת
bool Monster::checkRemoveMonster()
{
	return (m_numOfShoot<=0 ||m_removeMonster);
}

//--------------------------------------------------------------------------------------------
// ציור יריות
void Monster::drawShoot(sf::RenderWindow& window)
{
	for (auto& shoot : m_shootVec)
		shoot->drawOnWindow(window);
}

//--------------------------------------------------------------------------------------------
// תזוזת מפלצות
void Monster::move(float deltaTime)
{
	m_move->move(deltaTime, m_sprite,m_player);
}

//--------------------------------------------------------------------------------------------
// תזוזת יריות
void Monster::moveShoot(float deltaTime)
{
	for (auto& shoot : m_shootVec)
		shoot->move(deltaTime);
	shoots(deltaTime);
}

//--------------------------------------------------------------------------------------------
// סימון אם למחוק את המפלצת
void Monster::removeThisMonster()
{
	m_removeMonster = true;
}

