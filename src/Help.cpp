#include "Help.h"
#include <iostream>

//--------------------------------------------------------------------------------------------
// c-tor
Help::Help(sf::RenderWindow& window) :Command(window, { 1080, 300 },"Help"),m_index(1)
{
}


//--------------------------------------------------------------------------------------------
// פונקציה פנימית 
void Help::execute()
{
	sf::RenderWindow helpWindow({ WINDOW_WIDTH_HELP,WINDOW_HEIGHT_HELP }, "Help");
    while (helpWindow.isOpen()) {
        
        helpWindow.clear();
        drawOnWindow(helpWindow);
        helpWindow.display();
        checkEvent(helpWindow);
        if (m_index > NUM_OF_SCREEN_HELP)
            return;
    }
}


//--------------------------------------------------------------------------------------------
// c-tor
void Help::checkEvent(sf::RenderWindow& helpWindow)
{
    sf::RectangleShape rec(RECTANGLE_HELP_SIZE);
    rec.setPosition(RECTANGLE_HELP_POSITION);
    sf::Event event;
    while (helpWindow.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            helpWindow.close();
            return;

        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape)
            {
                helpWindow.close();
                return;
            }
        case sf::Event::MouseButtonPressed:
            sf::Vector2f vec = helpWindow.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
            if (rec.getGlobalBounds().contains(vec))
                m_index++;
            break;


        }
    }
}


//--------------------------------------------------------------------------------------------
// c-tor
void Help::drawOnWindow(sf::RenderWindow& helpWindow)
{
    m_spriteHelp.setTexture((ResourcesManage::instance().getImgScreen("help"+std::to_string(m_index))));
    helpWindow.draw(m_spriteHelp);

}
