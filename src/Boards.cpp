#include "Boards.h"

//--------------------------------------------------------------------------------------------
// c-tor
Boards::Boards(std::unique_ptr<Player>& player):tex(ResourcesManage::instance().getImgScreen("gameBackground")),m_boardMenu(player)
{
	
	tex.setRepeated(true);
	m_background_game.setTexture(tex);
	m_background_game.setTextureRect({ 0,0,BOARD_GAME_WIDTH*2,WINDOW_HEIGHT*2 });
	m_background_game.setPosition(0, 0);
	m_background_menu.setTexture(ResourcesManage::instance().getImgScreen("menu"));
	m_background_menu.setPosition(BOARD_GAME_WIDTH, 0);

	m_viewGame = sf::View(sf::FloatRect( 0,0 , BOARD_GAME_WIDTH, WINDOW_HEIGHT));
	m_viewGame.setViewport({ 0.f, 0.f,0.75f, 1.f });
	m_viewMenu = sf::View(sf::FloatRect(BOARD_GAME_WIDTH, 0, BOARD_MENU_WIDTH, WINDOW_HEIGHT));
	m_viewMenu.setViewport({ 0.75f, 0.f,0.24f, 1.f });
}

//--------------------------------------------------------------------------------------------
// פתיחת וקריאת קבצים
void Boards::openReadFile(sf::RenderWindow& window, int levelNum, std::unique_ptr<Player>& player, vector<std::unique_ptr<Monster>>& monsters)/*, sf::Time deltaTime)*/
{
	m_boardGame.run(window, levelNum, player, monsters);
}

//--------------------------------------------------------------------------------------------
// הוזזת מסך
void Boards::moveView(std::unique_ptr<Player>& player, float deltaTime)
{

	m_locationView = player->getLocation();
	m_directionView = player->getDirection();
	if (m_directionView == RIGHT_VEC || m_directionView == LEFT_VEC)
	{
		if (m_locationView.x >=PRE_LIMIT_VIEW_X && m_locationView.x <= LIMIT_VIEW_X)
			m_viewGame.move(m_directionView * VIEW_SPEED * deltaTime);
	}
	else
		if (m_locationView.y >=PRE_LIMIT_VIEW_Y && m_locationView.y <= LIMIT_VIEW_Y)
			m_viewGame.move(m_directionView * 150.f * deltaTime);

}

//--------------------------------------------------------------------------------------------
// ציור המסך והאובייקטים
void Boards::draw(sf::RenderWindow& window, sf::Time& deltaTime, WantedHandle& wantedHandle,int levelNum,int time)
{
	window.setView(m_viewMenu);
	window.draw(m_background_menu);
	m_boardMenu.draw(window, levelNum,time);
	wantedHandle.drawOnMenu(window);

	window.setView(m_viewGame);
	window.draw(m_background_game);
	m_boardGame.draw(window);
	wantedHandle.drawOnBoard(window);
}

//--------------------------------------------------------------------------------------------
// בדיקת התנגשות שחקן עם אוביקטים סטטים
void Boards::playerCollideWithStaticObjectt(std::unique_ptr<Player>& player)
{
	m_boardGame.playerCollideWithStaticObjectt(player);
}

//--------------------------------------------------------------------------------------------
// בדיקת התנגשות מפלצות ואוביקטים סטטים
void Boards::monstersCollideWithStaticObjectt(std::unique_ptr<Monster>& monsters)
{
	m_boardGame.monstersCollideWithStaticObjectt(monsters);
}

//--------------------------------------------------------------------------------------------
// בדיקה אם זה קיר
void Boards::isWall(sf::Vector2f location)
{
	 m_boardGame.isWall(location);
}

//--------------------------------------------------------------------------------------------
// בדיקה אם המיקום ריק
bool Boards::isEmpty(sf::Vector2f location)
{
	return m_boardGame.isEmpty(location);
}
