#include "PlayerRegular.h"
#include "Level.h"

//--------------------------------------------------------------------------------------------
// c-tor
PlayerRegular::PlayerRegular():Player("regularPlayer")
{
}


//--------------------------------------------------------------------------------------------
// התנגשויות של יריות עם מפלצות 
void PlayerRegular::shootCollideWithMonster(Level& level)
{
    for (int i=0;i<m_shoot.size();i++)
    {
        m_indexShoot = i;
        level.monstersCollideWithShoot(*m_shoot[i]);
    }
}

