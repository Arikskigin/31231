#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include "Utilities.h"
#include "OpenMenu.h"
#include "GameManager.h"
#include <iostream>
#include <chrono>
#include <thread>
using std::unique_ptr;
using std::make_unique;

class Controller
{
public:
	Controller();
	~Controller()=default;
	void run();
	void gameResult(bool& isSucsses);

protected:
	sf::RenderWindow m_window;
	OpenMenu m_openMenu;
	bool m_start;
	sf::Sprite m_sprite;
	sf::View m_viewGame;
	sf::Sound m_sound;
};

