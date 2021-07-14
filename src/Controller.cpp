#include "Controller.h"
//--------------------------------------------------------------------------------------------
// c-tor
Controller::Controller() :m_window({ WINDOW_WIDTH, WINDOW_HEIGHT },"The Avengers Game"), m_start(false), m_openMenu(m_window, m_start)

{
    m_window.setFramerateLimit(FRAME_LIMIT);
    m_window.setPosition({ 0,0 });
}


//--------------------------------------------------------------------------------------------
//הפונקציה שמנהלת את המשחקן
void Controller::run()
{
    bool isSucsses = true;
	try {
		m_openMenu.run();

		if (m_start)
		{
			GameManager game;
			isSucsses = game.run(m_window);
			gameResult(isSucsses);
		}
	}
	catch(...)
	{ }
 
}

//--------------------------------------------------------------------------------------------
// מטפלת בסיום משחק - נצחון / הפסד 
void Controller::gameResult(bool& isSucsses)
{

	m_viewGame = sf::View(sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));
	m_viewGame.setViewport({ 0.f, 0.f,1.f,1.f });
	m_window.setView(m_viewGame);
	if (!isSucsses)
	{
		
		m_window.clear();
		m_sprite.setTexture(ResourcesManage::instance().getImgScreen("gameOver"));
		m_sound.setBuffer(ResourcesManage::instance().getSound("gameOver"));
		m_sound.play();

	}
	else
	{
		m_window.clear();
		m_sprite.setTexture(ResourcesManage::instance().getImgScreen("win"));
		m_sound.setBuffer(ResourcesManage::instance().getSound("win"));
		m_sound.play();

	}
	m_window.draw(m_sprite);
	m_window.display();

	sf::Event event;
	m_window.waitEvent(event);


	run();
	return;
}


