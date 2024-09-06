#include "BreakoutBall.h"

BreakoutBall::BreakoutBall(const float radius, const float delta_value, const sf::Vector2u& window_size) :
    Ball(radius, delta_value, window_size) {}

void BreakoutBall::paddleCollision(const Paddle& paddle) {
    if (y_delta > 0 && this->getGlobalBounds().intersects(paddle.getGlobalBounds())) {
        y_delta = -y_delta;
    }
}

void BreakoutBall::wallCollision(const sf::Vector2u &window_size) {
    if (this->getPosition().x - this->getRadius() < 0 || this->getPosition().x + this->getRadius() > static_cast<float>(window_size.x)) {
        x_delta = -x_delta;
    }
    if (this->getPosition().y - this->getRadius() < 0 || this->getPosition().y + this->getRadius() > static_cast<float>(window_size.y)) {
        y_delta = -y_delta;
    }
}

void BreakoutBall::brickCollision(Brick& brick) {
    if (this->getGlobalBounds().intersects(brick.getGlobalBounds())) {
        brick.setInGame(false);
        if (this->getPosition().y > brick.getPosition().y - (brick.getSize().y / 2.f)
            && this->getPosition().y < brick.getPosition().y + (brick.getSize().y / 2.f)) {
            x_delta = -x_delta;
        }
        else if (y_delta < 0) {
            y_delta = -y_delta;
        }
    }
}

void BreakoutBall::collisions(const sf::Vector2u &window_size, const Paddle &paddle) {
    this->wallCollision(window_size);
    this->paddleCollision(paddle);
}
