#pragma once
#include "Command.h"

#include <SFML/Graphics.hpp>
class Exit :public Command
{
public:
	Exit(sf::RenderWindow& window);
	~Exit() = default;
	virtual void execute() override;

private:
};

