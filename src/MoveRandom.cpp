#include "MoveRandom.h"
#include "Utilities.h"

//--------------------------------------------------------------------------------------------
// c-tor
MoveRandom::MoveRandom()
{
}

//--------------------------------------------------------------------------------------------
// תזוזה רנדומלית
void MoveRandom::move(float deltaTime, sf::Sprite& sprite, std::unique_ptr<Player>& player)
{
    if (m_aiTime.getElapsedTime().asSeconds() >= 3)
    {
        m_aiTime.restart();
        m_dir = static_cast<Direction>(rand() % 4);
        scaleAnimation(sprite, m_dir);
    }
    moveAnimation(sprite);
    m_prevPosition = sprite.getPosition();
    sprite.move(player->dirToVector(m_dir) * deltaTime * MONSTER_SPEED);

}

//--------------------------------------------------------------------------------------------
//קביעת כיון
void MoveRandom::setDirection(sf::Sprite& sprite)
{
    sprite.setPosition(m_prevPosition);
    m_dir = static_cast<Direction>(rand() % 4);
}
