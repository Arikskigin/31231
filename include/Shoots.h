#pragma once
#include "DynamicObject.h"
#include"ResourcesManage.h"
#include "Utilities.h"
#include <SFML/Graphics.hpp>
#include <string>

class Shoots : public DynamicObject
{
public:
	Shoots(const std::string& name, const sf::Vector2f& location,sf::Vector2f direction);
	virtual ~Shoots()=0 {}
	virtual void move(float deltaTime) = 0;
	void scaleAnimation(sf::Vector2f  dir);
protected:
	sf::Vector2f m_directionShoot;
};