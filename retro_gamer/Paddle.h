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
	Paddle(float move_value,float x_position, sf::Vector2u&& window_size,
		sf::Keyboard::Key&& up_key, sf::Keyboard::Key&& down_key);
	void move(unsigned int y_window);
};

