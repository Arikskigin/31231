#include "Level.h"

//--------------------------------------------------------------------------------------------
// c-tor
Level::Level(std::unique_ptr<Player>& player ,int& levelNum)
    :m_wantedHandle(player,*this),m_boards(player),m_levelNum(levelNum),m_success(false),m_player(player),m_indexMonster(0)
    , m_specialPlayerOn(false),m_timeSpeicalMode(10)
{
    m_player->RegisterObserver(this);//רישום לאובזרבר
    m_timePassed.restart();

}

//--------------------------------------------------------------------------------------------
// הפונקציה הראשית שמנהלת את השלב
bool Level::run(sf::RenderWindow& window)
{
    (*ResourcesManage::instance().getMusic()).setVolume(50);
    (*ResourcesManage::instance().getMusic()).play();
	try {
		m_boards.openReadFile(window, m_levelNum, m_player, m_monsters);
		m_wantedHandle.readFile(m_levelNum);
	}
	catch (const ExceptionFile & e)
	{
		std::cout << e.what();
		exit(EXIT_FAILURE);
	}
    
    while (window.isOpen()) {
        auto deltaTime = m_gameClock.restart();
        window.clear();
        draw(window,deltaTime);
        window.display();
        checkEvent(window, deltaTime);
        moveObject(deltaTime );
		checkModePlayer();
        if ((m_player->getLive() <= 0)|| (timePassed() <= 0))
        {
            stopMusic();
            return false;
        }
        if (m_success)
            return true;
    }
}

//--------------------------------------------------------------------------------------------
// הפונקציה בודקת אם נגמרו האובייקטים שצריכים למצוא ואז נגמר השלב
void Level::Update()
{
    if (m_wantedHandle.endVector())
        m_success = true;
}

//--------------------------------------------------------------------------------------------
// בדיקת המאורע שהתקבל
void Level::checkEvent(sf::RenderWindow& window, sf::Time& deltaTime)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            exit(0);
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape)
            {
                window.close();
                break;
            }
            m_player->setDirection(event.key.code,*this);
            break;

        }
    }
}

//--------------------------------------------------------------------------------------------
//ציור כל השלב על הלוח
void Level::draw(sf::RenderWindow& window, sf::Time& deltaTime)
{
    m_boards.draw(window,deltaTime,m_wantedHandle, m_levelNum, timePassed());
    m_player->drawOnWindow(window);
    m_player->drawShoot(window);
	for (auto& monster : m_monsters)
	{
		monster->drawOnWindow(window);
		monster->drawShoot(window);
	}
}

//--------------------------------------------------------------------------------------------
// הוזזת האובייקטים הדינאמים בשלב
void Level::moveObject(sf::Time deltaTime)
{
    m_player->move(deltaTime.asSeconds());
    m_player->shoot(deltaTime.asSeconds());
    m_boards.moveView(m_player, deltaTime.asSeconds());
	for (auto& monster : m_monsters)
	{
		monster->move(deltaTime.asSeconds());
		monster->moveShoot(deltaTime.asSeconds());//תזוזת יריות של מפלצות
	}
	mainCollision();//בדיקת התנגשויות
}

//--------------------------------------------------------------------------------------------
// הפונקציה בודקת התנגשויות
void Level::mainCollision()
{
	m_boards.playerCollideWithStaticObjectt(m_player);//שחקן עם אובייקטים סטטים
    playerCollideWithMonster();//שחקן עם מפלצות
    monstersCollideWithStaticObject();//מפלצות עם אובייקטים סטטים
    playerCollideWithWanted();//שחקן עם האוביקטים שהוא מחפש
    m_player->shootCollideWithMonster(*this);//מפלצות עם היריות של השחקן
    for (int i = 0; i < m_monsters.size(); i++)
    {
        m_indexMonster = i;
        m_monsters[i]->shootCollideWithPlayer(*this);//שחקן עם יריות של מפלצות
    }
}

//--------------------------------------------------------------------------------------------
// בדיקת התנגשויות של מפלצות עם אובייקטים סטטים
void Level::monstersCollideWithStaticObject()
{
    for (auto& monster : m_monsters)
        m_boards.monstersCollideWithStaticObjectt(monster);

}

//--------------------------------------------------------------------------------------------
// בדיקת התנגשויות של שחקן עם מפלצות
void Level::playerCollideWithMonster()
{
    for (int i = 0; i < m_monsters.size(); i++)//רצים על הווקטור של המפלצות
    {
        if (m_player->getGlobalBoundsOfSprite().intersects(m_monsters[i]->getGlobalBoundsOfSprite()))//  בדיקה עם יש חפיפה בין שני האוביקטים
            processCollision(*m_player, *m_monsters[i]);
        if (m_monsters[i]->checkRemoveMonster())
            m_monsters.erase(m_monsters.begin() + i);
    }
}

//--------------------------------------------------------------------------------------------
// בדיקת התנגשויות של המפלצות עם היריות של השחקן
void Level::monstersCollideWithShoot(Shoots& shoot)
{
    for (int i = 0; i < m_monsters.size(); i++)//רצים על הווקטור של המפלצות
    {
        if (m_monsters[i]->getGlobalBoundsOfSprite().intersects(shoot.getGlobalBoundsOfSprite()))//  בדיקה עם יש חפיפה בין שני האוביקטים
        {
            processCollision(*m_monsters[i], shoot);
            m_player->removeShoot();
        }
        if(m_monsters[i]->checkRemoveMonster())
            m_monsters.erase(m_monsters.begin() + i);
    }
}

//--------------------------------------------------------------------------------------------
// בדיקת התנגשויות של השחקן עם יריות שח המפלצות
void Level::playerCollideWithShoot(Shoots& shoot)
{
	if (m_player->getGlobalBoundsOfSprite().intersects(shoot.getGlobalBoundsOfSprite()))//  בדיקה עם יש חפיפה בין שני האוביקטים
	{
		processCollision(*m_player, shoot);
		m_monsters[m_indexMonster]->removeShoot();
	}
}

//--------------------------------------------------------------------------------------------
// בדיקת התנגשויות שחקן עם החפצים שהוא מחפש
void Level::playerCollideWithWanted()
{
    m_wantedHandle.playerCollideWithWantedd(m_player);
}

//--------------------------------------------------------------------------------------------
// בדיקה אם האובייקט הוא קיר
void Level::isWall(sf::Vector2f location)
{
    m_boards.isWall(location);
}

//--------------------------------------------------------------------------------------------
// בדיקה אם התא ריק
bool Level::isEmpty(sf::Vector2f location)
{
    return m_boards.isEmpty(location);
}

//--------------------------------------------------------------------------------------------
// בדיקה אם הזמן שמוקצב לשלב עבר
int Level::timePassed()
{
    return m_player->getTime() - m_timePassed.getElapsedTime().asSeconds();
}

//--------------------------------------------------------------------------------------------
// בדיקה אם הזמן שמוקצב לשחקן מיוחד עבר
int Level::timePassedSpecialMode()
{
    return m_timeSpeicalMode - m_clockTimeSpeicalMode.getElapsedTime().asSeconds();
}

//--------------------------------------------------------------------------------------------
// משנה את השחקן הרגיל לשחקן חכם
void Level::changePlayerModeToSmart()
{
	for (int i = 0; i < NUM_OF_OBSERVER_PLAYER; i++)
		m_playerObserver.emplace_back(m_player->getObserver(i));
    sf::Vector2f location = m_player->getLocation();
    m_clockTimeSpeicalMode.restart();
    m_player->RemoveAllObserver();
    m_player = std::make_unique<PlayerSmart>();
    m_player->setPosition(location);
    for (auto& o : m_playerObserver)
        m_player->RegisterObserver(o);
}

//--------------------------------------------------------------------------------------------
// משנה את השחקן החכם לשחקן רגיל
void Level::changePlayerModeToRegular()
{
	for (int i = 0; i < NUM_OF_OBSERVER_PLAYER; i++)
		m_playerObserver.emplace_back(m_player->getObserver(i));
    sf::Vector2f location = m_player->getLocation();
    m_player->RemoveAllObserver();
    m_player = std::make_unique<PlayerRegular>();
    m_player->setPosition(location);
    for (auto& o : m_playerObserver)
        m_player->RegisterObserver(o);
}

//--------------------------------------------------------------------------------------------
// עצירת מוזיקה
void Level::stopMusic()
{
    (*ResourcesManage::instance().getMusic()).stop();
}

//--------------------------------------------------------------------------------------------
//עדכון מצב השחקן
void Level::UpdateSpecialPlayr()
{
	m_specialPlayerOn = true;
	m_clockTimeSpeicalMode.restart();
}

//--------------------------------------------------------------------------------------------
// בדיקב איזה סוג שחקן צריך להיות
void Level::checkModePlayer()
{
	if (m_specialPlayerOn )
	{
		changePlayerModeToSmart();
		m_player->setPlayerChangeMode(true);
		m_specialPlayerOn = false;
	}
	if (m_player->getPlayerChangeMode() && timePassedSpecialMode() <= 0)
	{
		m_player->setPlayerChangeMode(false);
		changePlayerModeToRegular();
	}
}
