#pragma once

#include <SFML/Graphics.hpp>
#include <utility>

class Paddle : public sf::RectangleShape {
private:
	float move_value;
	float y_position;
	sf::Keyboard::Key up_key;
	sf::Keyboard::Key down_key;

public:
	Paddle(const float move_value,const float x_position, const sf::Vector2u&& window_size,
		const sf::Keyboard::Key&& up_key, const sf::Keyboard::Key&& down_key);
	void move(const unsigned int y_window);
};

