#include "Level.h"
#include <string>
#include <cmath>

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	if (!font.loadFromFile("font/msgothic.ttc")) {
		std::cout << "Error loading font.\n";
	}

	mPos.setFont(font);
	mPos.setCharacterSize(36);
	mPos.setFillColor(sf::Color::White);
	mPos.setOutlineColor(sf::Color::Blue);
	mPos.setOutlineThickness(2.f);

	circClick.setRadius(15);
	circClick.setFillColor(sf::Color::Cyan);
	circClick.setOutlineColor(sf::Color::Blue);
	circClick.setOutlineThickness(5.f);
}

Level::~Level()
{
	input = nullptr;
}

// handle user input
void Level::handleInput()
{
	std::string mousePos = std::to_string(input->getMouseX());
	mousePos += ", ";
	mousePos += std::to_string(input->getMouseY());

	mPos.setString(mousePos);

	if (input->isKeyDown(sf::Keyboard::W)) {
		input->setKeyUp(sf::Keyboard::W);
		std::cout << "W was pressed just now" << std::endl;
	}

	if (input->isKeyDown(sf::Keyboard::J) && input->isKeyDown(sf::Keyboard::K) && input->isKeyDown(sf::Keyboard::L)) {
		input->setKeyUp(sf::Keyboard::J);
		input->setKeyUp(sf::Keyboard::K);
		input->setKeyUp(sf::Keyboard::L);
		std::cout << "Who are you trying to impress with those three keys?" << std::endl;
	}

	if (input->isKeyDown(sf::Keyboard::Escape)) {
		exit(0);
	}

	if (input->isMouseLDown()) {
		if (!dragYes) {
			dragYes = true;
			initMousePos.x = input->getMouseX();
			initMousePos.y = input->getMouseY();
		}
		else {
			finalMousePos.x = input->getMouseX();
			finalMousePos.y = input->getMouseY();

			distance = sqrt(pow(finalMousePos.x - initMousePos.x, 2) + pow(finalMousePos.y - initMousePos.y, 2));
			std::cout << distance << std::endl;
		}
	}
	else {
		dragYes = false;
	}

	if (input->isMouseRDown()) {
		circClick.setPosition(input->getMouseX(),input->getMouseY());
	}

	//std::cout << "Mouse position currently at: " << input->getMouseX() << ", " << input->getMouseY() << std::endl;
}

// Update game objects
void Level::update()
{

}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(mPos);
	window->draw(circClick);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}