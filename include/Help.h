#pragma once
#include "Command.h"
#include <SFML/Graphics.hpp>
class Help :public Command
{
public:
	Help(sf::RenderWindow& window);
	~Help()=default;
	virtual void execute() override;

private:
	void checkEvent(sf::RenderWindow& helpWindow);
	void drawOnWindow(sf::RenderWindow& helpWindow);
	sf::Sprite m_spriteHelp;
	int m_index;
};

