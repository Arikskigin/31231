#pragma once
#include <vector>
#include "Monster.h"
#include "Boards.h"
#include "Player.h"
#include "WantedHandle.h"
#include "Observer.h"
#include "PlayerRegular.h"
#include "PlayerSmart.h"
#include "ExceptionFile.h"
using std::vector;

class Level:public Observer
{
public:
	Level(std::unique_ptr<Player>& player,int& levelNum);
	~Level()=default;
	bool run(sf::RenderWindow& window);
	void checkEvent(sf::RenderWindow& window, sf::Time& deltaTime);
	void draw(sf::RenderWindow& window, sf::Time& deltaTime);
	void moveObject(sf::Time deltaTime);
	void mainCollision();
	void isWall(sf::Vector2f location);
	bool isEmpty(sf::Vector2f location);
	void Update();
	int timePassed();
	int timePassedSpecialMode();
	void stopMusic();
	void UpdateSpecialPlayr();
	void monstersCollideWithShoot(Shoots& shoot);
	void playerCollideWithShoot(Shoots& shoot);


private:
	void monstersCollideWithStaticObject();
	void playerCollideWithMonster();
	void playerCollideWithWanted();
	void checkModePlayer();
	void changePlayerModeToSmart();
	void changePlayerModeToRegular();


	std::unique_ptr <Player>& m_player;
	vector<std::unique_ptr<Monster>>m_monsters;
	Boards m_boards;
	sf::Clock m_gameClock;
	WantedHandle m_wantedHandle;
	int& m_levelNum;
	bool m_success;
	sf::Clock m_timePassed;
	int m_indexMonster;
	sf::Clock m_clockTimeSpeicalMode;
	int m_timeSpeicalMode;
	bool m_specialPlayerOn;
	vector<Observer*> m_playerObserver;
	sf::Music m_musicBackgraund;
};

