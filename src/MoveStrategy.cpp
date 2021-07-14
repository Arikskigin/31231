#include "MoveStrategy.h"

//--------------------------------------------------------------------------------------------
// c-tor
MoveStrategy::MoveStrategy()
{
}

//--------------------------------------------------------------------------------------------
//  מפלצות שינוי אנימציה
void MoveStrategy::moveAnimation(sf::Sprite& sprite)
{
	static int x = 0;
	if (m_dir == RIGHT || m_dir == LEFT)
	{
		sprite.setTextureRect(sf::IntRect({ SIZE_OF_IMAGE * x,0,SIZE_OF_IMAGE ,SIZE_OF_IMAGE }));
		x = (x + 1) % SIZE_IMAGE_ANIMATION;
	}
	else
		x = 0;
}

//--------------------------------------------------------------------------------------------
// שינוי אנימציה יריות
void MoveStrategy::scaleAnimation( sf::Sprite& sprite, Direction& dir)
{
    switch (dir)
    {
    case RIGHT:
        sprite.setScale(1, 1);
        break;
    case LEFT:
        sprite.setScale(-1, 1);
        break;
    default:
        break;
    }
}

//--------------------------------------------------------------------------------------------
// מחזיר מיקום
sf::Vector2f MoveStrategy::getPosition(sf::Sprite& sprite)
{
    return sprite.getPosition();
}

//--------------------------------------------------------------------------------------------
// מחזיר כיון
sf::Vector2f MoveStrategy::getDirection()
{
    return dirToVector(m_dir);
}

//--------------------------------------------------------------------------------------------
// משנה מכיון לוקטור
sf::Vector2f MoveStrategy::dirToVector(Direction dir)
{
    switch (dir)
    {
    case Direction::RIGHT: return { 1, 0 };
    case Direction::LEFT: return { -1, 0 };
    case Direction::UP: return { 0, -1 };
    case Direction::DOWN: return { 0, 1 };
    case Direction::STAY: return { 0, 0 };
    }
    return { 0, 0 };
}