#pragma once

#include <SFML/Graphics.hpp>

class Ball : public sf::CircleShape {
private:
	float x_delta;
	float y_delta;

public:
	Ball(float radius, sf::Vector2u&& window_size);
};

