#pragma once
#include"StaticObject.h"
#include <iostream>
#include "Factory.h"
#include <string>
using std::string;
class Wanted : public StaticObject
{
public:
	Wanted(const string str,const sf::Vector2f& location);
	virtual ~Wanted() = default;
	string getName()const;
	void setName(string name);
private:
	string m_str;
};
