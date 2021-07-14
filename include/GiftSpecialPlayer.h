#pragma once
#include "Gift.h"
#include "Factory.h"
class GiftSpecialPlayer : public Gift
{
public:
	GiftSpecialPlayer(const sf::Vector2f& location);
	virtual ~GiftSpecialPlayer() = default;
protected:
	static bool m_registerit;
};
inline bool GiftSpecialPlayer::m_registerit = Factory::registeritGift(
	[](const sf::Vector2f& location) -> std::unique_ptr<Gift> { return std::make_unique<GiftSpecialPlayer>(location); });


