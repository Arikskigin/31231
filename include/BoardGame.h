#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Utilities.h"
#include "StaticObject.h"
#include "Wall.h"
#include "Floor.h"
#include <experimental/vector>
#include "Factory.h"
#include "Player.h"
#include "CollisionHandling.h"
#include <SFML/Audio.hpp>
#include "EmptyObject.h"
#include "ExceptionFile.h"
using std::vector;
using std::string;
using std::getline;
using std::ifstream;
using std::cout;
using std::unique_ptr;
using std::make_unique;
class BoardGame
{
public:
	BoardGame();
	~BoardGame()=default;
	void run(sf::RenderWindow& window, int levelNum, std::unique_ptr<Player>& player, vector<std::unique_ptr<Monster>>& monsters);
	void draw(sf::RenderWindow& window);
	void playerCollideWithStaticObjectt(std::unique_ptr<Player>& player);
	void monstersCollideWithStaticObjectt(std::unique_ptr<Monster>& monsters);
	void isWall(sf::Vector2f location);
	bool isEmpty(sf::Vector2f location);



private:
	void openFile(int levelNum);
	void readFile(std::unique_ptr<Player>& player, vector<std::unique_ptr<Monster>>& monsters);
	void setObject(char character, sf::Vector2f location, int i, std::unique_ptr<Player>& player, vector<std::unique_ptr<Monster>>& monsters);
	ifstream m_fileGame;
	typedef vector<vector <unique_ptr<Object>>> objects;
	objects m_vectorObject;
	int m_row;
	int m_col;
	sf::Clock m_gameClock;
	sf::Sound m_sound;



};

