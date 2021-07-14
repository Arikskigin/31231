#pragma once 
#include "Player.h"
class Level;

class PlayerRegular :public Player
{
public:
	PlayerRegular();
	virtual ~PlayerRegular() = default;
	void shootCollideWithMonster(Level& level)override;
	
private:
};