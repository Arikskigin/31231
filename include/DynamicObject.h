#pragma once
#include "Object.h"
#include "Utilities.h"
class DynamicObject : public Object
{
public:
	DynamicObject(const std::string& name, const sf::Vector2f& location);
	virtual ~DynamicObject() = 0 {}
	sf::Vector2f getPosition();
	sf::Vector2f dirToVector(Direction dir);
protected:
	sf::Vector2f m_prevPosition;

};
