#include "Paddle.h"

Paddle::Paddle(const float move_value, const float y_position, const float x_position, const sf::Vector2f& size,
    const sf::Keyboard::Key&& first_key, const sf::Keyboard::Key&& second_key) :
    move_value(move_value), y_position(y_position), x_position(x_position), first_key(first_key), second_key(second_key) {
    this->setFillColor(sf::Color::White);
    this->setSize(size);
    this->setOrigin(sf::Vector2f(this->getSize().x / 2.f, this->getSize().y / 2.f));
    this->setPosition(sf::Vector2f(x_position, y_position));
}

void Paddle::move(const unsigned int y_window) {
    if (sf::Keyboard::isKeyPressed(first_key) && y_position > this->getSize().y / 2.f) {
        y_position -= move_value;
        this->setPosition(sf::Vector2f(x_position, y_position));
    }
    if (sf::Keyboard::isKeyPressed(second_key) && y_position < static_cast<float>(y_window) - this->getSize().y / 2.f) {
        y_position += move_value;
        this->setPosition(sf::Vector2f(x_position, y_position));
    }
}
