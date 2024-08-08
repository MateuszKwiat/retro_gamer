#include "Ball.h"

Ball::Ball(float radius, sf::Vector2u&& window_size) : sf::CircleShape(radius), x_delta(0.2f), y_delta(0.2f) {
	this->setFillColor(sf::Color::White);
	this->setOrigin(sf::Vector2f(radius, radius));
	this->setPosition(sf::Vector2f(window_size.x / 2.f, window_size.y / 2.f));
}

