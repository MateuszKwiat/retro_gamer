#include "Brick.h"

Brick::Brick(const sf::Vector2f& size) {
    in_game = true;
    this->setFillColor(sf::Color::White);
    this->setSize(size);
    this->setOrigin(this->getSize().x / 2, this->getSize().y / 2);
}
