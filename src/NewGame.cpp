#include "NewGame.h"

//--------------------------------------------------------------------------------------------
// c-tor
NewGame::NewGame(sf::RenderWindow& window, bool& start):Command(window,{1080, 100},"New Game"),m_start(start)
{
}

//--------------------------------------------------------------------------------------------
// פונקציה פנימית
void NewGame::execute()
{
	m_start = true;
}
