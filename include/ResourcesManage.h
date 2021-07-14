#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <SFML/Audio.hpp>
#include "Utilities.h"
using std::unique_ptr;
class ResourcesManage
{
public:

	~ResourcesManage() = default;
	static ResourcesManage& instance();
	sf::Font* getFont();
	sf::Music* getMusic();
	sf::Texture& getImgBoard(std::string img);
	sf::Texture& getImgScreen(std::string img);
	sf::SoundBuffer& getSound(std::string sound);


private:
	ResourcesManage();
	ResourcesManage(const ResourcesManage&)=default;
	void insertImageBoardToMap();
	void insertImageScreenToMap();
	void insertSoundToMap();
	std::map<std::string, sf::Texture>m_imageBoard;
	std::map<std::string, sf::Texture> m_imageScreen;
	sf::Font m_font;
	sf::Music m_music_Background;
	std::map<std::string, sf::SoundBuffer> m_sound;

};

