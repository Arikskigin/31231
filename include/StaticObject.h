#pragma once
#include "Object.h"
#include <SFML/Graphics.hpp>
#include "Utilities.h"
#include "ResourcesManage.h"

class StaticObject : public Object
{
public:
	StaticObject(const std::string& name, const sf::Vector2f& location);
	virtual ~StaticObject() = 0 {}



protected:
	
};

