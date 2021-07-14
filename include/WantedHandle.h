#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Utilities.h"
#include "Wanted.h"
#include "Factory.h"
#include "Player.h"
#include "Observer.h"
#include "CollisionHandling.h"
#include "BoardGame.h"
#include "ExceptionFile.h"
#include <exception>
using std::vector;
using std::string;
using std::getline;
using std::ifstream;
using std::cout;
using std::unique_ptr;
using std::make_unique;
class Level;
class  WantedHandle:public Observer
{
public:
	 WantedHandle(std::unique_ptr<Player>& pPlayer, Level& level);
	~ WantedHandle()=default;
	void readFile(int levelNum);
	void drawOnMenu(sf::RenderWindow& window);
	void drawOnBoard(sf::RenderWindow& window);
	void Update();
	void playerCollideWithWantedd(std::unique_ptr<Player>& player);
	bool checkLocation(sf::Vector2f location);
	bool endVector();

	void UpdateSpecialPlayr(){}


private:
	void randomLocation();
	Level& m_level;
	ifstream m_fileWamted;
	vector <unique_ptr<Wanted>> m_vectorWanted;
	int m_index;
	int m_x, m_y;
	unique_ptr<Wanted> m_wantedObject;
	sf::Sprite m_ring;
	sf::Sound m_sound;

};
