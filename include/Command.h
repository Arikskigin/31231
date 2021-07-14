#pragma once
#include "ResourcesManage.h"
#include <SFML/Graphics.hpp>
#include <string>
class Command {
public:
	Command(sf::RenderWindow& window, const sf::Vector2f position,std::string name);
	virtual ~Command() = 0 {}
	virtual void execute() = 0;
	bool isContent(sf::Vector2f possition); 
	virtual void draw(sf::RenderWindow& window);

protected:
	sf::Sprite m_sprite;
	sf::Text m_text;
};