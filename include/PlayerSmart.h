#pragma once 
#include "Player.h"
class Level;

class PlayerSmart :public Player
{
public:
	PlayerSmart();
	virtual ~PlayerSmart() = default;
	void shootCollideWithMonster(Level& level)override;
private:
};