#pragma once
#include "ResourcesManage.h"
#include "Utilities.h"
#include "Command.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "NewGame.h"
#include "Help.h"
#include <iostream>
#include<string>
#include "Exit.h"
using std::vector;
using std::pair;
class OpenMenu
{
public:
	OpenMenu(sf::RenderWindow& window, bool& start);
	~OpenMenu()=default;
	void run();

private:
	void draw();
	sf::Sprite m_sprite;
	sf::RenderWindow& m_window;
	typedef pair<std::string, unique_ptr<Command>> option;
	vector<option> m_buttons;

};

