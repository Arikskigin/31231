#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Utilities.h"
#include "StaticObject.h"
#include "Wanted.h"
#include "Factory.h"
#include "Object.h"
#include <experimental/vector>
#include <SFML/Audio.hpp>
#include "Player.h"
using std::vector;
using std::string;
using std::getline;
using std::ifstream;
using std::cout;
using std::unique_ptr;
using std::make_unique;
class BoardMenu
{
public:
	BoardMenu(std::unique_ptr<Player>& player);
	~BoardMenu()=default;
	void draw(sf::RenderWindow& window, int levelNum, int time);


private:
	std::unique_ptr<Player>& m_player;

	void playerLive();
	void levelTime(int time);
	void levelNum(int levelNumber);
	void list();
	void message();
	void shoot();
	sf::Font m_font;
	sf::Text m_levelNumText;
	sf::Text m_listText;
	sf::Text m_timeLevelText;
	sf::Text m_livePlayerText;
	sf::Text m_messageText;
	sf::Text m_numShootText;
	sf::Sound m_soundClock;

};
