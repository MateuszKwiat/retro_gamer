#include "Ball.h"

Ball::Ball(const float radius, const float delta_value, const sf::Vector2u&& window_size)
    : sf::CircleShape(radius), x_delta(delta_value), y_delta(delta_value) {
    this->setFillColor(sf::Color::White);
    this->setOrigin(sf::Vector2f(radius, radius));
    this->setPosition(sf::Vector2f(window_size.x / 2.f, window_size.y / 2.f));
}

void Ball::paddleCollision(const Paddle& player_one, const Paddle& player_two) {
    if (x_delta < 0) {
        if (this->getGlobalBounds().intersects(player_one.getGlobalBounds()))
            x_delta = -x_delta;
    }
    else {
        if (this->getGlobalBounds().intersects(player_two.getGlobalBounds()))
            x_delta = -x_delta;
    }
}

bool Ball::wallCollision(const sf::Vector2u& window_size) {
    if (this->getPosition().x - this->getRadius() < 0 ||
        this->getPosition().x + this->getRadius() > window_size.x) {
        this->setPosition(sf::Vector2f(window_size.x / 2.f, window_size.y / 2.f));
        x_delta = -x_delta;
        }

    return (this->getPosition().y - this->getRadius() < 0 ||
        this->getPosition().y + this->getRadius() > window_size.y);
}

void Ball::move() {
    this->setPosition(sf::Vector2f(this->getPosition().x + x_delta,
        this->getPosition().y + y_delta));
}

void Ball::collisions(const sf::Vector2u&& window_size,
    const Paddle& player_one, const Paddle& player_two) {
    if (this->wallCollision(window_size)) {
        y_delta = -y_delta;
    }
    this->paddleCollision(player_one, player_two);
}