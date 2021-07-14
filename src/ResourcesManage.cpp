#include "ResourcesManage.h"
//--------------------------------------------------------------------------------------------
//c-tor
ResourcesManage::ResourcesManage()
{
	m_font.loadFromFile("C:/Windows/Fonts/Impact.ttf");
	insertImageBoardToMap();
	insertImageScreenToMap();
	insertSoundToMap();
	m_music_Background.openFromFile("GameMusic.wav");
}

//--------------------------------------------------------------------------------------------
//singleton
ResourcesManage& ResourcesManage::instance()
{
	static ResourcesManage inst;
	return inst;
}

void ResourcesManage::insertImageBoardToMap()
{
	auto image = sf::Texture();

	image.loadFromFile("empty.png");
	m_imageBoard.insert(std::make_pair("empty", image));

	image.loadFromFile("gift.png");
	m_imageBoard.insert(std::make_pair("gift", image));

	image.loadFromFile("wall.png");
	m_imageBoard.insert(std::make_pair("wall", image));

	image.loadFromFile("wall.png");
	m_imageBoard.insert(std::make_pair("floor", image));

	image.loadFromFile("player.png");
	m_imageBoard.insert(std::make_pair("regularPlayer", image));

	image.loadFromFile("playerSpecial.png");
	m_imageBoard.insert(std::make_pair("smartPlayer", image));

	image.loadFromFile("monster.png");
	m_imageBoard.insert(std::make_pair("monsterStupid", image));

	image.loadFromFile("monster.png");
	m_imageBoard.insert(std::make_pair("monsterSmart", image));

	image.loadFromFile("shoot2.png");
	m_imageBoard.insert(std::make_pair("ShootStupid", image));

	image.loadFromFile("ring.png");
	m_imageBoard.insert(std::make_pair("ShootSpecial", image));

	image.loadFromFile("playerProtected3.png");
	m_imageBoard.insert(std::make_pair("playerProtected", image));


	image.loadFromFile("walkieTalki.png");
	m_imageBoard.insert(std::make_pair("walkieTalki", image));

	image.loadFromFile("computer.png");
	m_imageBoard.insert(std::make_pair("computer", image));

	image.loadFromFile("person.png");
	m_imageBoard.insert(std::make_pair("person", image));

	image.loadFromFile("door.png");
	m_imageBoard.insert(std::make_pair("door", image));

	image.loadFromFile("clock.png");
	m_imageBoard.insert(std::make_pair("clock", image));

	image.loadFromFile("gun.png");
	m_imageBoard.insert(std::make_pair("gun", image));

	image.loadFromFile("key.png");
	m_imageBoard.insert(std::make_pair("key", image));

	image.loadFromFile("ball.jpg");
	m_imageBoard.insert(std::make_pair("ball", image));
}

void ResourcesManage::insertImageScreenToMap()
{
	auto image = sf::Texture();

	image.loadFromFile("openBackground.png");
	m_imageScreen.insert(std::make_pair("openBackground", image));

	image.loadFromFile("help1.png");
	m_imageScreen.insert(std::make_pair("help1", image));

	image.loadFromFile("help2.png");
	m_imageScreen.insert(std::make_pair("help2", image));

	image.loadFromFile("gameBackground.jpg");
	m_imageScreen.insert(std::make_pair("gameBackground", image));

	image.loadFromFile("menuBackground.png");
	m_imageScreen.insert(std::make_pair("menu", image));

	image.loadFromFile("button.jpg");
	m_imageScreen.insert(std::make_pair("button", image));

	image.loadFromFile("gameOver.png");
	m_imageScreen.insert(std::make_pair("gameOver", image));

	image.loadFromFile("win.png");
	m_imageScreen.insert(std::make_pair("win", image));
}

void ResourcesManage::insertSoundToMap()
{
	auto sound = sf::SoundBuffer();

	sound.loadFromFile("wantedSound.wav");
	m_sound.insert(std::make_pair("wanted", sound));

	sound.loadFromFile("clock.wav");
	m_sound.insert(std::make_pair("clock", sound));

	sound.loadFromFile("win.wav");
	m_sound.insert(std::make_pair("wanted", sound));

	sound.loadFromFile("gameOver.wav");
	m_sound.insert(std::make_pair("gameOver", sound));

	sound.loadFromFile("boom1.wav");
	m_sound.insert(std::make_pair("boom1", sound));

	sound.loadFromFile("boom2.wav");
	m_sound.insert(std::make_pair("boom2", sound));
}





//--------------------------------------------------------------------------------------------
//מחזיר פונט
sf::Font* ResourcesManage::getFont()
{
	return &m_font;
}

sf::Music* ResourcesManage::getMusic()
{
	 	return &m_music_Background;
}


sf::Texture& ResourcesManage::getImgBoard(std::string img)
{
	auto it = m_imageBoard.find(img);
	if (it == m_imageBoard.end())
		exit(1);
	return m_imageBoard.find(img)->second;
}

sf::Texture& ResourcesManage::getImgScreen(std::string img)
{
	auto it = m_imageScreen.find(img);
	if (it == m_imageScreen.end())
	{
		
		exit(1);
	}
	return m_imageScreen.find(img)->second;
}

sf::SoundBuffer& ResourcesManage::getSound(std::string sound)
{
	auto it = m_sound.find(sound);
	if (it == m_sound.end())
		exit(1);
	return m_sound.find(sound)->second;
}


