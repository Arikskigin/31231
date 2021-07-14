#pragma once
#include "BoardGame.h"
#include "BoardMenu.h"
#include "Player.h"
#include "Monster.h"
#include "WantedHandle.h"
class Boards
{
public:
	Boards(std::unique_ptr<Player>& player);
	~Boards() = default;
	void openReadFile(sf::RenderWindow& window, int levelNum, std::unique_ptr<Player>& player, vector<std::unique_ptr<Monster>>& monsters);
	void moveView(std::unique_ptr<Player>& player, float deltaTime);
	void draw(sf::RenderWindow& window, sf::Time& deltaTime,WantedHandle& wantedHandle, int levelNum,int time);
	void playerCollideWithStaticObjectt(std::unique_ptr<Player>& player);
	void monstersCollideWithStaticObjectt(std::unique_ptr<Monster>& monsters);
	void isWall(sf::Vector2f location);
	bool isEmpty(sf::Vector2f location);
private:
	BoardGame m_boardGame;
	BoardMenu m_boardMenu;
	sf::View m_viewGame;
	sf::View m_viewMenu;
	sf::Texture& tex;
	sf::Sprite m_background_game;
	sf::Sprite m_background_menu;
	sf::Vector2f m_directionView;
	sf::Vector2f m_locationView;
};