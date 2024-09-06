#include "Brick.h"

Brick::Brick(const sf::Vector2f& size, const sf::Vector2f& position) {
    this->setFillColor(sf::Color::White);
    this->setSize(size);
    this->setOrigin(this->getSize().x / 2, this->getSize().y / 2);
    this->setPosition(position);
}
