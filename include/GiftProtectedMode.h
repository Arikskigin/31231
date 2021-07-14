#pragma once
#include "Gift.h"
#include "Factory.h"
class GiftProtectedMode: public Gift
{
public:
	GiftProtectedMode(const sf::Vector2f& location);
	virtual ~GiftProtectedMode() = default;
protected:
	static bool m_registerit;
};
inline bool GiftProtectedMode::m_registerit = Factory::registeritGift(
	[](const sf::Vector2f& location) -> std::unique_ptr<Gift> { return std::make_unique<GiftProtectedMode>(location); });


