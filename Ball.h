#pragma once

#include <SFML/Graphics.hpp>

class Ball : public sf::CircleShape {
protected:
    float x_delta;
    float y_delta;

public:
    Ball(const float radius, const float delta_value, const sf::Vector2u& window_size);
    void move();
};