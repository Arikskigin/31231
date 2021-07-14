#include "BoardGame.h"
#include "Level.h"

//--------------------------------------------------------------------------------------------
// c-tor
BoardGame::BoardGame():m_col(0),m_row(0)
{
}

//--------------------------------------------------------------------------------------------
// פתיחת וקריאת קבצים
void BoardGame::run(sf::RenderWindow& window, int levelNum, std::unique_ptr<Player>& player, vector<std::unique_ptr<Monster>>& monsters)
{
	openFile(levelNum);
	readFile(player, monsters);
}

//--------------------------------------------------------------------------------------------
// פתיחת קובץ
void BoardGame::openFile(int levelNum)
{
	string file = "LEVEL" + std::to_string(levelNum) + ".txt";

	m_fileGame = ifstream(file);
	if (!m_fileGame.is_open())
		throw ExceptionFile ();
}

//--------------------------------------------------------------------------------------------
// קריאת קובץ
void BoardGame::readFile(std::unique_ptr<Player>& player, vector<std::unique_ptr<Monster>>& monsters)
{
	string str;
	char character;
	m_fileGame >> m_row ;
	m_vectorObject.resize(m_row);
	getline(m_fileGame, str);
	int i=0;
	while (!m_fileGame.eof())
	{
		
		getline(m_fileGame, str);
		for(int j=0;j<str.size();j++)
			setObject(str[j], sf::Vector2f(j * SIZE_OF_IMAGE, i * SIZE_OF_IMAGE), i, player, monsters);
		i++;
	}
}

//--------------------------------------------------------------------------------------------
//מכניס למטריצה
void BoardGame::setObject(char character, sf::Vector2f location,int i, std::unique_ptr<Player>& player, vector<std::unique_ptr<Monster>>& monsters)
{
	switch (character)
	{

	case PLAYER:
			player->setPosition(location);
		break;
	case MONSTER:
	{
		monsters.emplace_back(Factory::createMonsters(location, player));
	}
		break;
	case WALL:
		m_vectorObject[i].emplace_back(Factory::create("wall", location));
		break;
	case FLOOR:
		m_vectorObject[i].emplace_back(Factory::create("floor", location));
		break;
	case GIFT:
		m_vectorObject[i].emplace_back(Factory::createGift(location));
		break;
	case EMPTY:
		m_vectorObject[i].emplace_back(Factory::create("empty", location));
		break;
	default:
		break;
	}
}

//--------------------------------------------------------------------------------------------
// מצייר על הלוח
void BoardGame::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < m_vectorObject.size(); i++)
		for (int j = 0; j < m_vectorObject[i].size(); j++)
			m_vectorObject[i][j]->drawOnWindow(window);
}

//--------------------------------------------------------------------------------------------
// בדיקת התנגשות שחקן ואוביקטים סטטים
void BoardGame::playerCollideWithStaticObjectt(std::unique_ptr<Player>& player)
{
	for (int i = 0; i < m_vectorObject.size(); i++)
		for (int j = 0; j < m_vectorObject[i].size(); j++)
			if (player->getGlobalBoundsOfSprite().intersects(m_vectorObject[i][j]->getGlobalBoundsOfSprite()))//סדיקה אם קיים חפיפה בין שתי האוביקטיים
			{
				processCollision(*player, *m_vectorObject[i][j]);
				if (typeid(*m_vectorObject[i][j]).name() != typeid(Wall).name() && typeid(*m_vectorObject[i][j]).name() != typeid(Floor).name())
					m_vectorObject[i].erase(m_vectorObject[i].begin() + j);//מחיקה
			}
		
}

//--------------------------------------------------------------------------------------------
//בדיקת התנגשות מפלצות עם אוביקטים סטטים
void BoardGame::monstersCollideWithStaticObjectt(std::unique_ptr<Monster>& monsters)
{
	for (int i = 0; i < m_vectorObject.size(); i++)
		for (int j = 0; j < m_vectorObject[i].size(); j++)
		{
			if (typeid(*m_vectorObject[i][j]).name() == typeid(Floor).name()||
				typeid(*m_vectorObject[i][j]).name() == typeid(Wall).name())
				if (monsters->getGlobalBoundsOfSprite().intersects(m_vectorObject[i][j]->getGlobalBoundsOfSprite()))//סדיקה אם קיים חפיפה בין שתי האוביקטיים
					processCollision(*monsters, *m_vectorObject[i][j]);//שליחה לפונקציה שמטפלת בהתנגשות
		}
}

//--------------------------------------------------------------------------------------------
// בדיקה אם במיקום יש חומה
void BoardGame::isWall(sf::Vector2f location)
{
	for (int i = 0; i < m_vectorObject.size(); i++)
	{
		for (int j = 0; j < m_vectorObject[i].size(); j++)
		{
			if ((typeid(*m_vectorObject[i][j]) == typeid(Wall)))
				if (m_vectorObject[i][j]->getGlobalBoundsOfSprite().contains(location))
				{
					m_vectorObject[i].erase(m_vectorObject[i].begin() + j);
					m_sound.setBuffer(ResourcesManage::instance().getSound("boom1"));
					m_sound.play();
				}
		}
	}
}

//--------------------------------------------------------------------------------------------
// בדיקה אם המיקום ריק
bool BoardGame::isEmpty(sf::Vector2f location)
{
	for (int i = 0; i < m_vectorObject.size(); i++)
		for (int j = 0; j < m_vectorObject[i].size(); j++)
			if (typeid(*m_vectorObject[i][j]).name() == typeid(EmptyObject).name())
				if (m_vectorObject[i][j]->getGlobalBoundsOfSprite().contains(location))
					return true;
	return false;
}
