#pragma once

#include <SFML/Graphics.hpp>

class Brick final : public sf::RectangleShape {
public:
    Brick(const sf::Vector2f& size);
};