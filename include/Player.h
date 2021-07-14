#pragma once
#include "DynamicObject.h"
#include"ResourcesManage.h"
#include "Utilities.h"
#include <SFML/Graphics.hpp>
#include "Subject.h"
#include "Shoots.h"
#include <vector>
#include <string>
#include <SFML/Audio.hpp>
class Level;
using std::vector;

class Player : public DynamicObject,Subject
{
public:
	Player(const std::string& name);
	virtual ~Player() = 0 {}
	void setDirection(sf::Keyboard::Key key, Level& level);
	void setPrevPosition();
	 void move(float deltaTime);
	void RegisterObserver(Observer* pObserver);
	void RemoveObserver(Observer* pObserver);
	void NotifyObserversWanted();
	void NotifyObserversSpecialPlayer();
	sf::Vector2f getDirection();
	int getLive() const;
	void decLive();
	void RemoveAllObserver();
	void shoot(float deltaTime);
	void drawShoot(sf::RenderWindow& window);
	bool getShootOn()const;
	virtual void shootCollideWithMonster(Level& level) = 0;
	void removeShoot();
	void restart();
	int getTime() const;
	sf::Vector2f getFirstPosition();
	void setProtectedMode();
	void setShootSpecialOn();
	bool getPlayerChangeMode()const;
	bool getPlayerProtectedMode()const;
	void setPlayerChangeMode(bool flag);
	Observer* getObserver(int i);
	void subShootStupidCollition();
	void checkPlayerMode();
	void changeAnimation();
	int getShootNum()const;
protected:

	bool m_protectedMode;
	Direction m_direction = Direction::STAY;
	vector<Observer*> vec_pObserver_;
	int m_live;
	std::vector<std::unique_ptr<Shoots>>m_shoot;
	bool m_shootSpecialOn;
	int m_indexShoot;
	int m_time;
	int m_timeProtectedMode;
	sf::Clock m_clockProtectedMode;
	bool m_playerChangeMode;
	int m_shootStupid;
	sf::Sound m_sound;

};

