#include "..\include\Exit.h"


Exit::Exit(sf::RenderWindow& window) :Command(window, { 1080, 500 }, "Exit")
{
}

void Exit::execute()
{
	exit(EXIT_SUCCESS);
}
