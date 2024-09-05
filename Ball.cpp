#include "Ball.h"

Ball::Ball(const float radius, const float delta_value, const sf::Vector2u& window_size)
    : sf::CircleShape(radius), x_delta(delta_value), y_delta(delta_value) {
    this->setFillColor(sf::Color::White);
    this->setOrigin(sf::Vector2f(radius, radius));
    this->setPosition(sf::Vector2f(static_cast<float>(window_size.x) / 2.f, static_cast<float>(window_size.y) / 2.f));
}

void Ball::move() {
    this->setPosition(sf::Vector2f(this->getPosition().x + x_delta, this->getPosition().y + y_delta));
}