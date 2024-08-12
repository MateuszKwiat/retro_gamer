#include "Ball.h"

Ball::Ball(const float radius, const float delta_value, const sf::Vector2u&& window_size) 
	: sf::CircleShape(radius), x_delta(delta_value), y_delta(delta_value) {
	this->setFillColor(sf::Color::White);
	this->setOrigin(sf::Vector2f(radius, radius));
	this->setPosition(sf::Vector2f(window_size.x / 2.f, window_size.y / 2.f));
}

bool Ball::paddleCollision(const bool player_one, const sf::Vector2f& player_size,
	const sf::Vector2f& player_position) {
	if (player_one) {
		return (this->getPosition().x - this->getRadius() <= player_position.x + (player_size.x / 2.f)
			&& this->getPosition().y >= player_position.y - (player_size.y / 2.f)
			&& this->getPosition().y <= player_position.y + (player_size.y / 2.f));
	}
	else {
		return (this->getPosition().x + this->getRadius() >= player_position.x - (player_size.x / 2.f)
			&& this->getPosition().y >= player_position.y - (player_size.y / 2.f)
			&& this->getPosition().y <= player_position.y + (player_size.y / 2.f));
	}
}

bool Ball::wallCollision(const sf::Vector2u& window_size) {
	if (this->getPosition().x - this->getRadius() < 0 ||
		this->getPosition().x + this->getRadius() > window_size.x) {
		this->setPosition(sf::Vector2f(window_size.x / 2.f, window_size.y / 2.f));
		x_delta *= -1;
	}

	return (this->getPosition().y - this->getRadius() < 0 ||
		this->getPosition().y + this->getRadius() > window_size.y);
}

void Ball::move() {
	this->setPosition(sf::Vector2f(this->getPosition().x + x_delta,
		this->getPosition().y + y_delta));
}

void Ball::collisions(const sf::Vector2u&& window_size, const sf::Vector2f& player_size,
	const sf::Vector2f& player_one_position, const sf::Vector2f& player_two_position) {
	if (this->wallCollision(window_size)) {
		y_delta *= -1;
	}
	if (this->paddleCollision(true, player_size, player_one_position) 
		|| this->paddleCollision(false, player_size, player_two_position)) {
		x_delta *= -1;
	}
}