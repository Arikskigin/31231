#pragma once
#include <SFML/Graphics.hpp>
#include "Level.h"
#include "PlayerRegular.h"
#include "Player.h"
#include "ResourcesManage.h"
class GameManager
{
public:
	GameManager();
	bool run(sf::RenderWindow& window);
private:
	std::unique_ptr < Player> m_player;
	int m_levelNum;
	sf::Sprite m_sprite;
};
