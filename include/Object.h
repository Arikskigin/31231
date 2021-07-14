#pragma once
#include <SFML/Graphics.hpp>
#include "ResourcesManage.h"
#include "Utilities.h"
#include <vector>
class Shoots;
class Player;
class Wall;
class Monster;
class Object
{
public:
	Object(const std::string& name, const sf::Vector2f& location);
	virtual ~Object() = 0 {}
	virtual void drawOnWindow(sf::RenderWindow& window);
	sf::FloatRect getGlobalBoundsOfSprite();
	void setPosition(sf::Vector2f location);
	sf::Vector2f getLocation();
	void setFirstLocation();


protected:
	sf::Vector2f m_location;
	sf::Vector2f m_firstLocation;
	sf::Sprite m_sprite;
};

