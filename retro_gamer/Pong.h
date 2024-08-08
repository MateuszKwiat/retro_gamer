#pragma once

#include <SFML/Graphics.hpp>

#include "Ball.h"

class Pong {
private:
	sf::RenderWindow* window;
	Ball* ball;

public:
	Pong(int x_window, int y_window);
	~Pong();
	void run();
};

