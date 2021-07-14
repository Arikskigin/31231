#include "MonsterStupid.h"
#include "Level.h"
//--------------------------------------------------------------------------------------------
// c-tor
MonsterStupid::MonsterStupid(const sf::Vector2f& location, std::unique_ptr<Player>& player):Monster("monsterStupid",location,player, std::make_unique<MoveRandom>())
{
    m_sprite.setTextureRect(sf::IntRect{ 0, 0, SIZE_OF_IMAGE, SIZE_OF_IMAGE });
    m_firstLocation = location;
}

//--------------------------------------------------------------------------------------------
// התנגשות עם יריות
void MonsterStupid::shootCollideWithPlayer(Level& level)
{
    for (int i = 0; i < m_shootVec.size(); i++)
    {
          m_indexShoot = i;
        level.playerCollideWithShoot(*m_shootVec[i]);
    }
}

//--------------------------------------------------------------------------------------------
//מחיקת יריה
void MonsterStupid::removeShoot()
{
    m_shootVec.erase(m_shootVec.begin() + m_indexShoot);
}