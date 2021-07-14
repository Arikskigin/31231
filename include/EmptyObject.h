#pragma once
#include "StaticObject.h"
#include "Factory.h"
class EmptyObject:public StaticObject
{
public:
	EmptyObject(const sf::Vector2f& location);
	~EmptyObject()=default;

protected:
	static bool m_registerit;
};

inline bool EmptyObject::m_registerit = Factory::registerit("empty",
	[](const sf::Vector2f& location) -> std::unique_ptr<StaticObject> { return std::make_unique<EmptyObject>(location); });
