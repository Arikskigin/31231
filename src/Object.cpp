#include "Object.h"

//--------------------------------------------------------------------------------------------
// c-tor
Object::Object(const std::string& name,const sf::Vector2f& location) :m_location(location)
{
	m_sprite.setTexture(ResourcesManage::instance().getImgBoard(name));
	m_sprite.setPosition(m_location);
}

//--------------------------------------------------------------------------------------------
//קביעת מיקום
void Object::setPosition(sf::Vector2f location)
{
	m_firstLocation = location;
	m_sprite.setPosition(location);
}

//--------------------------------------------------------------------------------------------
// מחזיר מיקום
sf::Vector2f Object::getLocation()
{
	return m_sprite.getPosition();
}

//--------------------------------------------------------------------------------------------
//קובע מיקום ראשוני
void Object::setFirstLocation()
{
	m_sprite.setPosition(m_firstLocation);
}

//--------------------------------------------------------------------------------------------
//ציור בלוח
void Object::drawOnWindow(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

//--------------------------------------------------------------------------------------------
//בודק גבולות
sf::FloatRect Object::getGlobalBoundsOfSprite()
{
	return m_sprite.getGlobalBounds();
}
