#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput();
	void update();
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	sf::CircleShape circClick;

	// Add your object here
	sf::Font font;
	sf::Text mPos;

	float distance;
	sf::Vector2f initMousePos;
	sf::Vector2f finalMousePos;
	bool dragYes = false;
};