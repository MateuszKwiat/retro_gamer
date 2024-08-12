#pragma once

#include <SFML/Graphics.hpp>
#include <utility>

#include "Ball.h"
#include "Paddle.h"

class Pong {
private:
	sf::RenderWindow* window;
	Ball* ball;
	Paddle* player_one;

public:
	Pong(int x_window, int y_window);
	~Pong();
	void run();
};

