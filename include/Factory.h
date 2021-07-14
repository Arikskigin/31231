#pragma once
#include <iostream>
#include "StaticObject.h"
#include "Monster.h"
#include"Gift.h"
#include <SFML/Graphics.hpp>
#include<vector>
#include "Shoots.h"


typedef std::map<std::string, std::unique_ptr<StaticObject>(*)(const sf::Vector2f& location)> mapStaticObject;
typedef std::vector<std::unique_ptr<Monster>(*)(const sf::Vector2f& location, std::unique_ptr<Player>& player)> vecMonster;
typedef std::vector<std::unique_ptr<Gift>(*)(const sf::Vector2f& location)> vecGift;
typedef std::map<std::string, std::unique_ptr<Shoots>(*)(const sf::Vector2f& location,sf::Vector2f direction)> mapshoot;

class Factory
{
public:
	Factory()=default;
	~Factory() = default;
	static std::unique_ptr<StaticObject> create(const std::string& name, const sf::Vector2f& location);
	static bool registerit(const std::string& name, std::unique_ptr<StaticObject>(*f)(const sf::Vector2f& location));

	static std::unique_ptr<Monster> createMonsters( const sf::Vector2f& location, std::unique_ptr<Player>& player);
	static bool registeritMonsters( std::unique_ptr<Monster>(*f)(const sf::Vector2f& location, std::unique_ptr<Player>& player));

	static std::unique_ptr<Gift> createGift(const sf::Vector2f& location);
	static bool registeritGift(std::unique_ptr<Gift>(*f)(const sf::Vector2f& location));

	static std::unique_ptr<Shoots> createShoot(const std::string& name, const sf::Vector2f& location, sf::Vector2f direction);
	static bool registeritShoot(const std::string& name, std::unique_ptr<Shoots>(*f)(const sf::Vector2f& location, sf::Vector2f direction));


private:
	static mapStaticObject& getMapStaticObject();
	static vecMonster& getVecMonster();
	static vecGift& getVecGift();
	static mapshoot& getMapcShoot();
};