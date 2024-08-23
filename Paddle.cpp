#include "Paddle.h"

Paddle::Paddle(const float move_value, const float x_position, const sf::Vector2u&& window_size,
    const sf::Keyboard::Key&& up_key, const sf::Keyboard::Key&& down_key) :
    move_value(move_value), up_key(up_key), down_key(down_key) {
    this->setFillColor(sf::Color::White);
    this->setSize(sf::Vector2f(static_cast<float>(window_size.x) / 60.f, static_cast<float>(window_size.y) / 6.f));
    this->setOrigin(sf::Vector2f(this->getSize().x / 2.f, this->getSize().y / 2.f));
    this->setPosition(sf::Vector2f(x_position, static_cast<float>(window_size.y) / 2.f));
    y_position = this->getPosition().y;
}

void Paddle::move(const unsigned int y_window) {
    if (sf::Keyboard::isKeyPressed(up_key) && y_position > this->getSize().y / 2.f) {
        y_position -= move_value;
        this->setPosition(sf::Vector2f(this->getPosition().x, y_position));
    }
    if (sf::Keyboard::isKeyPressed(down_key) && y_position < static_cast<float>(y_window) - this->getSize().y / 2.f) {
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