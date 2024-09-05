#include "Ball.h"

Ball::Ball(const float radius, const float delta_value, const sf::Vector2u&& window_size)
    : sf::CircleShape(radius), x_delta(delta_value), y_delta(delta_value) {
    this->setFillColor(sf::Color::White);
    this->setOrigin(sf::Vector2f(radius, radius));
    this->setPosition(sf::Vector2f(static_cast<float>(window_size.x) / 2.f, static_cast<float>(window_size.y) / 2.f));
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

void Ball::paddleCollision(const Paddle &paddle) {
    if (y_delta > 0 && this->getGlobalBounds().intersects(paddle.getGlobalBounds())) {
        y_delta = -y_delta;
    }
}

bool Ball::wallCollision(const sf::Vector2u& window_size, Score& player_one_score, Score& player_two_score) {
    if (this->getPosition().x - this->getRadius() < 0 ||
        this->getPosition().x + this->getRadius() > static_cast<float>(window_size.x)) {
        this->setPosition(sf::Vector2f(static_cast<float>(window_size.x) / 2.f, static_cast<float>(window_size.y) / 2.f));
        x_delta < 0 ? player_two_score++ : player_one_score++;
        x_delta = -x_delta;
    }

    return (this->getPosition().y - this->getRadius() < 0 ||
        this->getPosition().y + this->getRadius() > static_cast<float>(window_size.y));
}

void Ball::wallCollision(const sf::Vector2u& window_size) {
    if (this->getPosition().x - this->getRadius() < 0 || this->getPosition().x + this->getRadius() > static_cast<float>(window_size.x)) {
        x_delta = -x_delta;
    }
    if (this->getPosition().y - this->getRadius() < 0 || this->getPosition().y + this->getRadius() > static_cast<float>(window_size.y)) {
        y_delta = -y_delta;
    }
}

void Ball::move() {
    this->setPosition(sf::Vector2f(this->getPosition().x + x_delta, this->getPosition().y + y_delta));
}

void Ball::collisions(const sf::Vector2u&& window_size, const Paddle& player_one, const Paddle& player_two,
    Score& player_one_score, Score& player_two_score) {
    if (this->wallCollision(window_size, player_one_score, player_two_score)) {
        y_delta = -y_delta;
    }
    this->paddleCollision(player_one, player_two);
}

void Ball::collisions(const sf::Vector2u& window_size, const Paddle& paddle) {
    this->wallCollision(window_size);
    this->paddleCollision(paddle);
}