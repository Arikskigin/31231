#pragma once
#include"StaticObject.h"
class Gift : public StaticObject
{
public:
	Gift(const sf::Vector2f& location);
	virtual ~Gift() = 0 {}

protected:
};