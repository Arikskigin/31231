#include "GameManager.h"
//--------------------------------------------------------------------------------------------
// c-tor
GameManager::GameManager() : m_levelNum(1),m_player()
{
    m_player = std::make_unique<PlayerRegular>();

}

//--------------------------------------------------------------------------------------------
// הפונקציה העיקרית שמנהלת את המשחק
bool GameManager::run(sf::RenderWindow& window)
{
    bool  isSucsses = false;
    while (true)
    {
        Level level(m_player, m_levelNum);
            bool  isSucsses = level.run(window);
        
        if (isSucsses)
        {
            if (m_levelNum >= NUM_OF_LEVEL)
                return true;
            m_player->restart();
            m_levelNum++;
            isSucsses = false;
            
        }
        else
            return false;
    }
    return true;
}
