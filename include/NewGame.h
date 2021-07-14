#pragma once
#include "Command.h"

#include <SFML/Graphics.hpp>
class NewGame:public Command
{
public:
	NewGame(sf::RenderWindow& window, bool& start);
	~NewGame()=default;
	virtual void execute() override;

private:
	bool& m_start;
};

