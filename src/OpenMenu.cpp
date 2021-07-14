#include "OpenMenu.h"

//--------------------------------------------------------------------------------------------
// c-tor
OpenMenu::OpenMenu(sf::RenderWindow& window, bool& start) : m_window(window)
{
	m_sprite.setTexture((ResourcesManage::instance().getImgScreen("openBackground")));
	m_sprite.setPosition({ 0,0 });
	m_buttons.emplace_back("Help",std::make_unique<Help>(m_window));
	m_buttons.emplace_back("Exit", std::make_unique<Exit>(m_window));
	m_buttons.emplace_back("New Game", std::make_unique<NewGame>(m_window, start));
}

//--------------------------------------------------------------------------------------------
// הפונקציה העיקרית שמנהלת את המסך פתיחה
void OpenMenu::run()
{

	draw();
	while (m_window.isOpen())
	{
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				m_window.close();
				exit(0);
			case sf::Event::MouseButtonPressed:
				sf::Vector2f vec;
				vec = m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
				for (size_t i = 0; i < m_buttons.size(); i++)
				{
					if (m_buttons[i].second->isContent(vec)) {
						m_buttons[i].second->execute();
						if (m_buttons[i].first == "New Game")
							return;
						break;

					}
				}
				break;
			}
		}
		m_window.clear();
		draw();
		m_window.display();
	}
}

//--------------------------------------------------------------------------------------------
// c-tor
void OpenMenu::draw()
{
	m_window.draw(m_sprite);
	for (auto& i : m_buttons)
		i.second->draw(m_window);
}