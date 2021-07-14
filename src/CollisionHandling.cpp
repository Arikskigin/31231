#include "CollisionHandling.h"

namespace 
{
//--------------------------------------------------------------------------------------------
// שחקן ומפלצת טיפשה
	void playerMonsterStupid(Object& player, Object& regularMonster)
	{
		PlayerRegular& playerr = static_cast<PlayerRegular&>(player);
		MonsterStupid& Monster = static_cast<MonsterStupid&>(regularMonster);
		playerr.decLive();
		Monster.setFirstLocation();

	}

//--------------------------------------------------------------------------------------------
//שחקן ומפלצת חכמה
	void playerMonsterSmart(Object& player, Object& specielMonster)
	{
		PlayerRegular& playerr = static_cast<PlayerRegular&>(player);
		MonsterSmart& Monster = static_cast<MonsterSmart&>(specielMonster);
		playerr.decLive();
		Monster.setFirstLocation();
	}
	
	//--------------------------------------------------------------------------------------------
//שחקן וחומה
	void playerWall(Object& player, Object& wall)
	{
		Player& playerr = static_cast<Player&>(player);
		Wall& walll = static_cast<Wall&>(wall);
		playerr.setPrevPosition();
	}

	//--------------------------------------------------------------------------------------------
// שחקן וריצפה
	void playerFloor(Object& player, Object& floor)
	{
		Player& playerr = static_cast<Player&>(player);
		Floor& floorr = static_cast<Floor&>(floor);
		playerr.setPrevPosition();
	}

	//--------------------------------------------------------------------------------------------
// מפלצת ורצפה
	void MonsterFloor(Object& monster, Object& floor)
	{
		Monster& monsterr = static_cast<Monster&>(monster);
		Floor& floorr = static_cast<Floor&>(floor);
		monsterr.setDirection();
	}

	//--------------------------------------------------------------------------------------------
// מפלצת וקיר
	void MonsterWall(Object& monster, Object& wall)
	{
		Monster& monsterr = static_cast<Monster&>(monster);
		Wall& walll = static_cast<Wall&>(wall);
		monsterr.setDirection();
	}

	//--------------------------------------------------------------------------------------------
// שחקן וחפץ
	void playerWanted(Object& player, Object& wanted)
	{
		Player& playerr = static_cast<Player&>(player);
		Wanted& wontedd = static_cast<Wanted&>(wanted);
		playerr.NotifyObserversWanted();
	}
	
	//--------------------------------------------------------------------------------------------
// שחקן ומתנה - יריה מיוחדת
	void playerGiftSpecialShoot(Object& player, Object& giftSpecialShoot)
	{
		Player& playerr = static_cast<Player&>(player);
		GiftSpecialShoot& gift = static_cast<GiftSpecialShoot&>(giftSpecialShoot);
		playerr.setShootSpecialOn();
	}

	//--------------------------------------------------------------------------------------------
// שחקן ומתנה - מצב מוגן
	void playerGiftProtectedMode(Object& player, Object& gift)
	{
		Player& playerr = static_cast<Player&>(player);
		GiftProtectedMode& giftt = static_cast<GiftProtectedMode&>(gift);
		playerr.setProtectedMode();
	}

	//--------------------------------------------------------------------------------------------
// שחקן ומתנה - שחקן חכם
	void playerGiftSpecialPlayer(Object& player, Object& gift)
	{
		Player& playerr = static_cast<Player&>(player);
		GiftSpecialPlayer& giftt = static_cast<GiftSpecialPlayer&>(gift);
		playerr.NotifyObserversSpecialPlayer();
	}

	//--------------------------------------------------------------------------------------------
	// מיקום ריק ושחקן
	void emptyPlayer(Object& player, Object& empty)
	{
		Player& playerr = static_cast<Player&>(player);
		EmptyObject& emptyy  = static_cast<EmptyObject&>(empty);
	}

	//--------------------------------------------------------------------------------------------
// יריה טיפשה ושחקן
	void ShootStupidPlayer(Object& player, Object& shoot)
	{
		ShootStupid& shoott = static_cast<ShootStupid&>(shoot);
		Player& playerr = static_cast<Player&>(player);
		playerr.subShootStupidCollition();
	}

	//--------------------------------------------------------------------------------------------
// יריה טיפשה ומפלצת
	void ShootStupidMonster(Object& monster, Object& shoot )
	{
		ShootStupid& shoott = static_cast<ShootStupid&>(shoot);
		Monster& monsterr = static_cast<Monster&>(monster);
		monsterr.subShootCollition();
	}

	//--------------------------------------------------------------------------------------------
// שחקן חכם ומפלצת 
	void smartPlayerMonster(Object& player, Object& regularMonster)
	{
		PlayerSmart& playerr = static_cast<PlayerSmart&>(player);
		Monster& monster = static_cast<Monster&>(regularMonster);
		monster.removeThisMonster();

	}








	
	using HitFunctionPtr = void (*)(Object&, Object&);

	using Key = std::pair<std::type_index, std::type_index>;
	using HitMap = std::map<Key, HitFunctionPtr>;

	HitMap initializeCollisionMap()
	{
		HitMap phm;
		//בדיקת התנגשות עם שחקן רגיל
		phm[Key(typeid(PlayerRegular), typeid(MonsterStupid))] = &playerMonsterStupid;
		phm[Key(typeid(PlayerRegular), typeid(MonsterSmart))] = &playerMonsterSmart;
		phm[Key(typeid(PlayerRegular), typeid(EmptyObject))] = &emptyPlayer;
		phm[Key(typeid(PlayerRegular), typeid(Floor))] = &playerFloor;
		phm[Key(typeid(PlayerRegular), typeid(Wall))] = &playerWall;
		phm[Key(typeid(PlayerRegular), typeid(Wanted))] = &playerWanted;
		phm[Key(typeid(PlayerRegular), typeid(GiftSpecialShoot))] = &playerGiftSpecialShoot;
		phm[Key(typeid(PlayerRegular), typeid(GiftProtectedMode))] = &playerGiftProtectedMode;
		phm[Key(typeid(PlayerRegular), typeid(GiftSpecialPlayer))] = &playerGiftSpecialPlayer;
		phm[Key(typeid(PlayerRegular), typeid(ShootStupid))] = &ShootStupidPlayer;

		//בדיקת התנגשות עם שחקן חכם
		phm[Key(typeid(PlayerSmart), typeid(MonsterStupid))] = &smartPlayerMonster;
		phm[Key(typeid(PlayerSmart), typeid(MonsterSmart))] = &smartPlayerMonster;
		phm[Key(typeid(PlayerSmart), typeid(EmptyObject))] = &emptyPlayer;
		phm[Key(typeid(PlayerSmart), typeid(Floor))] = &playerFloor;
		phm[Key(typeid(PlayerSmart), typeid(Wall))] = &playerWall;
		phm[Key(typeid(PlayerSmart), typeid(Wanted))] = &playerWanted;
		phm[Key(typeid(PlayerSmart), typeid(GiftSpecialShoot))] = &playerGiftSpecialShoot;
		phm[Key(typeid(PlayerSmart), typeid(GiftProtectedMode))] = &playerGiftProtectedMode;
		phm[Key(typeid(PlayerSmart), typeid(GiftSpecialPlayer))] = &playerGiftSpecialPlayer;
		phm[Key(typeid(PlayerSmart), typeid(ShootStupid))] = &ShootStupidPlayer;

		//בדיקת התנגשות עם מפלצות
		phm[Key(typeid(MonsterStupid), typeid(ShootStupid))] = &ShootStupidMonster;
		phm[Key(typeid(MonsterSmart), typeid(ShootStupid))] = &ShootStupidMonster;
		phm[Key(typeid(MonsterStupid), typeid(ShootSpecial))] = &ShootStupidMonster;
		phm[Key(typeid(MonsterSmart), typeid(ShootSpecial))] = &ShootStupidMonster;
		phm[Key(typeid(MonsterSmart), typeid(Floor))] = &MonsterFloor;
		phm[Key(typeid(MonsterStupid), typeid(Floor))] = &MonsterFloor;
		phm[Key(typeid(MonsterSmart), typeid(Wall))] = &MonsterWall;
		phm[Key(typeid(MonsterStupid), typeid(Wall))] = &MonsterWall;


	

		return phm;
	}



	HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2)
	{
		static HitMap collisionMap = initializeCollisionMap();
		auto mapEntry = collisionMap.find(std::make_pair(class1, class2));
		if (mapEntry == collisionMap.end())
		{
			return nullptr;
		}
		return mapEntry->second;
	}

} // end namespace
//בודק אם 'קיים פונקציה של התנגשות
void processCollision(Object& object1, Object& object2)
{
	auto phf = lookup(typeid(object1), typeid(object2));
	if (!phf)
	{
		throw UnknownCollision(object1, object2);
	}
	phf(object1, object2);
}


