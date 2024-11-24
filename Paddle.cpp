#include "Paddle.h"

Paddle::Paddle(const float move_value,
                const sf::Vector2f& position,
                const sf::Vector2f& size,
                const sf::Keyboard::Key&& first_key,
                const sf::Keyboard::Key&& second_key) :
                        move_value(move_value),
                        position(position),
                        first_key(first_key),
                        second_key(second_key) {
    this->setFillColor(sf::Color::White);
    this->setSize(size);
    this->setOrigin(sf::Vector2f(this->getSize().x / 2.f, this->getSize().y / 2.f));
    this->setPosition(sf::Vector2f(position.x, position.y));
}

void Paddle::moveVertically(const unsigned int y_window) {
    if (sf::Keyboard::isKeyPressed(first_key) && position.y > this->getSize().y / 2.f) {
        position.y -= move_value;
        this->setPosition(sf::Vector2f(position.x, position.y));
    }
    if (sf::Keyboard::isKeyPressed(second_key) && position.y < static_cast<float>(y_window) - this->getSize().y / 2.f) {
        position.y += move_value;
        this->setPosition(sf::Vector2f(position.x, position.y));
    }
}

void Paddle::moveHorizontally(const unsigned int x_window) {
    if (sf::Keyboard::isKeyPressed(first_key) && position.x > this->getSize().x / 2.f) {
        position.x -= move_value;
        this->setPosition(sf::Vector2f(position.x, position.y));
    }
    if (sf::Keyboard::isKeyPressed(second_key) && position.x < static_cast<float>(x_window) - this->getSize().x / 2.f) {
        position.x += move_value;
        this->setPosition(sf::Vector2f(position.x, position.y));
    }
}

void Paddle::resetHorizontally(const unsigned int x_window) {
    position.x = static_cast<float>(x_window) / 2.f;
    this->setPosition(sf::Vector2f(position.x, position.y));
}
