#include "Command.h"
//--------------------------------------------------------------------------------------------
// c-tor 
Command::Command(sf::RenderWindow& window, const sf::Vector2f position, std::string name)
{
	m_sprite.setTexture(ResourcesManage::instance().getImgScreen("button"));
	m_sprite.setPosition(position);
	m_text.setFont(*ResourcesManage::instance().getFont());
	m_text.setString(name);
	m_text.setPosition({position.x + LIMIT_COMMAND_X, position.y + LIMIT_COMMAND_Y});
	m_text.setCharacterSize(SIZE_CHARACTER);
}

//--------------------------------------------------------------------------------------------
// בדיקה
bool Command::isContent(sf::Vector2f possition)
{
	return(m_sprite.getGlobalBounds().contains(possition));
}

//--------------------------------------------------------------------------------------------
// ציור
void Command::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
	window.draw(m_text);
}
