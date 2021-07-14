#include "MonsterSmart.h"
#include "Level.h"
//--------------------------------------------------------------------------------------------
// c-tor
MonsterSmart::MonsterSmart(const sf::Vector2f& location, std::unique_ptr<Player>& player) :Monster("monsterSmart", location,player,std::make_unique<MoveSmart>()),m_player(player)
{
	m_sprite.setTextureRect(sf::IntRect{ 0, 0, SIZE_OF_IMAGE, SIZE_OF_IMAGE });
	m_firstLocation = location;
}

//--------------------------------------------------------------------------------------------
// התנגשות עם יריות
void MonsterSmart::shootCollideWithPlayer(Level& level)
{
    for (int i = 0; i < m_shootVec.size(); i++)
    {
          m_indexShoot = i;
        level.playerCollideWithShoot(*m_shootVec[i]);
    }
}

//--------------------------------------------------------------------------------------------
// מחיקת יריה
void MonsterSmart::removeShoot()
{
    m_shootVec.erase(m_shootVec.begin() + m_indexShoot);
}