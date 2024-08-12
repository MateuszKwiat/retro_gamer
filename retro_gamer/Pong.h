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
	Paddle* player_two;

public:
	Pong(const int x_window, const int y_window);
	~Pong();
	void run();
};

