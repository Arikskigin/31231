#include "DynamicObject.h"

//--------------------------------------------------------------------------------------------
// c-tor
DynamicObject::DynamicObject(const std::string& name, const sf::Vector2f& location) :Object(name, location)
{
}

//--------------------------------------------------------------------------------------------
// מחזיר מיקום
sf::Vector2f DynamicObject::getPosition()
{
    return m_sprite.getPosition();
}

//--------------------------------------------------------------------------------------------
// משנה מכיון לוקטור
sf::Vector2f DynamicObject::dirToVector(Direction dir)
{
    switch (dir)
    {
    case Direction::RIGHT: return RIGHT_VEC;
    case Direction::LEFT: return LEFT_VEC;
    case Direction::UP: return UP_VEC;
    case Direction::DOWN: return DOWN_VEC;
    case Direction::STAY: return STAY_VEC;
    }
    return { 0, 0 };
}