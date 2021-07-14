#include "PlayerSmart.h"
#include "Level.h"
PlayerSmart::PlayerSmart() :Player("smartPlayer")
{
}

//--------------------------------------------------------------------------------------------
// התנגשויות של יריות עם מפלצות
void PlayerSmart::shootCollideWithMonster(Level& level)
{
    for (int i = 0; i < m_shoot.size(); i++)
    {
        m_indexShoot = i;
        level.monstersCollideWithShoot(*m_shoot[i]);
    }
}