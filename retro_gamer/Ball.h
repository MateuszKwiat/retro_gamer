#pragma once

#include <SFML/Graphics.hpp>

class Ball : public sf::CircleShape {
private:
	float x_delta;
	float y_delta;

	bool paddleCollision(const bool player_one, const sf::Vector2f& player_size,
		const sf::Vector2f& player_position);
	bool wallCollision(const sf::Vector2u& window_size);

public:
	Ball(const float radius, const float delta_value, const sf::Vector2u&& window_size);
	void move();
	void collisions(const sf::Vector2u&& window_size, const sf::Vector2f& player_size,
		const sf::Vector2f& player_one_position, const sf::Vector2f& player_two_position);
};

