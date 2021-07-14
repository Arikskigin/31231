#include "BoardMenu.h"
#include <memory>
//--------------------------------------------------------------------------------------------
// c-tor
BoardMenu::BoardMenu(std::unique_ptr<Player>& player):m_player(player)
{

	m_font = (*ResourcesManage::instance().getFont());
}

//--------------------------------------------------------------------------------------------
//מצייר על התפריט
void BoardMenu::draw(sf::RenderWindow& window, int levelNumber,int time)
{
	playerLive();
	levelNum(levelNumber);
	levelTime(time);
	list();
	message();
	shoot();
	window.draw(m_livePlayerText);
	window.draw(m_levelNumText);
	window.draw(m_timeLevelText);
	window.draw(m_messageText);
	window.draw(m_listText);
	window.draw(m_numShootText);
}

//--------------------------------------------------------------------------------------------
//מדפיס כמה חיים יש לשחקן
void BoardMenu::playerLive()
{
	m_livePlayerText.setFont(m_font);
	m_livePlayerText.setPosition( { 1100,400});
	m_livePlayerText.setString("LIVE: "+std::to_string(m_player->getLive()));
	m_livePlayerText.setCharacterSize(40.f);
	m_livePlayerText.setFillColor(sf::Color::White);
}

//--------------------------------------------------------------------------------------------
//מדפיס כמה זמן נשאר
void BoardMenu::levelTime(int time)
{
	auto color = sf::Color();
	if (time / 60 >= 10 && time % 60 >= 10)
		m_timeLevelText = sf::Text(std::to_string(time / 60) + ":" + std::to_string(time % 60), m_font);
	else if (time / 60 < 10 && time % 60 >= 10)
		m_timeLevelText = sf::Text(std::to_string(0) + std::to_string(time / 60) + ":" + std::to_string(time % 60), m_font);
	else if (time / 60 >= 10 && time % 60 < 10)
		m_timeLevelText = sf::Text(std::to_string(time / 60) + ":" + std::to_string(0) + std::to_string(time % 60), m_font);
	else
		m_timeLevelText = sf::Text(std::to_string(0) + std::to_string(time / 60) + ":" + std::to_string(0) + std::to_string(time % 60), m_font);
	if (time % 60 <= 5 && time / 60 < 1)
	{
		color = sf::Color::Red;
		m_soundClock.setBuffer(ResourcesManage::instance().getSound("clock"));
		m_soundClock.play();
	}
	else
		color = sf::Color::White;
	m_timeLevelText.setPosition({ 1100,300 });
	m_timeLevelText.setCharacterSize(40.f);
	m_timeLevelText.setColor(color);
}

//--------------------------------------------------------------------------------------------
// מדפיס מה המספר שלב
void BoardMenu::levelNum(int levelNumber)
{
	m_levelNumText.setFont(m_font);
	m_levelNumText.setPosition({ 1100,200 });
	m_levelNumText.setString("LEVEL: "+std::to_string(levelNumber));
	m_levelNumText.setCharacterSize(40.f);
	m_levelNumText.setFillColor(sf::Color::White);
}

//--------------------------------------------------------------------------------------------
// מדפיס את המצב של השחקן
void BoardMenu::list()
{
	m_listText.setFont(m_font);
	m_listText.setPosition({ 1050,50 });
	m_listText.setCharacterSize(40.f);
	m_listText.setFillColor(sf::Color::Red);
	m_listText.setString("NEED TO FIND:");
}

void BoardMenu::message()
{
	m_messageText.setFont(m_font);
	m_messageText.setPosition({ 1050,600 });
	m_messageText.setCharacterSize(40.f);
	m_messageText.setFillColor(sf::Color::Green);
	if (m_player->getPlayerChangeMode())
		m_messageText.setString("SpecialPlayerMode");
	else if (m_player->getShootOn())
		m_messageText.setString("SpecialShoot");
	else if (m_player->getPlayerProtectedMode())
		m_messageText.setString("ProtectedMode");
	else
		m_messageText.setString("");
}

void BoardMenu::shoot()
{
	m_numShootText.setFont(m_font);
	m_numShootText.setPosition({ 1100,500 });
	m_numShootText.setString("SHOOT: " + std::to_string(m_player->getShootNum()));
	m_numShootText.setCharacterSize(40.f);
	m_numShootText.setFillColor(sf::Color::White);
}



