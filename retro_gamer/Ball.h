#pragma once

#include <SFML/Graphics.hpp>

class Ball : public sf::CircleShape {
private:
	float x_delta;
	float y_delta;

public:
	Ball(float radius, float delta_value, sf::Vector2u&& window_size);
	void move();
	void collision(sf::Vector2u&& window_size);
};

