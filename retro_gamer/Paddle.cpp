#include "Paddle.h"

Paddle::Paddle(float move_value, float x_position, sf::Vector2u&& window_size, 
	sf::Keyboard::Key&& up_key, sf::Keyboard::Key&& down_key) : 
	move_value(move_value), up_key(up_key), down_key(down_key) {
	this->setFillColor(sf::Color::White);
	this->setSize(sf::Vector2f(window_size.x / 60.f, window_size.y / 6.f));
	this->setOrigin(sf::Vector2f(this->getSize().x / 2.f, this->getSize().y / 2.f));
	this->setPosition(sf::Vector2f(x_position, window_size.y / 2.f));
	y_position = this->getPosition().y;
}

void Paddle::move(unsigned int y_window) {
	if (sf::Keyboard::isKeyPressed(up_key) && y_position > 0) {
		y_position -= move_value;
		this->setPosition(sf::Vector2f(this->getPosition().x, y_position));
	}
	if (sf::Keyboard::isKeyPressed(down_key) && y_position < y_window) {
		y_position += move_value;
		this->setPosition(sf::Vector2f(this->getPosition().x, y_position));
	}
}

/*
if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && yPosition > 0) {
		yPosition -= moveValue;
		sprite->setPosition(xPosition, yPosition);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && yPosition < yWindow - sprite->getSize().y) {
		yPosition += moveValue;
		sprite->setPosition(xPosition, yPosition);
	}
*/
