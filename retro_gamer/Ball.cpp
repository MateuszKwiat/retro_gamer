#include "Ball.h"

Ball::Ball(float radius, float delta_value, sf::Vector2u&& window_size) : sf::CircleShape(radius), 
x_delta(delta_value), y_delta(delta_value) {
	this->setFillColor(sf::Color::White);
	this->setOrigin(sf::Vector2f(radius, radius));
	this->setPosition(sf::Vector2f(window_size.x / 2.f, window_size.y / 2.f));
}

void Ball::move() {
	this->setPosition(sf::Vector2f(this->getPosition().x + x_delta,
		this->getPosition().y + y_delta));
}

void Ball::collision(sf::Vector2u&& window_size) {
	if (this->getPosition().x - this->getRadius() < 0 ||
		this->getPosition().x + this->getRadius() > window_size.x) {
		x_delta *= -1;
	}
	if (this->getPosition().y - this->getRadius() < 0 || 
		this->getPosition().y + this->getRadius() > window_size.y) {
		y_delta *= -1;
	}
}