#include "Wanted.h"

//--------------------------------------------------------------------------------------------
// c-tor
Wanted::Wanted(const string str, const sf::Vector2f& location) :StaticObject(str, location), m_str(str)
{
	m_sprite.setOrigin({ 0, 0 });
}

//--------------------------------------------------------------------------------------------
// מחזיר שם
string Wanted::getName()const
{
	return m_str;
}

//--------------------------------------------------------------------------------------------
// מכניס שם
void Wanted::setName(string name)
{
	m_str = name;
}
