#include "PongBall.h"


PongBall::PongBall(const float radius, const float delta_value, const sf::Vector2u&& window_size) : Ball(radius, delta_value, window_size) {}

void PongBall::paddleCollision(const Paddle& player_one, const Paddle& player_two) {
    if (x_delta < 0) {
        if (this->getGlobalBounds().intersects(player_one.getGlobalBounds()))
            x_delta = -x_delta;
    }
    else {
        if (this->getGlobalBounds().intersects(player_two.getGlobalBounds()))
            x_delta = -x_delta;
    }
}

bool PongBall::wallCollision(const sf::Vector2u& window_size, Score& player_one_score, Score& player_two_score) {
    if (this->getPosition().x - this->getRadius() < 0 ||
        this->getPosition().x + this->getRadius() > static_cast<float>(window_size.x)) {
        this->setPosition(sf::Vector2f(static_cast<float>(window_size.x) / 2.f, static_cast<float>(window_size.y) / 2.f));
        x_delta < 0 ? player_two_score++ : player_one_score++;
        x_delta = -x_delta;
        }

    return (this->getPosition().y - this->getRadius() < 0 ||
        this->getPosition().y + this->getRadius() > static_cast<float>(window_size.y));
}

void PongBall::collisions(const sf::Vector2u&& window_size, const Paddle& player_one, const Paddle& player_two,
                Score& player_one_score, Score& player_two_score) {
        if (this->wallCollision(window_size, player_one_score, player_two_score)) {
            y_delta = -y_delta;
        }
        this->paddleCollision(player_one, player_two);
}