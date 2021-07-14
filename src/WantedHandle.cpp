#include "WantedHandle.h"
#include "Level.h"
//--------------------------------------------------------------------------------------------
// c-tor
WantedHandle::WantedHandle(std::unique_ptr<Player>& pPlayer, Level& level):m_index(0), m_level(level)
{
	pPlayer->RegisterObserver(this);

}
//--------------------------------------------------------------------------------------------
// ����� ����
void WantedHandle::readFile(int levelNum)
{
	m_index = 0;
	m_vectorWanted.clear();
	string file = "WANTED" + std::to_string(levelNum) + ".txt";
	string str;
	m_fileWamted = ifstream(file);
	if (!m_fileWamted.is_open())
	{
		throw ExceptionFile();
	}
	while (!m_fileWamted.eof())
	{
		getline(m_fileWamted, str);
		m_vectorWanted.emplace_back(make_unique<Wanted>(str, sf::Vector2f(1100, 100)));
	}
	m_fileWamted.close();
	randomLocation();
}

//--------------------------------------------------------------------------------------------
// ���� ������
void WantedHandle::drawOnMenu(sf::RenderWindow& window)
{
	for (int i = 0; i < m_vectorWanted.size(); i++)
		if (i == m_index)
			m_vectorWanted[i]->drawOnWindow(window);

}

//--------------------------------------------------------------------------------------------
// ���� ������� ����
void WantedHandle::drawOnBoard(sf::RenderWindow& window)
{

	string str = m_vectorWanted[m_index]->getName();
	m_wantedObject=(make_unique<Wanted>(str, sf::Vector2f(m_x,m_y)));
	m_wantedObject->drawOnWindow(window);

}

//--------------------------------------------------------------------------------------------
// �����
void WantedHandle::Update()
{
	m_sound.setBuffer(ResourcesManage::instance().getSound("wanted"));
	m_sound.play();
	m_index++;
	randomLocation();
}

//--------------------------------------------------------------------------------------------
// ������� �� ���� �� ���
void WantedHandle::playerCollideWithWantedd(std::unique_ptr<Player>& player)
{
	if (player->getGlobalBoundsOfSprite().intersects(m_wantedObject->getGlobalBoundsOfSprite()))//  ����� �� �� ����� ��� ��� ���������
		processCollision(*player, *m_wantedObject);// ����� �������� �� ����� �������
}

//--------------------------------------------------------------------------------------------
// ����� �����
bool WantedHandle::checkLocation(sf::Vector2f location)
{
	return m_level.isEmpty(location);
}

//--------------------------------------------------------------------------------------------
// ����� �� ������
bool WantedHandle::endVector()
{
	return m_index>=m_vectorWanted.size();
}

//--------------------------------------------------------------------------------------------
// ����� ����� �������
void WantedHandle::randomLocation()
{
	m_x = rand() % (BOARD_GAME_WIDTH * 2);
	m_y = rand() % (WINDOW_HEIGHT*2);
	while (!m_level.isEmpty(sf::Vector2f(m_x, m_y)))
	{
		m_x = rand() % (BOARD_GAME_WIDTH * 2);
		m_y = rand() % (WINDOW_HEIGHT * 2);
	}
}
