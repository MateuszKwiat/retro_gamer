#pragma once

#include <SFML/Graphics.hpp>

class Pong {
private:
	sf::RenderWindow* window;

public:
	Pong();
	~Pong();
	void run();
};

