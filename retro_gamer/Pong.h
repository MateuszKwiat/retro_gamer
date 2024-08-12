#pragma once

#include <SFML/Graphics.hpp>
#include <utility>

#include "Paddle.h"
#include "Net.h"
#include "Ball.h"

class Pong {
private:
	sf::RenderWindow* window;
	Paddle* player_one;
	Paddle* player_two;
	Net* net;
	Ball* ball;

public:
	Pong(const int x_window, const int y_window);
	~Pong();
	void run();
};

