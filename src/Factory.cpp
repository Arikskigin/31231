#include "Factory.h"
//--------------------------------------------------------------------------------------------
// יצירת אובייקטים סטטים
std::unique_ptr<StaticObject> Factory::create(const std::string& name, const sf::Vector2f& location)
{
	auto it = getMapStaticObject().find(name);
	if (it == getMapStaticObject().end())
		return nullptr;
	return it->second(location);
}

//--------------------------------------------------------------------------------------------
// רישום אובייקטים סטטים
bool Factory::registerit(const std::string& name, std::unique_ptr<StaticObject>(*f)(const sf::Vector2f& location))
{
	getMapStaticObject().emplace(name, f);
	return true;
}

//--------------------------------------------------------------------------------------------
// יצירת מפלצות
std::unique_ptr<Monster> Factory::createMonsters( const sf::Vector2f& location, std::unique_ptr<Player>& player)
{
	int typeOfVecc = rand() % getVecMonster().size();
	return getVecMonster()[typeOfVecc](location,player);
}

//--------------------------------------------------------------------------------------------
// רישום מפלצות
bool Factory::registeritMonsters( std::unique_ptr<Monster>(*f)(const sf::Vector2f& location, std::unique_ptr<Player>& player))
{
	getVecMonster().emplace_back(f);
	return true;
}

//--------------------------------------------------------------------------------------------
// יצירת מתנות
std::unique_ptr<Gift> Factory::createGift(const sf::Vector2f& location)
{
	int typeOfVecc = rand() % getVecGift().size();
	return getVecGift()[typeOfVecc](location);
}

//--------------------------------------------------------------------------------------------
// רישום מתנות
bool Factory::registeritGift(std::unique_ptr<Gift>(*f)(const sf::Vector2f& location))
{
	getVecGift().emplace_back(f);
	return true;
}

//--------------------------------------------------------------------------------------------
//יצירת יריות
std::unique_ptr<Shoots> Factory::createShoot(const std::string& name, const sf::Vector2f& location, sf::Vector2f direction)
{
	auto it = getMapcShoot().find(name);
	if (it == getMapcShoot().end())
		return nullptr;

	return it->second(location,direction);
}

//--------------------------------------------------------------------------------------------
// רישם יריות
bool Factory::registeritShoot(const std::string& name, std::unique_ptr<Shoots>(*f)(const sf::Vector2f& location, sf::Vector2f direction))
{
	getMapcShoot().emplace(name, f);
	return true;
}

//--------------------------------------------------------------------------------------------
mapStaticObject& Factory::getMapStaticObject()
{
	static mapStaticObject m_map;
	return m_map;
}

//--------------------------------------------------------------------------------------------
vecMonster& Factory::getVecMonster()
{
	static vecMonster m_vecMonster;
	return m_vecMonster;
}

//--------------------------------------------------------------------------------------------
vecGift& Factory::getVecGift()
{
	static vecGift m_vecGift;
	return m_vecGift;
}

//--------------------------------------------------------------------------------------------
mapshoot& Factory::getMapcShoot()
{
	static mapshoot m_mapShoot;
	return m_mapShoot;
}


