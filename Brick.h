#pragma once

#include <SFML/Graphics.hpp>

class Brick : public sf::RectangleShape {
public:
    Brick(const sf::Vector2f& size, const sf::Vector2f& position);
};