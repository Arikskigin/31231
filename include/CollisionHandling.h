#pragma once
#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <typeindex>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Object.h"
#include "PlayerRegular.h"
#include "MonsterSmart.h"
#include "MonsterStupid.h"
#include "ResourcesManage.h"
#include "Wall.h"
#include "Wanted.h"
#include "GiftSpecialShoot.h"
#include <Windows.h>
#include "Floor.h"
#include "EmptyObject.h"
#include "ShootStupid.h"
#include "GiftProtectedMode.h"
#include "GiftSpecialPlayer.h"
#include "PlayerSmart.h"
#include "ResourcesManage.h"

// Sample struct for exception throwing
struct UnknownCollision : public std::runtime_error
{
	UnknownCollision(Object& a, Object& b)
		: std::runtime_error(std::string("Unknown collision of ") + typeid(a).name() + " and " + typeid(b).name())
	{
	}
};

void processCollision(Object& object1, Object& object2);

